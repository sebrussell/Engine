#include "Transform.h"

void Transform::Awake()
{
	m_position = glm::vec3(0.0f, 0.0f, 0.0f);	
	m_localPosition = glm::vec3(1, 1, 1);
	m_front = glm::vec3(0.0f, 0.0f, -1.0f);
	m_up    = glm::vec3(0.0f, 1.0f,  0.0f);	
}

void Transform::Update()
{
    // Calculate the new Front vector
	//m_front.x = cos(glm::radians(m_pitch)) * cos(glm::radians(m_yaw));
	//m_front.y = sin(glm::radians(m_pitch));
	//m_front.z = cos(glm::radians(m_pitch)) * sin(glm::radians(m_yaw));
	//m_front = glm::normalize(m_front);
    // Also re-calculate the Right and Up vector
   // m_right = glm::normalize(glm::cross(m_front, m_worldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	//m_up    = glm::normalize(glm::cross(m_right, m_front));
}

glm::mat4 Transform::GetModelMatrix()
{
	glm::mat4 model;
	model = glm::mat4();
	model = glm::translate(model, m_position);
	return model;
}

glm::mat4 Transform::GetLookAt()
{
	return glm::lookAt(m_position, m_position + m_front, m_up);
}

glm::vec3 Transform::GetPosition()
{
	glm::vec3 position;
	while(!m_parent.expired())
	{
		position = m_parent.lock()->GetPosition() + m_localPosition;
	}
	return position;
}

glm::vec3 Transform::GetLocalPosition()
{
	return m_localPosition;
}

void Transform::SetLocalPosition(glm::vec3 _position)
{
	m_localPosition = _position;
}

void Transform::SetParent(std::weak_ptr<Transform> _parent)
{
	m_parent = _parent;
}