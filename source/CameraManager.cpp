#include "CameraManager.h"

int CameraManager::Awake()
{

	
	return 0;	
}

void CameraManager::SetMainCamera(std::weak_ptr<Camera> _camera) { 

	m_mainCamera = _camera; 

}

void CameraManager::SetActiveCamera(std::weak_ptr<Camera> _camera) 
{ 
	m_activeCamera = _camera; 
}
