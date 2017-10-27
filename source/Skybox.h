#ifndef SKYBOX_H
#define SKYBOX_H

#include "OpenGL.h"
#include "Model.h"

#include <memory>


class Skybox
{
	public:
		Skybox();
		~Skybox() {};
		unsigned int loadCubemap();
		void Draw(Shader shader);
		unsigned int GetSkyboxTexture() { return cubemapTexture; }
	private:
		std::shared_ptr<Model> skybox;
		std::vector<std::string> faces;
		unsigned int cubemapTexture;
};

#endif