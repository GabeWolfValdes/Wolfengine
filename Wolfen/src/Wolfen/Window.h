#pragma once

#include "wfpch.h"
#include "Wolfen/Core.h"

// interface for platform specific windows
namespace Wolfen
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps( const std::string& title = "WolfEngine",
			unsigned int width = 1280,
			unsigned int height = 720 )
			:Title(title),Width(width),Height(height)
		{
		}
	};

	class Window
	{
	public:
		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetVSync( bool enabled ) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create( const WindowProps& props = WindowProps() );
	};
}