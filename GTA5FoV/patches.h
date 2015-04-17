#pragma once

char patchTemplate[] =
{
	0x49, 0xBB,										// mov r11,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,	// (callback address)
	0x41, 0xFF, 0xE3								// jmp r11
};

typedef struct patch_parameter_t
{
	char *name;
	char *iniSection;
	char *iniName;
	size_t offset;
	size_t length;
} patch_parameter_t;

typedef struct patch_t
{
	char *name;
	char *signature;			// bytes to search for
	size_t signatureLength;
	size_t jumpOffset;			// number of bytes after the first byte of signature to place the jump
	size_t nopCount;			// how many nops to add after jump
	char *code;					// code to inject
	size_t codeLength;
	size_t jumpBackAddrOffset;	// number of bytes after the first byte of code to place the return jump address
	patch_parameter_t *parameters;
	size_t paramCount;
} patch_t;



char firstPersonWalkingSignature[] =
{
	0xF3, 0x44, 0x0F, 0x11, 0x4D, 0x00, 0x8B, 0x86, 0xB0, 0x13, 0x00, 0x00, 0xC1, 0xE8, 0x1E
};
char firstPersonWalkingCode[] =
{
	0xC7, 0x45, 0x00,								// mov [rbp+00],
	0x00, 0x00, 0x88, 0x42,							// (fov - default 68)
	0x8B, 0x86, 0xB0, 0x13, 0x00, 0x00,				// mov eax,[rsi+000013B0] (copied over)
	0xC1, 0xE8, 0x1E,								// shr eax, 1E (copied over)
	0x49, 0xBB,										// mov r11, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,	// (return jump address)
	0x41, 0xFF, 0xE3								// jmp r11
};
patch_parameter_t firstPersonWalkingFovParams[] =
{
	{
		"fov",
		"FirstPerson",
		"Walking",
		3,
		4
	}
};

char firstPersonCarSignature[] =
{
	0x48, 0x8B, 0xCB, 0xF3, 0x0F, 0x11, 0x83, 0x90, 0x00, 0x00, 0x00, 0x48, 0x83, 0xC4, 0x20, 0x5B
};
char firstPersonCarCode[] =
{
	0xC7, 0x83, 0x90, 0x00, 0x00, 0x00,							// mov [rbp+00],
	0x00, 0x00, 0x88, 0x42,										// (fov - default 68)
	0x48, 0x83, 0xC4, 0x20,										// add rsp, 20 (copied over)
	0x5B,														// pop rbx (copied over)
	0x49, 0xBB,													// mov r11, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,				// (return jump address)
	0x41, 0xFF, 0xE3											// jmp r11
};
patch_parameter_t firstPersonCarFovParams[] =
{
	{
		"fov",
		"FirstPerson",
		"Car",
		6,
		4
	}
};

patch_t fovPatches[] =
{
	{
		"firstpersonwalking",
		firstPersonWalkingSignature,
		15,
		0,
		2,
		firstPersonWalkingCode,
		29,
		18,
		firstPersonWalkingFovParams,
		1
	},
	{
		"firstpersoncar",
		firstPersonCarSignature,
		16,
		3,
		0,
		firstPersonCarCode,
		28,
		17,
		firstPersonCarFovParams,
		1
	}
};
size_t fovPatchCount = 2;