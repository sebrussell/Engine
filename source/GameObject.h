#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class SceneManager;

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
			m_components.push_back(_component);
			_component->SetGameObject(shared_from_this());
			
			return _component;		
		}	
		
		
		template<class T>
		std::shared_ptr<T> GetComponent()
		{			
			for(int i = 0; i < m_components.size(); i++)
			{
				//std::shared_ptr<T> t = std::dynamic_pointer_cast<T>(m_components.at(i));
				if(typeid(m_components.at(i)).name() == typeid(T).name())
				{
					std::cout << typeid(T).name() << std::endl;
				}
				
			}
			return std::shared_ptr<T>();
		}
		  
		void Awake();
		void Update();		
		std::weak_ptr<SceneManager> m_sceneManager;
		int i;
	private:
		std::vector<std::shared_ptr<Component>> m_components;
};

#endif