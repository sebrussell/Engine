#include "Light.h"

Light::Light()
{
	
}

Light::~Light()
{

}

void Light::SetShader(std::weak_ptr<Shader> _shader)
{
	m_shader = _shader;
}

void Light::Update()
{
	
}

void Light::Awake()
{
	
}