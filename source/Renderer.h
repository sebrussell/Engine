#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <memory>

#include "Component.h"
#include "Shader.h"

class Renderer : public Component
{
	public:
		//Renderer();
		//~Renderer();
		virtual void Update() { std::cout << "I am rendered" << std::endl; }
		//void SetShader(Shader _shader) { m_shader = _shader };
	private:
		//Shader m_shader;
};

#endif 