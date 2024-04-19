#include "main.h"

/**
 * processInput- takes action based on the key pressed
 * @window- targeted window
 *
 * Return: nothing
 */
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

}
