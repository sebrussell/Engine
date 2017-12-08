#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include <iostream>

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

class Mesh
{
	public:
		Mesh();
		~Mesh();
		void MakeCube();
		void MakeSkybox();
		void MakeQuad();
		void MakeTransparent();
		void MakePlane();
		void MakeModel(std::vector<Vertex> _vertices, std::vector<unsigned int> _indices);
		void SetupMesh();
		void Draw();
		void Delete();
		int test = 7;
	private:
		int m_amountOfVertices = 0;
		unsigned int VAO, VBO, EBO;
		
		std::vector<Vertex> m_vertices;
        std::vector<unsigned int> m_indices;
};

#endif