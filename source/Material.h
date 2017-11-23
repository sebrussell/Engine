#ifndef MATERIAL_H
#define MATERIAL_H

#include "Component.h"
#include <memory>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Renderer;

struct Texture {
	Texture() {};
	//Texture(unsigned int _id, std::string _type, aiString _path) { id = _id, type = _type, path = _path; }
    unsigned int id;
    std::string type;
	//aiString path;
};  

class Material : public Component
{
	public:
		Material() {};
		~Material() {};
		virtual void Awake();
		virtual void Update();
	private:
		glm::vec3 m_colour;
		std::vector<Texture> m_textures;
		std::weak_ptr<Renderer> m_renderer;
};

#endif 