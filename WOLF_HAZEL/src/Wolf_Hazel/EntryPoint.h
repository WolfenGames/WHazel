#pragma once

#ifdef WH_PLATFORM_WINDOWS

extern Wolf_Hazel::Application* Wolf_Hazel::CreateApplication();

int	main(int ac, char** av)
{
	Wolf_Hazel::Log::Init();

	WH_INFO("Welcome to Wolf_Hazel Engine Inspired by TheCherno Hazel Engine");
	auto app = Wolf_Hazel::CreateApplication();
	app->Run();
	delete app;
}
#endif