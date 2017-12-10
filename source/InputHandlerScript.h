#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Component.h"

class Input;
class Transform;
class Rigidbody;

class InputHandler : public Component
{
	public:
		virtual void Update();
		virtual void Awake();
	private:	
		std::weak_ptr<Transform> m_transform;
		std::weak_ptr<Input> m_input;
		std::weak_ptr<Rigidbody> m_body;
		float m_mouseSensitivty = 0.1f;
		float m_speed = 0.1f;
		double m_mouseXOffset, m_mouseYOffset;
		bool m_useBody;
};

#endif