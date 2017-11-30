#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class SceneManager;
class Transform;
class Renderer;

#include "Component.h"

#include <memory>
#include <vector>
#include <iostream>

class GameObject : public std::enable_shared_from_this<GameObject>
{
	public:
		GameObject();
		~GameObject();
		template <typename T>
		std::shared_ptr<T> AddComponent()
		{
			std::shared_ptr<T> _component(new T());
			m_transform = std::dynamic_pointer_cast<Transform>(_component);
			_component->m_gameObject = shared_from_this();
			m_components.push_back(_component);			
			return _component;		
		}	
		
		
		template<class T>
		std::shared_ptr<T> GetComponent()
		{			
			for(int i = 0; i < m_components.size(); i++)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(m_components.at(i));
				if(rtn)
				{
					return rtn;
				}
			}
			return std::shared_ptr<T>();
		}
		  
		void Awake();
		void Update();	
		void Delete();
		std::weak_ptr<SceneManager> m_sceneManager;
		bool m_shouldUpdate = true;
		bool m_transparent = false;
		std::shared_ptr<Transform> m_transform;
		std::shared_ptr<Renderer> m_renderer;
	private:
		std::vector<std::shared_ptr<Component>> m_components;
};

#endif