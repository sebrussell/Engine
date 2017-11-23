#ifndef COMPONENT_H
#define COMPONENT_H

class GameObject;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include <memory>

class Component
{
	public:	
		//Component();
		virtual ~Component();
		virtual void Update();
		virtual void Awake();
		void SetGameObject(std::weak_ptr<GameObject> _gameObject);
	protected:
		std::weak_ptr<GameObject> m_gameObject;
	
};

#endif