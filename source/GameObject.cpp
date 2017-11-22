#include "GameObject.h"

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

