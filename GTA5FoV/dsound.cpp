#include <windows.h>
#include <stdio.h>
#include "GTA5FoV.h"

HINSTANCE mHinst = 0, mHinstDLL = 0;
extern "C" UINT_PTR mProcs[12] = {0};

LPCSTR mImportNames[] = {"DirectSoundCaptureCreate", "DirectSoundCaptureCreate8", "DirectSoundCaptureEnumerateA", "DirectSoundCaptureEnumerateW", "DirectSoundCreate", "DirectSoundCreate8", "DirectSoundEnumerateA", "DirectSoundEnumerateW", "DirectSoundFullDuplexCreate", "DllCanUnloadNow", "DllGetClassObject", "GetDeviceID"};
BOOL WINAPI DllMain( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved ) {
	mHinst = hinstDLL;
	if ( fdwReason == DLL_PROCESS_ATTACH ) {
		TCHAR expandedPath[MAX_PATH];
		ExpandEnvironmentStrings("%WINDIR%\\System32\\dsound.dll", expandedPath, MAX_PATH);
		char chainPath[MAX_PATH];
		GetPrivateProfileString("General", "ProxyLibrary", expandedPath, chainPath, MAX_PATH, ".\\fov.ini");
		mHinstDLL = LoadLibrary(chainPath);
		if ( !mHinstDLL )
			return ( FALSE );
		for ( int i = 0; i < 12; i++ )
			mProcs[ i ] = (UINT_PTR)GetProcAddress( mHinstDLL, mImportNames[ i ] );

		CreateThread(NULL, 0, fovfix, NULL, 0, NULL);
	} else if ( fdwReason == DLL_PROCESS_DETACH ) {
		FreeLibrary( mHinstDLL );
	}
	return ( TRUE );
}

extern "C" void DirectSoundCaptureCreate_wrapper();
extern "C" void DirectSoundCaptureCreate8_wrapper();
extern "C" void DirectSoundCaptureEnumerateA_wrapper();
extern "C" void DirectSoundCaptureEnumerateW_wrapper();
extern "C" void DirectSoundCreate_wrapper();
extern "C" void DirectSoundCreate8_wrapper();
extern "C" void DirectSoundEnumerateA_wrapper();
extern "C" void DirectSoundEnumerateW_wrapper();
extern "C" void DirectSoundFullDuplexCreate_wrapper();
extern "C" void DllCanUnloadNow_wrapper();
extern "C" void DllGetClassObject_wrapper();
extern "C" void GetDeviceID_wrapper();
