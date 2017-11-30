#include "DirectionalLight.h"
#include "Shader.h"

DirectionalLight::DirectionalLight()
{
	m_direction = glm::vec3(-0.2f, -1.0f, -0.3f);
	m_ambient = glm::vec3(0.05f, 0.05f, 0.05f);
	m_specular = glm::vec3(0.5f, 0.5f, 0.5f);
	m_diffuse = glm::vec3(0.4f, 0.4f, 0.4f);
}

DirectionalLight::DirectionalLight(glm::vec3 _direction, glm::vec3 _ambient, glm::vec3 _diffuse, glm::vec3 _specular)
{
	m_direction = _direction;
	m_ambient = _ambient;
	m_specular = _specular;
	m_diffuse = _diffuse;
}

DirectionalLight::~DirectionalLight()
{
};

void DirectionalLight::Update()
{
	m_shader.lock()->Use();
	m_shader.lock()->SetVec3("dirLight.direction", m_direction);
	m_shader.lock()->SetVec3("dirLight.ambient", m_ambient);
	m_shader.lock()->SetVec3("dirLight.specular", m_specular);
	m_shader.lock()->SetVec3("dirLight.diffuse", m_diffuse);
}
