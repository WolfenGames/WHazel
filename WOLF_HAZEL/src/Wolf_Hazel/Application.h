#pragma once

#include "Core.h"
#include <Wolf_Hazel/Window.h>
#include <Wolf_Hazel/Event/Event.h>
#include <Wolf_Hazel/Event/ApplicationEvent.h>
#include <Wolf_Hazel/Event/KeyEvent.h>

namespace Wolf_Hazel {
	class WH_API Application {
	public:
		Application();
		virtual ~Application();
		void	OnEvent(Event&);
		void	Run();

		inline Window& GetWindow() { return *m_window; }

		inline static Application& Get() { return *s_Instance; }
	private:

		bool OnWindowCloseEvent(WindowCloseEvent& e);
		
		std::unique_ptr<Window> m_window;
		bool	m_running = true;
	private:
		static Application* s_Instance;
	
	};

	Application* CreateApplication();
}

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
