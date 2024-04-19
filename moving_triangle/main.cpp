#include "main.h"

float vertices[] = {
    // positions          // color
    -0.1f,  -0.1f, 0.0f,   1.0f, 1.0f, 1.0f, // top right
    0.1f, -0.1f, 0.0f,   1.0f, 1.0f, 1.0f, // bottom right
    0.1f, 0.1f, 0.0f,   1.0f, 1.0f, 1.0f, // bottom left
    -0.1f,  0.1f, 0.0f,   1.0f, 1.0f, 1.0f  // top left 
};
unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};  



/**
 * main- the main function
 * 
 */
int main(void)
{
	unsigned int vertexShader, fragmentShader, shaderProgram;
	unsigned int VBO, VAO, EBO;
	int  success, succ;
	char infoLog[512];
	float offset = 0.5f;




	if (!glfwInit())
	{
		std::cout<<"failed to Initialize. Terminating..."<<std::endl;
		exit(90);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//creating window
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "MyWindow", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create window" <<std::endl;
		return (-1);
	}  
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//initialize glad to load os specific glfw functions
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
    	std::cout << "Failed to initialize GLAD" << std::endl;
    	return -1;
	}

	Shader ourShader("vertex.vert", "fragment.fs");

	
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &EBO);
	
	//bind vertice array
	glBindVertexArray(VAO);

	//vertice buffer objects
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//load data into buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	

	//elements buffer objects
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	
	//specify how array of floats are interpreted by opengl
	//position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	//wireframe 
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	//the rendering loop
	while (!glfwWindowShouldClose(window))
	{
		//input
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//draw object
		//glUseProgram(shaderProgram);
		ourShader.use();
		
		//ourShader.setFloat("xOffset", offset);


		glm::mat4 transform = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
        transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

		unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

		//render object
		glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		// check and call events and swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);
	glfwTerminate();
	return (0);
	
}