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

#ifdef WH_DEBUG
	#define WH_ENABLE_ASSERTS
#endif

#ifdef WH_ENABLE_ASSERTS
	#define WH_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define WH_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define WH_ASSERT(x, ...)
	#define WH_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define WH_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)