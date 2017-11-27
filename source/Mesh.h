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
		void Draw();
		void Delete();
	private:
		int m_amountOfVertices;
		unsigned int VAO, VBO, EBO;
};

#endif