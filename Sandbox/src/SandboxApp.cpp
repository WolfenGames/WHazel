#include <WH.h>

class Sandbox : public Wolf_Hazel::Application
{
public:
	Sandbox(){}
	~Sandbox(){}
};

Wolf_Hazel::Application* Wolf_Hazel::CreateApplication()
{
	return new Sandbox();
}