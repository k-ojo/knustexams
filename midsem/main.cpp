#include "ex.h"

/**
 * fbuffer_size_callback- changes the viewport of OpenGl
 * @w: window
 * @width: witdh of window
 * @height: height of window
 * Return: nothing
 *
 */
void fbuffer_size_cb(GLFWwindow* w, int width, int height)
{
	glViewport(0, 0, width, height);
}

/**
 * main- the main function
 *
 */
int main(void)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	
	/*creating window*/

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpengGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GFLW window" << std::endl;
		glfwTerminate();
		return (-1);
	}

	/* make window the current context*/
	glfwMakeContextCurrent(window);

	/*initializing glad*/
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return (-1);
	}

	/* telling OpenGL the size window of our application */

	glViewport(0, 0, 800, 600);

	/* readjusts view port for window after resize */
	glfwSetFramebufferSizeCallback(window, fbuffer_size_cb);

	/* render loop */

	while(!glfwWindowShouldClose(window))
	{
		/* input processor */
		processInput(window);

		//rendering commands
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// poll and swap buffers
	glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return (0);
}
