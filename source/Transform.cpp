#include "Transform.h"

void Transform::Awake()
{
	m_position = glm::vec3(0.0f, 0.0f, 0.0f);	
	m_localPosition = glm::vec3(0.0f, 0.0f, 0.0f);
	m_front = glm::vec3(0.0f, 0.0f, -1.0f);
	m_up    = glm::vec3(0.0f, 1.0f,  0.0f);	
	m_worldUp = m_up;
	m_parent = std::weak_ptr<Transform>();
	m_hasParent = false;
}

void Transform::Update()
{
		UpdatePosition(m_position);		
        glm::vec3 front;
        front.x = cos(glm::radians(m_rotation.y)) * cos(glm::radians(m_rotation.x));
        front.y = sin(glm::radians(m_rotation.x));
        front.z = sin(glm::radians(m_rotation.y)) * cos(glm::radians(m_rotation.x));
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
	model = glm::rotate(model, glm::radians(m_rotation.x), glm::vec3(1.0, 0.0, 0.0));
	model = glm::rotate(model, glm::radians(m_rotation.y), glm::vec3(0.0, 1.0, 0.0));
	model = glm::rotate(model, glm::radians(m_rotation.z), glm::vec3(0.0, 0.0, 1.0));
	return model;
}

void Transform::SetYawAndPitch(float _yaw, float _pitch)
{
	if (1) //constrain pitch boolean
    {
        if (_pitch > 89.0f)
            _pitch = 89.0f;
        if (_pitch < -89.0f)
            _pitch = -89.0f;
    }
	m_rotation += glm::vec3(_pitch, _yaw, 0);
}

glm::mat4 Transform::GetLookAt()
{
	return glm::lookAt(m_position, m_position + m_front, m_up);
}

glm::vec3 Transform::GetPosition()
{		
	return m_position;	
}

void Transform::UpdatePosition(glm::vec3& _position)
{
	_position = m_localPosition + m_position;
	
	if(!m_parent.expired())
	{
		m_parent.lock()->UpdatePosition(_position);
		m_position = m_localPosition + _position;
	}
}

glm::vec3 Transform::GetLocalPosition()
{
	return m_localPosition;
}

void Transform::SetLocalPosition(glm::vec3 _position)
{
	m_localPosition = _position;
}

void Transform::SetRotation(glm::vec3 _rotation)
{
	m_rotation = _rotation;
}

void Transform::SetPosition(glm::vec3& _position)
{
	m_position = _position;
}

void Transform::ChangePosition(glm::vec3 _position)
{
	m_position += m_front * _position.x;
	m_position += m_up * _position.y;
    m_position += glm::normalize(glm::cross(m_front, m_up)) * _position.z;
}

void Transform::SetParent(std::weak_ptr<Transform> _parent)
{
	m_hasParent = true;
	m_localPosition = m_position - _parent.lock()->m_position;
	m_parent = _parent;
}