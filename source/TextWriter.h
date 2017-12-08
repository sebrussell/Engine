#ifndef TEXT_H
#define TEXT_H

#define STB_TRUETYPE_IMPLEMENTATION
#define STBTT_STATIC
#include <stb_truetype.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class GameObject;
class Shader;
class SceneManager;


struct TextQuadCoordinates
{
	float position[3];
	float texCoordinate[2];
};


class Text
{
	public:
		Text();
		~Text();
		void SetSceneManager(std::weak_ptr<SceneManager> _sceneManager);
		void Awake();
		void Write(float x, float y, char *text);
		GLuint GetTexture() { return ftex; }	
		void Draw();
	private:
		unsigned char ttf_buffer[1<<20];
		unsigned char temp_bitmap[512*512];
		stbtt_bakedchar cdata[96]; // ASCII 32..126 is 95 glyphs
		GLuint ftex;
		std::vector<TextQuadCoordinates> m_position;
		std::weak_ptr<Shader> m_shader;
		std::weak_ptr<SceneManager> m_sceneManager;
		void MakeQuad(std::vector<TextQuadCoordinates> m_position, int amount);
		
		//testing
		int m_amountOfVertices;
		unsigned int VAO, VBO, EBO;
};

#endif