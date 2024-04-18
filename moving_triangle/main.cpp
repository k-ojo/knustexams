#include "main.h"

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
}; 


const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor= vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
    "}\0";


/**
 * main- the main function
 * 
 */
int main(void)
{
	unsigned int vertexShader, fragmentShader;
	unsigned int VBO;
	int  success, succ;
	char infoLog[512];
	 

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

	//binding buffer
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//create shader object
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); 

	//compile vertex shader
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	glCompileShader(vertexShader);




	//verify compilation
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &succ);
	if(!success)
	{
    	glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    	std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	if (!succ)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

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
