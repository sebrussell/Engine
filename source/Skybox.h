#ifndef SKYBOX_H
#define SKYBOX_H

class Model;
class Shader;

#include <glad/glad.h>
#include <GLFW/glfw3.h>
//#include "stb_image.h"

#include <memory>
#include <vector>
#include <iostream>

class Skybox
{
	public:
		Skybox();
		~Skybox() {};
		unsigned int loadCubemap();
		void Draw(std::shared_ptr<Shader> shader);
		unsigned int GetSkyboxTexture() { return cubemapTexture; }
	private:
		std::shared_ptr<Model> skybox;
		std::vector<std::string> faces;
		unsigned int cubemapTexture;
};

#endif