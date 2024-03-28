#include "ex.h"

/**
 * processInput- processes input
 * @w: window 
 * Return: nothing
 */
void processInput(GLFWwindow *w)
{
	if(glfwGetKey(w, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(w, true);
}
