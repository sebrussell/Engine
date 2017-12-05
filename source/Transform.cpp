#include "Transform.h"

void Transform::Awake()
{
	m_position = glm::vec3(0.0f, 0.0f, 0.0f);	
	m_localPosition = glm::vec3(1, 1, 1);
	m_front = glm::vec3(0.0f, 0.0f, -1.0f);
	m_up    = glm::vec3(0.0f, 1.0f,  0.0f);	
	m_worldUp = m_up;
}

void Transform::Update()
{
        glm::vec3 front;
        front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
        front.y = sin(glm::radians(m_pitch));
        front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
        m_front = glm::normalize(front);
        // Also re-calculate the Right and Up vector
        m_right = glm::normalize(glm::cross(m_front, m_worldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        m_up    = glm::normalize(glm::cross(m_right, m_front));
}

glm::mat4 Transform::GetModelMatrix()
{
	glm::mat4 model;
	model = glm::mat4();
	model = glm::translate(model, m_position);
	return model;
}

void Transform::SetYawAndPitch(float _yaw, float _pitch)
{
	m_yaw = _yaw;
	m_pitch = _pitch;
	
	if (1) //constrain pitch boolean
    {
        if (m_pitch > 89.0f)
            m_pitch = 89.0f;
        if (m_pitch < -89.0f)
            m_pitch = -89.0f;
    }
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

void Transform::ChangePosition(glm::vec3 _position)
{
	m_position += _position;
}

void Transform::SetParent(std::weak_ptr<Transform> _parent)
{
	m_parent = _parent;
}