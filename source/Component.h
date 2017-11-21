#ifndef COMPONENT_H
#define COMPONENT_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include <memory>

class GameObject;

class Component
{
	public:	
		//Component();
		virtual ~Component() {};
		virtual void Update() {};
		std::weak_ptr<GameObject> m_gameObject;
};

#endif