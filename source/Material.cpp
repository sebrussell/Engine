#include "Material.h"
#include "Renderer.h"
#include "stb_image.h"
#include "Shader.h"

void Material::Apply()
{
	for(int i = 0; i < m_textures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		if(m_textures.at(i).m_type == Texture2D)
		{
			glBindTexture(GL_TEXTURE_2D, m_textures.at(i).m_id);
		}
		if(m_textures.at(i).m_type == CubeMap)
		{
			glBindTexture(GL_TEXTURE_CUBE_MAP, m_textures.at(i).m_id);
		}		
	}

	//glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, m_textures.at(0).id);
	
	//glActiveTexture(GL_TEXTURE1);
	//glBindTexture(GL_TEXTURE_2D, m_textures.at(1).id);

	if(m_textures.size() == 0)
	{
		m_shader.lock()->SetBool("useColour", true);
		m_shader.lock()->SetVec3("objectColour", m_colour);
		m_shader.lock()->SetVec3("lightColour", glm::vec3(1.0f, 1.0f, 1.0f));
		//m_shader.lock()->SetVec3("lightPos", glm::vec3(0.0f, 0.0f, -2.0f));
		m_shader.lock()->SetVec3("viewPos", glm::vec3(0.0f, 0.0f, 0.0f));
		//set colour
	}
	
}

void Material::SetColour(glm::vec3 _colour)
{
	m_colour = _colour;
}

void Material::SetShader(std::weak_ptr<Shader> _shader)
{
	m_shader = _shader;
}

void Material::LoadTexture(char const * _path, TextureType _type)
{
	Texture texture;
    glGenTextures(1, &texture.m_id);

    int width, height, nrComponents;
    unsigned char *data = stbi_load(_path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, texture.m_id);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT); // for this tutorial: use GL_CLAMP_TO_EDGE to prevent semi-transparent borders. Due to interpolation it takes texels from next repeat 
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << _path << std::endl;
        stbi_image_free(data);
    }	

	texture.m_type = _type;
	m_textures.push_back(texture);
}

void Material::LoadTexture(unsigned int _id, TextureType _type)
{
	Texture texture;
	texture.m_id = _id;
	texture.m_type = _type;
	m_textures.push_back(texture);
}

void Material::SetTexture(unsigned int _id)
{
	if(m_textures.size() > 0)
	{
		m_textures.at(0).m_id = _id;
	}
	else{
		LoadTexture(_id, Texture2D);
	}
}