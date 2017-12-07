#ifndef TEXT_H
#define TEXT_H

#define STB_TRUETYPE_IMPLEMENTATION
#define STBTT_STATIC
#include <stb_truetype.h>
#include <iostream>
#include <stdio.h>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class GameObject;

struct TextQuadCoordinates
{
	glm::vec3 position, texCoordinate;
};


class Text
{
	public:
		Text();
		~Text();
		void Awake();
		void Write(float x, float y, char *text);
	
	private:
		unsigned char ttf_buffer[1<<20];
		unsigned char temp_bitmap[512*512];
		stbtt_bakedchar cdata[96]; // ASCII 32..126 is 95 glyphs
		GLuint ftex;
		std::vector<TextQuadCoordinates> m_position;
};

#endif