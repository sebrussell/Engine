#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>



class Mesh
{
	public:
		Mesh();
		~Mesh();
		void MakeCube();
		void MakeSkybox();
		void MakeQuad();
		void MakeTransparent();
		void Draw();
		void Delete();
		int test = 7;
	private:
		int m_amountOfVertices;
		unsigned int VAO, VBO, EBO;
};

#endif