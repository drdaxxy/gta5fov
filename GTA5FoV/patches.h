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
patch_t firstPersonWalkingPatch =
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
};

char firstPersonCarSignature[] =
{
	0x48, 0x8B, 0xCB, 0xF3, 0x0F, 0x11, 0x83, 0x90, 0x00, 0x00, 0x00, 0x48, 0x83, 0xC4, 0x20, 0x5B
};
char firstPersonCarCode[] =
{
	0xC7, 0x83, 0x90, 0x00, 0x00, 0x00,							// mov [rbx+00000090], 
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
patch_t firstPersonCarPatch =
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
};

char firstPersonAimingSignature[] =
{
	0xF3, 0x0F, 0x59, 0xC6, 0xF3, 0x0F, 0x58, 0xC1, 0xF3, 0x0F, 0x11, 0x83, 0x74, 0x05, 0x00, 0x00
};
char firstPersonAimingCode[] =
{
	0xC7, 0x83, 0x74, 0x05, 0x00, 0x00,				// mov [rbx+00000574], 
	0x00, 0x00, 0x88, 0x42,							// (fov - default 68)
	0x49, 0xBB,										// mov r11, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,	// (return jump address)
	0x41, 0xFF, 0xE3								// jmp r11
};
patch_parameter_t firstPersonAimingFovParams[] =
{
	{
		"fov",
		"FirstPerson",
		"Aiming",
		6,
		4
	}
};
patch_t firstPersonAimingPatch =
{
	"firstpersonaiming",
	firstPersonAimingSignature,
	16,
	0,
	3,
	firstPersonAimingCode,
	23,
	12,
	firstPersonAimingFovParams,
	1
};

char firstPersonCrouchingSignature[] =
{
	0x80, 0xA3, 0x3E, 0x07, 0x00, 0x00, 0xFB, 0x40, 0xB5, 0xF7, 0x40, 0x20, 0xAB, 0x44, 0x07, 0x00, 0x00
};
char firstPersonCrouchingCode[] =
{
	0xC7, 0x45, 0x00,								// mov [rbp+00],
	0x00, 0x00, 0x88, 0x42,							// (fov - default 68)
	0x80, 0xA3, 0x3E, 0x07, 0x00, 0x00, 0xFB,		// and byte ptr [rbx+0000073E],-05 (copied over)
	0x40, 0xB5, 0xF7,								// mov bpl,-09 (copied over)
	0x40, 0x20, 0xAB, 0x44, 0x07, 0x00, 0x00,		// and [rbx+00000744],bpl (copied over)
	0x49, 0xBB,										// mov r11, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,	// (return jump address)
	0x41, 0xFF, 0xE3								// jmp r11
};
patch_parameter_t firstPersonCrouchingFovParams[] =
{
	{
		"fov",
		"FirstPerson",
		"Crouching",
		3,
		4
	}
};
patch_t firstPersonCrouchingPatch =
{
	"firstpersoncrouching",
	firstPersonCrouchingSignature,
	17,
	0,
	4,
	firstPersonCrouchingCode,
	37,
	26,
	firstPersonCrouchingFovParams,
	1
};

char firstPersonADSSignature[] =
{
	0x8A, 0x83, 0x49, 0x07, 0x00, 0x00, 0xF3, 0x0F, 0x11, 0x83, 0x74, 0x05, 0x00, 0x00, 0xA8, 0x02
};
char firstPersonADSCode[] =
{
	0xC7, 0x83, 0x74, 0x05, 0x00, 0x00,				// mov [rbx+00000574], 
	0x00, 0x00, 0x88, 0x42,							// (fov - default 68)
	0x8A, 0x83, 0x49, 0x07, 0x00, 0x00,				// mov al,[rbx+00000749] (copied over)
	0x49, 0xBB,										// mov r11, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,	// (return jump address)
	0x41, 0xFF, 0xE3								// jmp r11
};
patch_parameter_t firstPersonADSFovParams[] =
{
	{
		"fov",
		"FirstPerson",
		"ADS",
		6,
		4
	}
};
patch_t firstPersonADSPatch =
{
	"firstpersonads",
	firstPersonADSSignature,
	16,
	0,
	1,
	firstPersonADSCode,
	29,
	18,
	firstPersonADSFovParams,
	1
};


patch_t fovPatches[] =
{
	firstPersonWalkingPatch,
	firstPersonCarPatch,
	firstPersonAimingPatch,
	firstPersonCrouchingPatch,
	firstPersonADSPatch
};
size_t fovPatchCount = 5;