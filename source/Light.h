#ifndef LIGHT_H
#define LIGHT_H

#include "Component.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>

class Transform;
class Shader;

class Light : public Component
{
	public:
		Light();
		~Light();
		virtual void Awake();
		virtual void Update();
		void SetShader(std::weak_ptr<Shader> _shader);
		std::weak_ptr<Shader> GetShader();
	protected:
		std::weak_ptr<Transform> m_transform;	
		std::weak_ptr<Shader> m_shader;
		
};

#endif