#include "Component.h"

void Component::Update() 
{
	
}

Component::~Component()
{
	
}

void Component::SetGameObject(std::weak_ptr<GameObject> _gameObject)
{
	m_gameObject = _gameObject;
}

void Component::Awake() 
{
	
}
