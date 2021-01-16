#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Wolfen
{
	std::shared_ptr<spdlog::logger> Log::spCoreLogger;
	std::shared_ptr<spdlog::logger> Log::spClientLogger;

	void Log::Init()
	{
		// sets output message patterm
		spdlog::set_pattern( "%^[%T] %n: %v%$" );
		
		// set colors 
		spCoreLogger = spdlog::stdout_color_mt( "WOLFEN" );
		spCoreLogger->set_level( spdlog::level::trace );
		
		spClientLogger = spdlog::stdout_color_mt( "APP" );
		spClientLogger->set_level( spdlog::level::trace );

	}
}