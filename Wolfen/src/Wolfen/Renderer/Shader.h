#pragma once
#include "wfpch.h"

namespace Wolfen
{
	class Shader
	{
	public:
		Shader( const std::string& vs, const std::string& ps );
		~Shader();

		void Bind() const;
		void Unbind() const;

	private:
		uint32_t m_id;
	};

}