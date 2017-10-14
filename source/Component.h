#ifndef COMPONENT_H
#define COMPONENT_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include <memory>

class Shader;

class Component
{
	public:	
		virtual void Update();
};

#endif