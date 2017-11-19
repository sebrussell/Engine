#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include <vector>
#include <memory>

#include "Camera.h"

class CameraManager
{
	public:
		CameraManager() {};
		~CameraManager() {};
		int Awake();
		int Update();
		void PostProcessing();
		std::shared_ptr<Camera> m_activeCamera;
	private:
		std::vector<std::shared_ptr<Camera>> m_cameras;
};

#endif
