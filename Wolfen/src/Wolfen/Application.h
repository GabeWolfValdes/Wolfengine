#pragma once

#include "wfpch.h"
#include "Core.h"
#include "Window.h"

namespace Wolfen
{
	class Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

	private:
		std::unique_ptr<Window> m_Window; // todo change to window ptr
		bool m_Running = true;
	};

	// To be defined in Client // 
	Application* CreateApplication();

}
