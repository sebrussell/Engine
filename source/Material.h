#ifndef MATERIAL_H
#define MATERIAL_H

#include "Component.h"

class Renderer;
class Lights;

class Material : public Component
{
	public:
		virtual void Update() { m_renderer.Update; }
	private:
		Renderer m_renderer;
	protected:
		std::vector<std::weak_ptr<Lights>> m_lights;
};

#endif MATERIAL_H