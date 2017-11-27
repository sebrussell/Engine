#include "SceneManager.h"
#include "OpenGL.h"
#include "CameraManager.h"
#include "Skybox.h"
#include "GameObject.h"
#include "ShaderManager.h"

int SceneManager::Awake()
{
	std::shared_ptr<OpenGL> openGL(new OpenGL);
	m_openGL = openGL;
	m_openGL->Setup(800, 600);
	

	m_maxViewDistance = 500.0f;
	m_minViewDistance = 0.1f;
		
	std::shared_ptr<CameraManager> cameraManager(new CameraManager);
	m_cameraManager = cameraManager;
	m_cameraManager->Awake();
	
	m_shaderManager = std::make_shared<ShaderManager>();
	m_shaderManager->Awake();
	
	std::shared_ptr<Skybox> skybox(new Skybox);
	
	
	
	for(int i = 0; i < m_gameObjects.size(); i++)
	{		
		m_gameObjects.at(i)->Awake();
	}
	
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
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects.at(i)->Update();
	}
	//enable main camera
	//draw instanced gameobjects
	//draw gameobjects
	//draw transparent gameobjects
	//skybox
	//draw cameras for mirrors
	//post processing
}

void SceneManager::Delete()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects.at(i)->Update();
	}
	glfwTerminate();
}

