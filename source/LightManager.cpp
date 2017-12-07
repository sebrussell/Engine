#include "LightManager.h"
#include "PointLight.h"
#include "DirectionalLight.h"
#include "GameObject.h"


int LightManager::Awake()
{
	return 0;	
}

void LightManager::AddPointLight(std::weak_ptr<GameObject> _light)
{
	if(m_pointLights.size() < m_maxSpotLight)
	{
		_light.lock()->GetComponent<PointLight>()->SetLightNumber(m_pointLights.size());
		m_pointLights.push_back(_light.lock()->GetComponent<PointLight>());
		
	}
}

void LightManager::SetDirectionalLight(std::weak_ptr<GameObject> _light)
{
	m_directionalLight = _light.lock()->GetComponent<DirectionalLight>();
}

