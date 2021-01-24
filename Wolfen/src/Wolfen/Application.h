#pragma once

#include "wfpch.h"
#include "Core.h"
#include "Window.h"
#include "Wolfen/Events/ApplicationEvent.h"
#include "Wolfen/Events/Event.h"
#include "Wolfen/Renderer/Buffer.h"

// todo this is temp
#include "Wolfen/Renderer/Shader.h"

namespace Wolfen
{
	class Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

		void OnEvent(Event& e);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	
	private:
		bool OnWindowClose( WindowCloseEvent& e );
	
	private:
		Window* m_Window; // todo change to window ptr
		bool m_Running = true;

		unsigned int m_VertexArray;

		VertexBuffer* m_VertexBuffer;
		IndexBuffer* m_IndexBuffer;
		Shader* m_Shader;
	
	private:
		static Application* s_Instance;
	};

	// To be defined in Client // 
	Application* CreateApplication();

}
