#pragma once

#ifdef VDE_PLATFORM_WINDOWS
	#if VDE_DYNAMIC_LINK
		#ifdef VDE_BUILD_DLL
			#define VITDRAGONENGINE_API	__declspec(dllexport)
		#else
			#define VITDRAGONENGINE_API __declspec(dllimport)
		#endif
	#else
		#define VITDRAGONENGINE_API
	#endif
#else
	#error VitDragonEngine only support Windows
#endif

#ifdef VDE_ENABLE_ASSERTS
	#define VDE_ASSERT(x, ...){ if(!(x)){ VDE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define VDE_CORE_ASSERT(x, ...){ if(!(x)){ VDE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define VDE_ASSERT(x, ...)
	#define VDE_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)

#define VDE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)