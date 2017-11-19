#include "CameraManager.h"

int CameraManager::Awake()
{
	std::shared_ptr<Camera> cameraMain(new Camera);
	m_cameras.push_back(cameraMain);
	m_activeCamera = cameraMain;
	
	
	return 0;	
}