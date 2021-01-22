#pragma once

#ifdef WF_PLATFORM_WINDOWS

extern Wolfen::Application* Wolfen::CreateApplication();

int main( int argc, char** argv )
{
	Wolfen::Log::Init();

	//WF_TRACE( "Welcome to WOLFENgine" );
	auto app = Wolfen::CreateApplication();
	app->Run();
	delete app;
}

#endif //
