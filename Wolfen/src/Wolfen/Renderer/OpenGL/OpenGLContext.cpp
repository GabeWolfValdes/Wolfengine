#include "wfpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Wolfen
{
	OpenGLContext::OpenGLContext( GLFWwindow* window )
		:m_WindowHandle(window)
	{
		WF_CORE_ASSERT(m_WindowHandle, "Window Handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		WF_CORE_ASSERT(status, "Failed to initialize Glad!");

		WF_CORE_INFO( "OpenGL Info:" );
		WF_CORE_INFO( "  Vendor: {0}", glGetString( GL_VENDOR ) );
		WF_CORE_INFO( "  Renderer: {0}", glGetString( GL_RENDERER ) );
		WF_CORE_INFO( "  Version: {0}", glGetString( GL_VERSION ) );
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}