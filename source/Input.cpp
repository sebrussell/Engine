#include "Input.h"
#include "OpenGL.h"
#include "SceneManager.h"

Input::Input()
{
	m_mouseX = 0;
	m_mouseY = 0;
}

Input::~Input()
{
	
}

void Input::Awake()
{
	m_mouseX = 0;
	m_mouseY = 0;
	m_oldMouseX = 0;
	m_oldMouseY = 0;
	
	m_keysPressed.push_back(NoInput);
	m_keysPressed.push_back(NoInput);
	m_keysPressed.push_back(NoInput);
	m_keysPressed.push_back(NoInput);
	m_keysPressed.push_back(NoInput);
	
}

void Input::SetSceneManager(std::weak_ptr<SceneManager> _sceneManager)
{
	m_sceneManager = _sceneManager;
}

void Input::ProcessMouse(double _xpos, double _ypos)
{
	m_mouseX = _xpos;
	m_mouseY = _ypos;
}

void Input::ProcessScroll(double _xOffset, double _yOffset)
{
	m_scrollX = _xOffset;
	m_scrollY = _yOffset;
}

void Input::ProcessKey(GLFWwindow* m_window)
{
	m_keysPressed.at(4) = m_keysPressed.at(3);
	m_keysPressed.at(3) = m_keysPressed.at(2);
	m_keysPressed.at(2) = m_keysPressed.at(1);	
	m_keysPressed.at(1) = m_keysPressed.at(0);	
	
	if(glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
        glfwSetWindowShouldClose(m_window, true);	
		m_keysPressed.at(0) = ESC;
	}
	else if (glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS)
	{
        m_keysPressed.at(0) = W;
	}
    else if (glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS)
	{
         m_keysPressed.at(0) = S;
	}
    else if (glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS)
	{
        m_keysPressed.at(0) = A;
	}
    else if (glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS)
	{
        m_keysPressed.at(0) = D;
	}	
	else
	{
		m_keysPressed.at(0) = NoInput;
	}
	
	m_mouseMovementX = m_mouseX - m_oldMouseX;
	m_mouseMovementY = m_oldMouseY - m_mouseY; // reversed since y-coordinates range from bottom to top
	
	m_oldMouseX = m_mouseX;
	m_oldMouseY = m_mouseY;
}


