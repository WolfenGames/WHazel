#include "Application.h"
#include "whpch.h"
#include <Wolf_Hazel\Event\ApplicationEvent.h>
#include <Wolf_Hazel/Event/KeyEvent.h>
#include <Wolf_Hazel/KeyCodes.h>
#include <glad/glad.h>

namespace Wolf_Hazel
{
	Application::Application()
	{
		m_window = std::unique_ptr<Window>(Window::Create());
		m_window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowCloseEvent));
		WH_CORE_TRACE("{0}", e);
	}

	bool Application::OnWindowCloseEvent(WindowCloseEvent &e)
	{
		m_running = false;
		return true;
	}

	void Application::Run()
	{
		while (m_running) {
			m_window->OnUpdate();
		}
	}
}
