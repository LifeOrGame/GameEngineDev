#include "window.h"
namespace sparky
{
	namespace graphics
	{
	
		Window::Window(const char *title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
			if (!init())
			{
				glfwTerminate();
			}
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Failed to init GLFW!" << std::endl;
				return false;
			}
			m_GLFWwindow = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (!m_GLFWwindow)
			{
				glfwTerminate();
				std::cout << "Failed to create GLFW Window!" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_GLFWwindow);
			return true;
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_GLFWwindow);
		}

		void Window::update() const
		{
			glfwPollEvents();
			glfwSwapBuffers(m_GLFWwindow);
		}
	}
}