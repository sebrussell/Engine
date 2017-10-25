#ifndef SKYBOX_H
#define SKYBOX_H

#include "Model.h"
#include "OpenGL.h"

class Skybox
{
	public:
		Skybox();
		~Skybox() {};
		unsigned int loadCubemap();
	private:
		Model skybox;
		std::vector<std::string> faces;
		unsigned int cubemapTexture;
};

#endif