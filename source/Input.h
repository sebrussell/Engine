#ifndef INPUT_H
#define INPUT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <iostream>
#include <vector>

class SceneManager;
class OpenGL;

enum KeyPress
{
	NoInput,
	W,
	A,
	S,
	D,
	ESC
};

class Input
{
	public:
		Input();
		~Input();
		void Awake();
		void SetSceneManager(std::weak_ptr<SceneManager> _sceneManager);
		void ProcessMouse(double _xpos, double _ypos);
		void ProcessScroll(double _xOffset, double _yOffset);
		void ProcessKey(GLFWwindow* m_window);
		
		double m_mouseX, m_mouseY;
		double m_mouseMovementX, m_mouseMovementY;
		
		double m_scrollX, m_scrollY;
	
		
	private:
		std::weak_ptr<SceneManager> m_sceneManager;
		double m_oldMouseX, m_oldMouseY;
		
		std::vector<KeyPress> m_keysPressed;
};

#endif