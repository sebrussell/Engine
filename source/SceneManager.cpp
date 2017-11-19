#include "SceneManager.h"

int SceneManager::Awake()
{
	std::shared_ptr<CameraManager> cameraManager(new CameraManager);
	m_cameraManager = cameraManager;
	m_cameraManager->Awake();
	
	std::shared_ptr<Skybox> skybox(new Skybox);
	return 0;
}

