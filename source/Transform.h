#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Component.h"

class Transform : public Component
{
	public:
		
		glm::mat4 GetLookAt();
		glm::vec3 GetWorldPosition();
		glm::vec3 GetLocalPosition();
		virtual void Update();
	private:
		float m_yaw = -90.0f;
		float m_pitch =  0.0f;
		float m_roll =  0.0f;
		glm::vec3 m_position;
		glm::vec3 m_localPosition;
		glm::vec3 m_front;
		glm::vec3 m_up;
		glm::vec3 m_right;
		glm::vec3 m_worldUp;	
		std::weak_ptr<Transform> m_parent;
};

#endif