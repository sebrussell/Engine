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
class Input;
class SceneManager;

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
		void SetViewPort(int _width = m_defaultWindowWidth, int _height = m_defaultWindowHeight);
		void SetSceneManager(std::weak_ptr<SceneManager> _manager);
		GLFWwindow* GetWindow() { return m_window; }
		
		//-------- CALLBACK FUNCTIONS ----------//
		static void KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void FrameBufferSizeCallBack(GLFWwindow* window, int width, int height);
		static void MouseCallBack(GLFWwindow* window, double xpos, double ypos);
		static void ScrollCallBack(GLFWwindow* window, double xoffset, double yoffset);
		static void ErrorCallBack(int error, const char* description);
		
		float m_aspectRatio;
	private:
		GLFWwindow* m_window;

		float lastFrame; // Time of last frame	
		float deltaTime;
		
		int m_windowWidth;
		int m_windowHeight;
		
		static const int m_defaultWindowWidth = 800;
		static const int m_defaultWindowHeight = 600;
		
		std::weak_ptr<Transform> m_cameraMain;
		std::weak_ptr<SceneManager> m_sceneManager;
		
};

#endif