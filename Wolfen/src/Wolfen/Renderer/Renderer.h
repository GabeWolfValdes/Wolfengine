#pragma once

namespace Wolfen
{
	enum class RendererAPI
	{
		None =0,
		OpenGL,
		DX12
	};

	class Renderer
	{
	public:
		inline static RendererAPI GetAPI() { return s_RendererAPI; }
	private:
		static RendererAPI s_RendererAPI;
	};
}