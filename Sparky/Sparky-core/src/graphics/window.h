#pragma once
#include <GLFW\glfw3.h>
#include <iostream>
namespace sparky {namespace graphics {
	class  Window
	{
	private:
		const char *m_Title;
		int m_Width, m_Height;
		GLFWwindow* m_Window;
		bool m_Closed;
	public:
		 Window(const char* name, int width, int height);
		~ Window();
	public:
		void update() const;
		bool closed() const;
	private:
		bool init();
	};
}}