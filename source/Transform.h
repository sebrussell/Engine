#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Component.h"

class Transform : public Component
{
	public:
		glm::mat4 GetModelMatrix();
		glm::mat4 GetLookAt();
		glm::vec3 GetPosition();
		glm::vec3 GetLocalPosition();
		void ChangePosition(glm::vec3 _position);
		void SetLocalPosition(glm::vec3 _position);
		void SetParent(std::weak_ptr<Transform> _parent);
		virtual void Update();
		virtual void Awake();
		glm::vec3 m_position;
		void SetYawAndPitch(float _yaw, float _pitch);
	private:		
		float m_pitch =  0.0f;
		float m_roll =  0.0f;
		float m_yaw = -90.0f;
		
		glm::vec3 m_localPosition;
		glm::vec3 m_front;
		glm::vec3 m_up;
		glm::vec3 m_right;
		glm::vec3 m_worldUp;	
		std::weak_ptr<Transform> m_parent;
};

#endif