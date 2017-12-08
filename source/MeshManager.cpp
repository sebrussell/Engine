#include "SceneManager.h"
#include "MeshManager.h"
#include "Mesh.h"
#include "Model.h"

int MeshManager::Awake()
{	
	return 0;	
}

void MeshManager::SetSceneManager(std::weak_ptr<SceneManager> _sceneManager)
{
	m_sceneManager = _sceneManager;
}

std::weak_ptr<Model> MeshManager::AddModel(Type _type, std::string _path)
{
	std::shared_ptr<Model> m_model(new Model);
	std::weak_ptr<Model> m_returnModel;
	switch(_type)
	{
		case CUBE:			
			if(!m_models["CUBE"])
			{		
				m_model->MakeCube();	
				m_models["CUBE"] = m_model;				
			}	
			m_returnModel = m_models["CUBE"];
			break;
		case PLANE:
			if(!m_models["PLANE"])
			{		
				m_model->MakePlane();	
				m_models["PLANE"] = m_model;				
			}	
			m_returnModel = m_models["PLANE"];
			break;
		case QUAD:
			if(!m_models["QUAD"])
			{		
				m_model->MakeQuad();	
				m_models["QUAD"] = m_model;				
			}
			m_returnModel = m_models["QUAD"];
			break;
		case SKYBOX:
			if(!m_models["SKYBOX"])
			{		
				m_model->MakeSkybox();	
				m_models["SKYBOX"] = m_model;				
			}
			m_returnModel = m_models["SKYBOX"];
			break;
		case REFLECT_CUBE:
			//m_mesh.MakeReflectCube();
		case MODEL:
			if(!m_models[_path])
			{		
				m_model->MakeModel(_path);	
				m_models[_path] = m_model;				
			}
			m_returnModel = m_models[_path];
		case TRANSPARENT_WINDOW:
			if(!m_models["WINDOW"])
			{		
				m_model->MakeTransparent();	
				m_models["WINDOW"] = m_model;				
			}
			m_returnModel = m_models["WINDOW"];
			break;
		default:
			break;			
	}
	return m_returnModel;
}


