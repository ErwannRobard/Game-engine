#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;
int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;


	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		cout << "Error" << endl;
	}

	/*float array containing position of the triangle*/
	float positions[6] = {
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.0f,  0.5f
	};
	cout << glGetString(GL_VERSION) << endl;

	//creating buffer
	unsigned int buffer;
	glGenBuffers(1, &buffer); //(number of buffer we want, memory of the buffer) we give him the memory, but he generate an int that will serve as the ID of the buffer
	//selectin usage of the buffer, or "binding" buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffer); //in OpenGL, selecting = binding // we "bind" buffer to a buffer array, so now it knows that "buffer" is a buffer array, now when we call glDraw, it will draw for a buffer array
	//putting stuff in the buffer
	glBufferData(GL_ARRAY_BUFFER, 6*sizeof(float), positions, GL_STATIC_DRAW);
	//we tell OpenGL the structure of the vertex position, by giving him a name (index), a vertice of 2, that it should allocate space for floats, no normalisation since we want to keep the decimals, we also tell it the byte space between each vertice (stride), and finaly the address of the first vertex attribute (a pointer is a number!)
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	//enable so VertexAttribArray is used when calling Draw
	glEnableVertexAttribArray(0);

	//shader = a program that on the GPU instead of the CPU that manipulates data inside the vertex buffers
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		//drawing the array
		glDrawArrays(GL_TRIANGLES, 0, 3);
		
		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}