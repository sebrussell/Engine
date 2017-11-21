#include "SceneManager.h"

int SceneManager::Awake()
{
	std::shared_ptr<CameraManager> cameraManager(new CameraManager);
	m_cameraManager = cameraManager;
	m_cameraManager->Awake();
	
	std::shared_ptr<Skybox> skybox(new Skybox);
	return 0;
}

void SceneManager::Update()
{
	//enable main camera
	//draw gameobjects
	//draw transparent gameobjects
	//skybox
	//draw cameras for mirrors
	//post processing
}

