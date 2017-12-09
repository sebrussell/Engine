#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <memory>
#include <string>
#include <iostream>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Mesh;

class Model
{
	public:
		Model();
		~Model();
		void MakeCube();
		void MakeSkybox();
		void MakeQuad();
		void MakeTransparent();
		void MakePlane();
		void MakeModel(std::string _path);
		glm::vec3 GetModelDimensions();
		void Draw();
	private:
		void CalculateDimensions();
		void ProcessNode(aiNode *node, const aiScene *scene);
		std::shared_ptr<Mesh> ProcessMesh(aiMesh *mesh, const aiScene *scene);
		std::vector<std::shared_ptr<Mesh>> m_meshes;
		glm::vec3 m_dimensions;
};

#endif