#pragma once

#ifdef WH_PLATFORM_WINDOWS
	#if WH_DYNAMIC_LINK
		#ifdef WH_BUILD_DLL
			#define WH_API __declspec(dllexport)
		#else
			#define	WH_API __declspec(dllimport)
		#endif
	#else
		#define WH_API
	#endif
#else
	#error Wolf_Hazel only supports Windows!
#endif


