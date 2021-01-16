#include <Wolfen.h>

class Sandbox : public Wolfen::Application 
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Wolfen::Application* Wolfen::CreateApplication()
{
	return new Sandbox();
}