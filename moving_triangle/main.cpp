#include "main.h"

/**
 * main- the main function
 *
 */
int main(void)
{
	if (!glfwInit())
	{
		std::cout<<"failed to Initialize. Terminating..."<<std::endl;
		exit(90);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//creating window
	GLFWwindow* window = glfwCreateWindow(350, 400, "MyWindow", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create window" <<std::endl;
		return (-1);
	}
	glfwMakeContextCurrent(window);

	//initialize glad to load os specific glfw functions
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
    	std::cout << "Failed to initialize GLAD" << std::endl;
    	return -1;
	}    

	glViewport(0, 0, 350, 400);

	//the rendering loop
	while (!glfwWindowShouldClose(window))
	{
		//input
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// check and call events and swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return (0);
}
