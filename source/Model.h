#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <memory>
#include <string>
#include <iostream>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

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
		void Draw();
	private:
		void ProcessNode(aiNode *node, const aiScene *scene);
		std::shared_ptr<Mesh> ProcessMesh(aiMesh *mesh, const aiScene *scene);
		std::vector<std::shared_ptr<Mesh>> m_meshes;
};

#endif