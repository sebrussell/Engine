#ifndef MESH_H
#define MESH_H

#include <vector>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Shader.h"


struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
	glm::vec3 Tangent;
    glm::vec3 Bitangent;
};

struct Texture {
    unsigned int id;
    std::string type;
	aiString path;
};  

class Mesh {
    public:
	    /*  Functions  */
		Mesh() {};
        Mesh(std::vector<Vertex> _vertices, std::vector<unsigned int> _indices, std::vector<Texture> _textures);
		~Mesh();
        void Draw(Shader shader);
		void MakeCube();
		void MakePlane();
        /*  Mesh Data  */
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;
		
	

    private:
        /*  Render data  */
        unsigned int VAO, VBO, EBO;
		int m_amountOfVertices;
        /*  Functions    */
        void setupMesh();
};  

#endif




