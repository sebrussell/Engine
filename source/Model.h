#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <memory>
#include <string>

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
		std::vector<std::shared_ptr<Mesh>> m_meshes;
};

#endif