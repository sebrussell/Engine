#include "InputHandlerScript.h"
#include "Input.h"
#include "Transform.h"
#include "GameObject.h"
#include "SceneManager.h"

void InputHandler::Awake()
{
	m_transform = m_gameObject.lock()->GetComponent<Transform>();
	if(m_transform.expired())
	{
		m_transform = m_gameObject.lock()->AddComponent<Transform>();
	}
	m_input = m_gameObject.lock()->m_sceneManager.lock()->m_input;
}

void InputHandler::Update()
{
	float amount = m_speed; //*delta time
	switch (m_input.lock()->GetCurrentKey())
	{
		case W:
			m_transform.lock()->ChangePosition(glm::vec3(amount, 0.0f, 0.0f));
			break;
		case S:
			m_transform.lock()->ChangePosition(glm::vec3(-amount, 0.0f, 0.0f));
			break;
		case D:
			m_transform.lock()->ChangePosition(glm::vec3(0.0f, 0.0f, -amount));
			break;
		case A:
			m_transform.lock()->ChangePosition(glm::vec3(0.0f, 0.0f, amount));
			break;
		default:
			break;
	}
	
    m_mouseXOffset = m_input.lock()->m_mouseMovementX * m_mouseSensitivty;
    m_mouseYOffset = m_input.lock()->m_mouseMovementY * m_mouseSensitivty;

	m_transform.lock()->SetYawAndPitch(m_mouseXOffset, m_mouseYOffset);

	
}
