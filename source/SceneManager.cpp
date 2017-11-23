#include "SceneManager.h"
#include "OpenGL.h"
#include "CameraManager.h"
#include "Skybox.h"
#include "GameObject.h"

int SceneManager::Awake()
{
	std::shared_ptr<OpenGL> openGL(new OpenGL);
	openGL->Setup(800, 600);
	
	std::shared_ptr<CameraManager> cameraManager(new CameraManager);
	m_cameraManager = cameraManager;
	m_cameraManager->Awake();
	
	std::shared_ptr<Skybox> skybox(new Skybox);
	return 0;
}

std::weak_ptr<GameObject> SceneManager::CreateGameOject()
{
	std::shared_ptr<GameObject> gameObject(new GameObject);
	m_gameObjects.push_back(gameObject);
	return gameObject;
}

void SceneManager::Update()
{
	//enable main camera
	//draw instanced gameobjects
	//draw gameobjects
	//draw transparent gameobjects
	//skybox
	//draw cameras for mirrors
	//post processing
}

