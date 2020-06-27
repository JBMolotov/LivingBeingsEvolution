#ifndef WINDOW_H
#define WINDOW_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glut.h>



#include <stdlib.h>
#include <iostream>
#include <functional>
//#include "defines.h"

class Window
{
public:
	Window();
	~Window();

	void start();
	//static void glfwKeyCallback(GLFWwindow* window, const int key, const int scancode, const int action, const int mods);

	// Functions called each frame
	std::function<void()> draw;
	std::function<void()> run;
private:
	GLFWwindow *_mainWindow;
};
#endif// WINDOW_H
