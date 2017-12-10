#include "InputHandlerScript.h"
#include "Input.h"
#include "Transform.h"
#include "GameObject.h"
#include "SceneManager.h"
#include "Rigidbody.h"

void InputHandler::Awake()
{
	m_transform = m_gameObject.lock()->GetComponent<Transform>();
	if(m_transform.expired())
	{
		m_transform = m_gameObject.lock()->AddComponent<Transform>();
	}
	m_input = m_gameObject.lock()->m_sceneManager.lock()->m_input;
	m_body = m_gameObject.lock()->GetComponent<Rigidbody>();
	if(m_body.expired())
	{
		m_useBody = false;
	}
	else
	{
		m_useBody = true;
	}
}

void InputHandler::Update()
{
	float amount = m_speed; //*delta time
	
	glm::vec3 force;
	
	switch (m_input.lock()->GetCurrentKey())
	{
		case W:			
				force = glm::vec3(amount, 0.0f, 0.0f);
			break;
		case S:
				force = glm::vec3(-amount, 0.0f, 0.0f);
			break;
		case D:
				force = glm::vec3(0.0f, 0.0f, amount);			
			break;
		case A:
				force = glm::vec3(0.0f, 0.0f, -amount);			
			break;
		default:
			break;
	}
	
	m_transform.lock()->ChangePosition(force);
	
	if(m_useBody)
	{
		
		m_body.lock()->SetPosition(m_transform.lock()->GetPosition());
	}

	
    m_mouseXOffset = m_input.lock()->m_mouseMovementX * m_mouseSensitivty;
    m_mouseYOffset = m_input.lock()->m_mouseMovementY * m_mouseSensitivty;

	m_transform.lock()->SetYawAndPitch(m_mouseXOffset, m_mouseYOffset);

	
}
