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

enum TextureType{
	Texture2D,
	CubeMap,
};

struct Texture {
	Texture() {};
    unsigned int m_id;
	TextureType m_type;
};  

class Material
{
	public:
		Material() {};
		~Material() {};
		void Apply();
		void LoadTexture(char const * _path, TextureType _type = Texture2D);
		void LoadTexture(unsigned int _id, TextureType _type = Texture2D);
		void SetTexture(unsigned int _id);
	private:
		glm::vec3 m_colour = glm::vec3(1.0f, 0.0f, 0.0f);
		std::vector<Texture> m_textures;
		std::weak_ptr<Renderer> m_renderer;
};

#endif 