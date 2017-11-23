#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <memory>
#include <string>

#include "Component.h"

class Shader;
class Mesh;
class Camera;
class Material;
class Transform;

enum Type
{
	CUBE,
	PLANE,
	QUAD,
	SKYBOX,
	REFLECT_CUBE,
	MODEL
};

class Renderer : public Component
{
	public:
		Renderer();
		~Renderer();
		virtual void Awake();
		virtual void Update();
		void SetShader(std::weak_ptr<Shader> _shader);
		void SetMesh(Type _type, std::string _path = "");
	private:		
		std::weak_ptr<Shader> m_shader;
		std::shared_ptr<Mesh> m_mesh;
		std::shared_ptr<Material> m_material;
		std::weak_ptr<Camera> m_activeCamera;
		std::weak_ptr<Transform> m_transform;
};

#endif 