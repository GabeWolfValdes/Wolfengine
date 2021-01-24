#include "wfpch.h"

#include "Application.h"
#include <glad/glad.h>
#include "Wolfen/Events/ApplicationEvent.h"

namespace Wolfen
{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = Window::Create();

		// this sets the function to call when an event occurs
		m_Window->SetEventCallback( BIND_EVENT_FN( OnEvent ) );

		// todo abstract this away

		// VertexBuffer vb = VertexBuffer::Create(sizeof(vertices),vertices);
		
		glGenVertexArrays( 1, &m_VertexArray );
		glBindVertexArray( m_VertexArray );

		float vertices[3 * 3] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		m_VertexBuffer = VertexBuffer::Create( vertices, sizeof( vertices ) );
		//m_VertexBuffer->Bind();

		glEnableVertexAttribArray( 0 );
		glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof( float ), nullptr );

		uint32_t indices[3] = {0, 1, 2};
		m_IndexBuffer = IndexBuffer::Create( indices, sizeof(indices)/sizeof(uint32_t) );
		//m_IndexBuffer->Bind();


		std::string vertexSrc = R"(
				#version 330 core
				
				layout(location=0) in vec3 a_Position;
			
				out vec3 v_Position;

				void main()
				{
					v_Position = a_Position;
					gl_Position = vec4(a_Position,1.0);
				}
			)";

		std::string pixelSrc = R"(
				#version 330 core

				layout(location=0) out vec4 color;

				in vec3 v_Position;
				void main()
				{
					color = vec4( v_Position* 0.5f + 0.5f, 1.0);
				}
			)";

		m_Shader = new Shader( vertexSrc, pixelSrc );
	}

	Application::~Application()
	{
	}

	void Application::OnEvent( Event& e )
	{
		EventDispatcher dispatcher( e );


		dispatcher.Dispatch<WindowCloseEvent>( BIND_EVENT_FN( OnWindowClose ) );

		WF_CORE_TRACE( "{0}", e );
	}

	void Application::Run()
	{
		while( m_Running )
		{
			glClearColor(1, 1, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Shader->Bind();
			glBindVertexArray( m_VertexArray );
			glDrawElements( GL_TRIANGLES, m_IndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr );
			m_Window->OnUpdate();
		};
	}

	bool Application::OnWindowClose( WindowCloseEvent& e )
	{
		m_Running = false;
		return true;
	}
}