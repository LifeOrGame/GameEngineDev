#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
namespace sparky
{
	namespace graphics
	{
		class Window
		{
		private:
			const char* m_Title;
			int m_Width, m_Height;
			GLFWwindow *m_GLFWwindow;
			bool m_Closed;
		public:
			Window(const char *title, int width, int height);
			~Window();
		public:
			bool init();
			bool closed() const;
			void update() const;
		};
	}
}