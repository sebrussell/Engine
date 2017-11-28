#ifndef SKYBOX_H
#define SKYBOX_H

class Mesh;
class Shader;
class MeshManager;

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
		void Draw();
		unsigned int GetSkyboxTexture() { return m_cubemapTexture; }
	private:
		std::weak_ptr<MeshManager> m_meshManager;
		std::weak_ptr<Shader> m_shader;
		std::weak_ptr<Mesh> m_skyboxMesh;
		std::vector<std::string> m_faces;
		unsigned int m_cubemapTexture;
};

#endif