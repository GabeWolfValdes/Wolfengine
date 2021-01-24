#pragma once
#include "wfpch.h"
#include "Wolfen/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Wolfen
{
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext( GLFWwindow* window );

		virtual void Init();
		virtual void SwapBuffers();
	
	private:
		GLFWwindow* m_WindowHandle;
	};
}