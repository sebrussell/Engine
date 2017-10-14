#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class Component;

class GameObject
{
	public:	
		void AddComponent(Component _component) { m_components->push_back(std::make_shared<Component>(_component));		
		
	private:
		std::vector<std::shared_ptr<Component>> m_components;
};

#endif