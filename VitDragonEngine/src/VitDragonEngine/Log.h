#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace VitDragonEngine{

	class VITDRAGONENGINE_API Log{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger> &GetCoreLogger(){ return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger> &GetClientLogger(){ return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define VDE_CORE_TRACE(...)		::VitDragonEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VDE_CORE_INFO(...)		::VitDragonEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VDE_CORE_WARN(...)		::VitDragonEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VDE_CORE_ERROR(...)		::VitDragonEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VDE_CORE_FATAL(...)		::VitDragonEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define VDE_TRACE(...)		::VitDragonEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VDE_INFO(...)		::VitDragonEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define VDE_WARN(...)		::VitDragonEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VDE_ERROR(...)		::VitDragonEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define VDE_FATAL(...)		::VitDragonEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)

// if dist build
#define VDE_CORE_INFO
