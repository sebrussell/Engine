#include "SceneManager.h"
#include "MeshManager.h"
#include "Mesh.h"

int MeshManager::Awake()
{	
	return 0;	
}

void MeshManager::SetSceneManager(std::weak_ptr<SceneManager> _sceneManager)
{
	m_sceneManager = _sceneManager;
}

std::weak_ptr<Mesh> MeshManager::AddMesh(Type _type, std::string _path)
{
	std::shared_ptr<Mesh> m_mesh(new Mesh);
	switch(_type)
	{
		case CUBE:			
			m_mesh->MakeCube();
			m_meshes.push_back(m_mesh);
			break;
		case PLANE:
			//m_mesh.MakePlane();
			break;
		case QUAD:
			m_mesh->MakeQuad();
			m_meshes.push_back(m_mesh);
			break;
		case SKYBOX:
			m_mesh->MakeSkybox();
			m_meshes.push_back(m_mesh);
			break;
		case REFLECT_CUBE:
			//m_mesh.MakeReflectCube();
		case MODEL:
			//load MODEL
		case TRANSPARENT_WINDOW:
			m_mesh->MakeTransparent();
			m_meshes.push_back(m_mesh);
			break;
		default:
			break;			
	}
	
	return m_mesh;
}


