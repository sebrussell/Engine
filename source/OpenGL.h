#ifndef OPENGL_H
#define OPENGL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <memory>

class Transform;

class OpenGL
{
	public:
		OpenGL();
		~OpenGL();
		int Setup(int _windowWidth, int _windowHeight);		
		
		
		bool ShouldWindowClose();
		void ProcessInput();
		void SwapBuffers();
		float GetDeltaTime() { return deltaTime; }
		int GetWindowWidth() { return m_windowWidth; }
		int GetWindowHeight() { return m_windowHeight; }
		void SetCameraMainTransform(std::weak_ptr<Transform> _transform);
		void SetViewPort();
		
		//-------- CALLBACK FUNCTIONS ----------//
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
		static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
		static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
		static void error_callback(int error, const char* description);
		
		float m_aspectRatio;
	private:
		GLFWwindow* m_window;

		float lastFrame; // Time of last frame	
		float deltaTime;
		
		int m_windowWidth;
		int m_windowHeight;
		
		std::weak_ptr<Transform> m_cameraMain;
		
};

#endif