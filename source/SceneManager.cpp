#include "SceneManager.h"
#include "OpenGL.h"
#include "CameraManager.h"
#include "Skybox.h"
#include "GameObject.h"
#include "ShaderManager.h"
#include "MeshManager.h"
#include "Camera.h"

int SceneManager::Awake()
{
	m_openGL = std::make_shared<OpenGL>();
	m_openGL->Setup(800, 600);
	

	m_maxViewDistance = 500.0f;
	m_minViewDistance = 0.1f;
		
	m_cameraManager = std::make_shared<CameraManager>();	
	m_cameraManager->SetSceneManager(shared_from_this());
	m_cameraManager->Awake();

	
	m_meshManager = std::make_shared<MeshManager>();
	
	m_shaderManager = std::make_shared<ShaderManager>();
	m_shaderManager->Awake();

	m_skybox  = std::make_shared<Skybox>();
	m_skybox->SetMeshManager(m_meshManager);
	m_skybox->Awake();
	m_skybox->SetShader(m_shaderManager->AddShader("..//source/shaders/skyboxShader.vs", "..//source/shaders/skyboxShader.fs"));

	
	for(int i = 0; i < m_gameObjects.size(); i++)
	{		
		m_gameObjects.at(i)->Awake();
	}
	
	m_cameraManager->SetupPostProcessing();

	return 0;
}

std::weak_ptr<GameObject> SceneManager::CreateGameObject()
{
	std::shared_ptr<GameObject> gameObject(new GameObject);
	gameObject->m_sceneManager = shared_from_this();
	m_gameObjects.push_back(gameObject);
	return gameObject;
}

void SceneManager::Update()
{
	m_cameraManager->PostProcessingCall1();
	
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		if(m_gameObjects.at(i)->m_shouldUpdate)
		{
			m_gameObjects.at(i)->Update();
		}		
	}
	
	m_skybox->Draw();
	
	m_cameraManager->TransparentCall();

	//draw instanced gameobjects

	//draw transparent gameobjects
	
	
	
	//draw cameras for mirrors
	//post processing
	//enable main camera
	m_cameraManager->PostProcessingCall2();
	
}

void SceneManager::Delete()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects.at(i)->Delete();
	}
	glfwTerminate();
}

