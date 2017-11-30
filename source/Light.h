#ifndef LIGHT_H
#define LIGHT_H

#include "Component.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>

class Transform;
class Shader;


struct PointLight {    
    glm::vec3 position;
    
    float constant;
    float linear;
    float quadratic;  

    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
};  

class Light : public Component
{
	public:
		Light();
		~Light();
		virtual void Awake();
		virtual void Update();
		void SetShader(std::weak_ptr<Shader> _shader);
	protected:
		std::weak_ptr<Transform> m_transform;	
		std::weak_ptr<Shader> m_shader;
};

#endif