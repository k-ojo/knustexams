#ifndef MAIN_H
#define MAIN_H
#include <glad/glad.h>
#include<GLFW/glfw3.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

 
void processInput(GLFWwindow *window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

/**
 * Shader- shader class for reading from disk
 * @ID: the program ID
 * 
 * 
*/
class Shader
{
    public:
    unsigned int ID;

};

#endif
