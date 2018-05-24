#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

using namespace glm;

int main(void) {
	// Initialize GLFW
	glewExperimental = true; // Needed for core profile
	if (!glfwInit()) {
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // For MacOS. Should not need
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // No old OpenGL

	// Open a window and create its OpenGL context
	GLFWwindow* window;
	window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);
	if (NULL == window) {
		fprintf(stderr, "Failed to open GLFW window. If you have an "
				"Intel GPU, they are not 3.3 compatible. Try "
				"the 2.1 version of the tutorial\n");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window); // Initialize GLEW
	if (GLEW_OK != glewInit()) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	// Ensure we can capture the escape key being pressed
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	do {
		// Clear the screen. It's not mentioned before Tutorial 02,
		// but it can cause flickering, so it's there nonetheless.
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw nothing

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	} while((GLFW_PRESS != glfwGetKey(window, GLFW_KEY_ESCAPE)) &&
		(0 == glfwWindowShouldClose(window)));

	return 0;
}
