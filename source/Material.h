#ifndef MATERIAL_H
#define MATERIAL_H

#include <memory>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Renderer;

struct Texture {
	Texture() {};
	//Texture(unsigned int _id, std::string _type, aiString _path) { id = _id, type = _type, path = _path; }
    unsigned int id;
    std::string type;
	//aiString path;
};  

class Material
{
	public:
		Material() {};
		~Material() {};
		void Apply();
		void LoadTexture(char const * _path, std::string _type);
	private:
		glm::vec3 m_colour = glm::vec3(1.0f, 0.0f, 0.0f);
		std::vector<Texture> m_textures;
		std::weak_ptr<Renderer> m_renderer;
};

#endif 