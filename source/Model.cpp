#include "Model.h"
#include "Mesh.h"

Model::Model()
{
	
}

Model::~Model()
{
	
}

void Model::MakeCube()
{
	std::shared_ptr<Mesh> m_mesh(new Mesh);
	m_mesh->MakeCube();
	m_meshes.push_back(m_mesh);
}

void Model::MakeSkybox()
{
	std::shared_ptr<Mesh> m_mesh(new Mesh);
	m_mesh->MakeSkybox();
	m_meshes.push_back(m_mesh);
}

void Model::MakeQuad()
{
	std::shared_ptr<Mesh> m_mesh(new Mesh);
	m_mesh->MakeQuad();
	m_meshes.push_back(m_mesh);
}

void Model::MakeTransparent()
{
	std::shared_ptr<Mesh> m_mesh(new Mesh);
	m_mesh->MakeTransparent();
	m_meshes.push_back(m_mesh);
}

void Model::MakePlane()
{
	std::shared_ptr<Mesh> m_mesh(new Mesh);
	m_mesh->MakePlane();
	m_meshes.push_back(m_mesh);
}

void Model::Draw()
{
	for(int i = 0; i < m_meshes.size(); i++)
	{
		m_meshes.at(i)->Draw();
	}
}

void Model::MakeModel(std::string _path)
{
	
}