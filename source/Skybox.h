#ifndef SKYBOX_H
#define SKYBOX_H

class Model;
class Shader;
class MeshManager;
class Transform;

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "stb_image.h"

#include <memory>
#include <vector>
#include <iostream>

class Skybox
{
	public:
		Skybox() {};
		~Skybox() {};
		void Awake();
		unsigned int loadCubemap();
		void SetShader(std::weak_ptr<Shader> _shader);
		void SetMeshManager(std::weak_ptr<MeshManager> _manager);
		void SetCameraTransform(std::weak_ptr<Transform> _transform);
		void Draw();
		unsigned int GetSkyboxTexture() { return m_cubemapTexture; }
		
	private:
		std::weak_ptr<MeshManager> m_meshManager;
		std::weak_ptr<Shader> m_shader;
		std::weak_ptr<Model> m_skyboxMesh;
		std::vector<std::string> m_faces;
		unsigned int m_cubemapTexture;
		std::weak_ptr<Transform> m_cameraTransform;
};

#endif