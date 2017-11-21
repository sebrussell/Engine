#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class SceneManager;

#include "Component.h"

#include <memory>
#include <vector>

class GameObject
{
	public:
		GameObject() {};
		template <typename T>
		std::shared_ptr<T> AddComponent()
		{
			std::shared_ptr<T> _component(new T());
			m_components.push_back(_component);
			_component->m_gameObject = std::make_shared<GameObject>(this);
			
			return _component;		
		}	
		
		/*
		template <typename T>
		std::shared_ptr<T> GetComponent()
		{
			for(int i = 0; i < m_components.size(); i++)
			{
				if(m_components[i]<T> = T)
				{
					return T;
				}
			}			
			return NULL;		
		}	
		*/
		
		void Update();		
		std::weak_ptr<SceneManager> m_sceneManager;
	private:
		std::vector<std::shared_ptr<Component>> m_components;
};

#endif