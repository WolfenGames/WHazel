#pragma once

#include <memory>

#include "spdlog/spdlog.h"
#include "Core.h"

namespace Wolf_Hazel {

	class WH_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

#define WH_CORE_TRACE(...)	::Wolf_Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define WH_CORE_INFO(...)	::Wolf_Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define WH_CORE_WARN(...)	::Wolf_Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define WH_CORE_ERROR(...)	::Wolf_Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define WH_CORE_FATAL(...)	::Wolf_Hazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)


#define WH_TRACE(...)	::Wolf_Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define WH_INFO(...)	::Wolf_Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define WH_WARN(...)	::Wolf_Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define WH_ERROR(...)	::Wolf_Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define WH_FATAL(...)	::Wolf_Hazel::Log::GetClientLogger()->fatal(__VA_ARGS__)