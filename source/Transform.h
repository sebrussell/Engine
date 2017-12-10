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
		glm::vec3 GetTransformFront() { return m_front; }
		glm::vec3 GetRotation() { return m_rotation; }
		void ChangePosition(glm::vec3 _position);
		void SetLocalPosition(glm::vec3 _position);
		void SetParent(std::weak_ptr<Transform> _parent);
		void UpdatePosition(glm::vec3& _position);
		void SetPosition(glm::vec3& _position);
		void SetRotation(glm::vec3 _rotation);
		virtual void Update();
		virtual void Awake();
		glm::vec3 m_position;
		void SetYawAndPitch(float _yaw, float _pitch);
	private:		
		glm::vec3 m_rotation;
		
		glm::vec3 m_localPosition;
		glm::vec3 m_front;
		glm::vec3 m_up;
		glm::vec3 m_right;
		glm::vec3 m_worldUp;	
		std::weak_ptr<Transform> m_parent;
		bool m_hasParent;
};

#endif