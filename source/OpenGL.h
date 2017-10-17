#ifndef OPENGL_H
#define OPENGL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#include "Camera.h"

class OpenGL
{
	public:
		OpenGL();
		int Setup();
		int GetWindowWidth() { return SCR_WIDTH; }
		int GetWindowHeight() { return SCR_HEIGHT; }
		
		bool CloseWindow();
		void processInput(Camera cameraMain);
		void SwapBuffers();
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
		static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
		static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
		static void error_callback(int error, const char* description);
		float deltaTime;	// Time between current frame and last frame
	private:
		GLFWwindow* m_window;
		float lastFrame; // Time of last frame
		int SCR_WIDTH;
		int SCR_HEIGHT;
};

#endif