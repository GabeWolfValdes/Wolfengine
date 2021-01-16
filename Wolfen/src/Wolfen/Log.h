#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>

namespace Wolfen
{
	class WOLFEN_API Log
	{
	public:
		Log();
		~Log();
		static void Init();
		inline static std::shared_ptr<spdlog::logger>GetCoreLogger()
		{
			return spCoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>GetClientLogger()
		{
			return spClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> spCoreLogger;
		static std::shared_ptr<spdlog::logger> spClientLogger;
	};
}

// core log macros
#define WF_CORE_TRACE(...) ::Wolfen::Log::GetCoreLogger()->trace( __VA_ARGS__ )
#define WF_CORE_INFO(...) ::Wolfen::Log::GetCoreLogger()->info( __VA_ARGS__ )
#define WF_CORE_WARN(...) ::Wolfen::Log::GetCoreLogger()->warn( __VA_ARGS__ )
#define WF_CORE_ERROR(...) ::Wolfen::Log::GetCoreLogger()->error( __VA_ARGS__ )
#define WF_CORE_FATAL(...) ::Wolfen::Log::GetCoreLogger()->fatal( __VA_ARGS__ )

// Client(app) log macros
#define WF_TRACE(...) ::Wolfen::Log::GetClientLogger()->trace( __VA_ARGS__ )
#define WF_INFO(...) ::Wolfen::Log::GetClientLogger()->info( __VA_ARGS__ )
#define WF_WARN(...) ::Wolfen::Log::GetClientLogger()->warn( __VA_ARGS__ )
#define WF_ERROR(...) ::Wolfen::Log::GetClientLogger()->error( __VA_ARGS__ )
#define WF_FATAL(...) ::Wolfen::Log::GetClientLogger()->fatal( __VA_ARGS__ )

