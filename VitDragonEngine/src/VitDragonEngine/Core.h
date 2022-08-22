#pragma once

#ifdef VDE_PLATFORM_WINDOWS
	#ifdef VDE_BUILD_DLL
		#define VITDRAGONENGINE_API	__declspec(dllexport)
	#else
		#define VITDRAGONENGINE_API __declspec(dllimport)
	#endif
#else
	#error VitDragonEngine only support Windows
#endif