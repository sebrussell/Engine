#include "PointLight.h"
#include "Shader.h"
#include "GameObject.h"
#include "Transform.h"
#include "SceneManager.h"
#include "LightManager.h"

PointLight::PointLight()
{
	
}

PointLight::~PointLight()
{

}

void PointLight::Update()
{	
	m_shader.lock()->Use();
	
	std::string def = std::string("pointLights[" + std::to_string(m_lightNumber));
	
	std::string input = def + "].position";
	m_shader.lock()->SetVec3(input, m_transform.lock()->m_position);
	
	input = def + "].constant";
	m_shader.lock()->SetFloat(input, m_constant);
	
	input = def + "].linear";
	m_shader.lock()->SetFloat(input, m_linear);
	
	input = def + "].quadratic";
	m_shader.lock()->SetFloat(input, m_quadratic);
	
	input = def + "].ambient";
	m_shader.lock()->SetVec3(input, m_ambient);
	
	input = def + "].diffuse";
	m_shader.lock()->SetVec3(input, m_diffuse);
	
	input = def + "].specular";
	m_shader.lock()->SetVec3(input, m_specular);

}

void PointLight::Awake()
{
	m_gameObject.lock()->m_sceneManager.lock()->m_lightManager->AddPointLight(m_gameObject);	
	
	m_transform = m_gameObject.lock()->GetComponent<Transform>();
	if(m_transform.expired())
	{
		m_transform = m_gameObject.lock()->AddComponent<Transform>();
	}

    m_ambient = glm::vec3(0.05f, 0.05f, 0.05f);
    m_diffuse = glm::vec3(0.8f, 0.8f, 0.8f);
    m_specular = glm::vec3(1.0f, 1.0f, 1.0f);
    m_constant = 1.0f;
    m_linear = 0.09;
    m_quadratic = 0.032;
}