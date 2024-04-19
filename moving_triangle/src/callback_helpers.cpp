#include "main.h"

/**
 * framebuffer_size_callback- readjust window on window resize
 *
 * @window: input window
 * @width: the width of window
 * @height: height of window
 *
 * Return:  nothing
 */
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
