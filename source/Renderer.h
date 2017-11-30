#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <memory>
#include <string>

#include "Component.h"
#include "MeshManager.h"

class Shader;
class Mesh;
class Camera;
class Material;
class Transform;


class Renderer : public Component
{
	public:
		Renderer();
		~Renderer();
		virtual void Awake();
		virtual void Update();
		virtual void Delete();
		void SetShader(std::weak_ptr<Shader> _shader);
		void SetMesh(Type _type, std::string _path = "");
		void SetMeshManager(std::weak_ptr<MeshManager> _manager);
		void SetActiveCamera(std::weak_ptr<Camera> _camera);
		std::shared_ptr<Material> m_material;
		std::weak_ptr<Shader> GetShader();
		std::weak_ptr<Shader> m_shader;
		std::weak_ptr<Mesh> m_mesh;	
	private:		
		std::weak_ptr<MeshManager> m_meshManager;
			
		std::weak_ptr<Camera> m_activeCamera;
		std::weak_ptr<Transform> m_transform;
};

#endif 