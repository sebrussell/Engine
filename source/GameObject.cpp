#include "GameObject.h"

GameObject::GameObject()
{
	
}
		
GameObject::~GameObject()
{
}

void GameObject::Awake()
{
	for(int i = 0; i < m_components.size(); i++)
	{
		m_components.at(i)->Awake();
	}
}

void GameObject::Update()
{
	for(int i = 0; i < m_components.size(); i++)
	{
		m_components.at(i)->Update();
	}
}

void GameObject::Delete()
{
	for(int i = 0; i < m_components.size(); i++)
	{
		m_components.at(i)->Delete();
	}
}
