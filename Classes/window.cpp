#include "window.h"

// int Window::_stepsOffline = STEPS_OFFLINE;

// void Window::glfwKeyCallback(GLFWwindow* window, const int key, const int scancode, const int action, const int mods)
// {
// 	if(action == GLFW_PRESS)
// 	{
// 		switch (key)
// 		{
// 			case GLFW_KEY_SPACE: 
// 				_stepsOffline = _stepsOffline==STEPS_OFFLINE ? 1 : STEPS_OFFLINE; 
// 				printf("Offline steps changed to %d\n", _stepsOffline);
// 				break;
// 			default: break;
// 		}
// 	}
// }

Window::Window()
{
	draw = nullptr;
	run = nullptr;

	// Check if glfw was initialized
	if(!glfwInit())
	{
		std::cout << BOLDRED << "[Window] GLFW initialization failed!" << RESET << std::endl;
		glfwTerminate();
		exit(1);
	}

	//----- GLFW config -----//
	glfwWindowHint(GLFW_RESIZABLE, WINDOW_RESIZABLE ? GLFW_TRUE : GLFW_FALSE);
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	//----- Create main window -----//
	GLFWmonitor* monitor = WINDOW_FULLSCREEN ? glfwGetPrimaryMonitor() : nullptr;

	_mainWindow = glfwCreateWindow(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT, "Living Beings", monitor, nullptr);
	//glfwSetWindowPos(_mainWindow, mode->width/2-(MAIN_WINDOW_WIDTH+CONSENSUS_PLOT_WINDOW_WIDTH)/2, 0);


	
	if(_mainWindow == nullptr)
	{
		std::cout << BOLDRED << "[Window] Failed to create main window!" << RESET << std::endl;
		glfwTerminate();
		exit(1);
	}

	// Set to draw to this window
	glfwMakeContextCurrent(_mainWindow);
	
}

Window::~Window()
{
	// Destroy window and terminate glfw
	if(_mainWindow != nullptr)
		glfwDestroyWindow(_mainWindow);
	glfwTerminate();
}

void Window::start()
{
	if(draw == nullptr)
		std::cout << BOLDYELLOW << "[Window] Draw function not defined!" << RESET << std::endl;
	if(run == nullptr)
		std::cout << BOLDYELLOW << "[Window] Run function not defined!" << RESET << std::endl;

	// Keep executing the code until the window is closed
	while (!glfwWindowShouldClose(_mainWindow))
	{
		glfwPollEvents();

		//----- Draw to main window -----//
		glfwMakeContextCurrent(_mainWindow);
		glClearColor(1.0, 1.0, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode (GL_PROJECTION);
  		glLoadIdentity();
		glOrtho(0, 800, 600, 0, -1, 1);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable( GL_BLEND );
		
		// Call run function
		if(run != nullptr)
			run();

		// Call draw function
		if(draw != nullptr)
			draw();

		glfwSwapBuffers(_mainWindow);
	}
}
