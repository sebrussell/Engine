#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "Light.h"
#include "Component.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>

class Transform;
class Shader;

class PointLight : public Light
{
	public:
		PointLight();
		~PointLight();
		virtual void Awake();
		virtual void Update();
		void SetLightNumber(int _number) { m_lightNumber = _number; }
	private:
    
		float m_constant;
		float m_linear;
		float m_quadratic;  

		glm::vec3 m_ambient;
		glm::vec3 m_diffuse;
		glm::vec3 m_specular;
		
		std::weak_ptr<Transform> m_transform;

		int m_lightNumber = 0;
};

#endif