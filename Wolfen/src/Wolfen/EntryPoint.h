#pragma once

#ifdef WF_PLATFORM_WINDOWS

extern Wolfen::Application* Wolfen::CreateApplication();

int main( int argc, char** argv )
{
	printf("Wolfen Application");
	auto app = Wolfen::CreateApplication();
	app->Run();
	delete app;
}

#endif //
