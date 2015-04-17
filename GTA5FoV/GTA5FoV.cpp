#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <Windows.h>
#include <Psapi.h>

#include "patches.h"

#define LOG(msg, ...) if (haveLog) { fprintf(logfile, msg, __VA_ARGS__); fflush(logfile); }

FILE *logfile;
BOOL haveLog;

char *applyPatch(patch_t *patch, const char *modOffset)
{
	LOG("Applying patch: %s\r\n", patch->name);
	char *patchLoc, *codeLoc, *patchTemp = NULL;
	DWORD oldProtect;

	for (size_t i = (size_t)modOffset; i < UINT64_MAX; i++)
	{
		for (size_t j = 0; j < patch->signatureLength; j++)
		{
			if (patch->signature[j] != *(char*)(i + j))
				break;

			if (j == patch->signatureLength - 1)
			{
				patchLoc = (char *)i;
				goto endloops;
			}
		}
	}

endloops:
	LOG("Signature search complete\r\n");
	if (patchLoc == NULL)
	{
		LOG("Patch failed\r\n");
		return NULL;
	}
	LOG("Signature found at %llx\r\n", patchLoc);

	codeLoc = (char *)malloc(patch->codeLength);
	VirtualProtect(codeLoc, patch->codeLength, PAGE_EXECUTE_READWRITE, &oldProtect);
	memcpy(codeLoc, patch->code, patch->codeLength);
	// jump is 13 bytes, return after jump and nops
	char *afterPatchLoc = patchLoc + patch->jumpOffset + 13 + patch->nopCount;
	memcpy(codeLoc + patch->jumpBackAddrOffset, &afterPatchLoc, 8);
	LOG("Code written\r\n");

	patchTemp = (char *)malloc(13 + patch->nopCount);
	memcpy(patchTemp, patchTemplate, 13);
	memcpy(patchTemp + 2, &codeLoc, 8);
	for (size_t i = 0; i < patch->nopCount; i++)
	{
		*(char*)(patchTemp + 13 + i) = 0x90;
	}

	VirtualProtect(patchLoc + patch->jumpOffset, 13 + patch->nopCount, PAGE_EXECUTE_READWRITE, &oldProtect);
	LOG("Game code made RWX\r\n");
	memcpy(patchLoc + patch->jumpOffset, patchTemp, 13 + patch->nopCount);
	LOG("Game code patched\r\n");
	VirtualProtect(patchLoc + patch->jumpOffset, 13 + patch->nopCount, oldProtect, &oldProtect);
	LOG("Game code memory protection restored\r\n");

	free(patchTemp);

	return codeLoc;
}

patch_parameter_t *findPatchParameter(patch_t *patch, const char *name)
{
	for (size_t i = 0; i < patch->paramCount; i++)
	{
		if (strcmp(patch->parameters[i].name, name) == 0)
			return &patch->parameters[i];
		break;
	}

	return NULL;
}

bool setPatchParameter(patch_t *patch, char *location, const char *paramName, const char *paramValue)
{
	LOG("Setting parameter %s on patch %s\r\n", paramName, patch->name);

	patch_parameter_t *param = findPatchParameter(patch, paramName);

	if (param == NULL)
	{
		LOG("No such parameter\r\n");
		return false;
	}

	memcpy(location + param->offset, paramValue, param->length);

	LOG("Parameter set\r\n");
	return true;
}

bool iniReadFloat(const char *section, const char *name, float default, float *out)
{
	char buffer[100], defaultStr[100];
	_snprintf_s(defaultStr, 100, "%f", default);
	GetPrivateProfileString(section, name, defaultStr, buffer, 100, ".\\fov.ini");
	*out = strtof(buffer, NULL);
	return (*out != HUGE_VALF && *out != -HUGE_VALF);
}

DWORD WINAPI fovfix(LPVOID lpParameter)
{
	Sleep(30 * 1000);

	if (fopen_s(&logfile, "fov-log.txt", "w") == EINVAL || logfile == NULL) haveLog = false;
	else haveLog = true;
	LOG("Logging initialised\r\n");

	MODULEINFO modinfo;
	HMODULE hModule = GetModuleHandle("GTA5.exe");
	if (hModule == 0) goto err;
	LOG("Module handle found\r\n");
	GetModuleInformation(GetCurrentProcess(), hModule, &modinfo, sizeof(MODULEINFO));
	char *modOffset = (char *)(modinfo.lpBaseOfDll);
	LOG("lpBaseOfDll: %llx\r\n", modinfo.lpBaseOfDll);

	float fov;
	char *codeLoc;

	for (size_t i = 0; i < fovPatchCount; i++)
	{
		patch_parameter_t *param = findPatchParameter(&fovPatches[i], "fov");
		if (!param)
		{
			LOG("No FoV parameter on FoV patch %s (???)\r\n", fovPatches[i].name);
			goto err;
		}

		if (!iniReadFloat(param->iniSection, param->iniName, 68, &fov)) goto err;
		LOG("Target %s FoV is %f\r\n", fovPatches[i].name, fov);

		codeLoc = applyPatch(&fovPatches[0], (char*)modOffset);
		if (codeLoc == NULL) goto err;
		if (!setPatchParameter(&fovPatches[0], codeLoc, "fov", (char*)&fov)) goto err;
	}

	goto exit;

err:
	MessageBoxA(NULL, "FOV Fix has encountered an issue", NULL, MB_OK | MB_ICONWARNING);
exit:
	if (logfile) fclose(logfile);
	return 0;
}
