#pragma once

#include "Core.h"

namespace Wolf_Hazel {
	class WH_API Application {
	public:
		Application();
		virtual ~Application();
		void	Run();
	};

	Application* CreateApplication();
}
