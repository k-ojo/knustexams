#ifndef MAIN_H
#define MAIN_H
#include <glad/glad.h>
#include<GLFW/glfw3.h>
#include <math.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <thread>
#include<chrono>
#define SCR_WIDTH 800
#define SCR_HEIGHT 600


 
void processInput(GLFWwindow *window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void updatePos(float& numX, float& numY, bool& incrementingX, bool& incrementingY);
glm::mat4 translate(float x, float y, float z);
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

    Shader(const char* vertextPath, const char* fragmentPath);
    void use();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;   
    void setFloat(const std::string &name, float value) const;    
};

#endif
