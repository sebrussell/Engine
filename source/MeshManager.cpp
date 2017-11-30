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
	std::weak_ptr<Mesh> m_returnMesh;
	switch(_type)
	{
		case CUBE:			
			if(!m_meshes["CUBE"])
			{		
				m_mesh->MakeCube();	
				m_meshes["CUBE"] = m_mesh;				
			}	
			m_returnMesh = m_meshes["CUBE"];
			break;
		case PLANE:
			if(!m_meshes["PLANE"])
			{		
				m_mesh->MakePlane();	
				m_meshes["PLANE"] = m_mesh;				
			}	
			m_returnMesh = m_meshes["PLANE"];
			break;
		case QUAD:
			if(!m_meshes["QUAD"])
			{		
				m_mesh->MakeQuad();	
				m_meshes["QUAD"] = m_mesh;				
			}
			m_returnMesh = m_meshes["QUAD"];
			break;
		case SKYBOX:
			if(!m_meshes["SKYBOX"])
			{		
				m_mesh->MakeSkybox();	
				m_meshes["SKYBOX"] = m_mesh;				
			}
			m_returnMesh = m_meshes["SKYBOX"];
			break;
		case REFLECT_CUBE:
			//m_mesh.MakeReflectCube();
		case MODEL:
			//load MODEL
		case TRANSPARENT_WINDOW:
			if(!m_meshes["WINDOW"])
			{		
				m_mesh->MakeTransparent();	
				m_meshes["WINDOW"] = m_mesh;				
			}
			m_returnMesh = m_meshes["WINDOW"];
			break;
		default:
			break;			
	}
	return m_returnMesh;
}


