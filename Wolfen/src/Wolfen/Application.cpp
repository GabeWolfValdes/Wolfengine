#include "wfpch.h"

#include "Application.h"
#include <GLFW/glfw3.h>
#include "Wolfen/Events/ApplicationEvent.h"

namespace Wolfen
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>( Window::Create() );
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e( 1200, 720 );
		WF_TRACE( e );
		while( m_Running )
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		};
	}
}