#pragma once

#ifdef WF_PLATFORM_WINDOWS
	#ifdef WF_BUILD_DLL
		#define WOLFEN_API _declspec(dllexport)
	#else
		#define WOLFEN_API _declspec(dllimport)
	#endif
#else 
	#error Wolfen only supports Windows!
#endif //
