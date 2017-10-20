#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Component.h"

class GameObject
{
	public:
		template <typename T>
		std::shared_ptr<T> AddComponent()
		{
			std::shared_ptr<T> _component(new T());
			m_components.push_back(_component);
			//_component->gameObject = this;
			
			return _component;
		
		}	
		void Update();
	private:
		std::vector<std::shared_ptr<Component>> m_components;
};

#endif