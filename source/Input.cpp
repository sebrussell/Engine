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
}

void Input::SetSceneManager(std::weak_ptr<SceneManager> _sceneManager)
{
	m_sceneManager = _sceneManager;
}

void Input::ProcessMouse(double _xpos, double _ypos)
{
	m_mouseX = _xpos;
	m_mouseY = _ypos;
	
	m_mouseMovementX = m_mouseX - m_oldMouseX;
	m_mouseMovementY = m_mouseY - m_oldMouseY;
	
	m_oldMouseX = m_mouseX;
	m_oldMouseY = m_mouseY;
}

void Input::ProcessScroll(double _xOffset, double _yOffset)
{
	m_scrollX = _xOffset;
	m_scrollY = _yOffset;
	
	std::cout << m_scrollY << std::endl;
}


