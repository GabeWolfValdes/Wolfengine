#pragma once

#ifdef WF_PLATFORM_WINDOWS
#if WF_DYNAMIC_LINK
	#ifdef WF_BUILD_DLL
		#define WOLFEN_API __declspec(dllexport)
	#else
		#define WOLFEN_API __declspec(dllimport)
	#endif // WF_BUILD_DLL
#else 
	#define WOLFEN_API
#endif //WF_DYNAMIC_LINK
#else 
	#error Wolfen only supports Windows!
#endif // WF_PLATFORM_WINDOWS


#ifdef WF_DEBUG
	#define WF_ENABLE_ASSERTS
#endif

#ifdef WF_ENABLE_ASSERTS
	#define WF_ASSERT(x, ...) { if(!(x)) { WF_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define WF_CORE_ASSERT(x, ...) { if(!(x)) { WF_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define WF_ASSERT(x, ...)
	#define WF_CORE_ASSERT(x, ...)
#endif

// for setting flags
#define BIT(x) (1 << x) 

// for event system
#define HZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
