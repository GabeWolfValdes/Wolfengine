#include "wfpch.h"

#include "WindowsWindow.h"
#include "Wolfen/Renderer/OpenGL/OpenGLContext.h"

namespace Wolfen
{
	static bool s_bGraphicsInitialized = false;

	static void GLFWErrorCallback( int error, const char* description )
	{
		WF_CORE_ERROR( "GLFW Error ({0}): {1}", error, description );
		WF_CORE_ASSERT( false, "GLFW error hit!" );
	}

	WindowsWindow::WindowsWindow( const WindowProps& props )
	{
		Init( props );
	}

	Window* Window::Create( const WindowProps& props )
	{
		return new WindowsWindow( props );
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init( const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		WF_CORE_INFO( "Creating Window {0} ({1}, {2})", props.Title, props.Width, props.Height );
	
		
		if( !s_bGraphicsInitialized )
		{
			//todo glfwTerminate on system shutdown
			int success = glfwInit();
			WF_CORE_ASSERT( success, "Could not initialize GLFW!" );
			glfwSetErrorCallback( GLFWErrorCallback );

			s_bGraphicsInitialized = true;
		}
		
		// todo abstract
		m_Window = glfwCreateWindow( (int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr );
		
		m_Context = new OpenGLContext(m_Window);
		m_Context->Init();

		// todo abstract
		glfwSetWindowUserPointer( m_Window, &m_Data );

		SetVSync( true );
	}

	void WindowsWindow::Shutdown()
	{
		// todo abstract
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		// todo abstract to window update
		glfwPollEvents();

		m_Context->SwapBuffers();
	}

	void WindowsWindow::SetVSync( bool enabled )
	{
		// todo abstract
		if( enabled )
			glfwSwapInterval( 1 );
		else
			glfwSwapInterval( 0 );
		
		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

}

