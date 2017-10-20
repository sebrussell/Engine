#include "GameObject.h"

void GameObject::Update()
{
	for(int i = 0; i < m_components.size(); i++)
	{
		m_components.at(i)->Update();
	}
}