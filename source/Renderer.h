#ifndef RENDERER_H
#define RENDERER_H

#include "Component.h"

class Shader;

class Renderer : public Component
{
	public:
		virtual void Update();
		void SetShader(Shader _shader) { m_shader = _shader };
	private:
		Shader m_shader;
};

#endif RENDERER_H