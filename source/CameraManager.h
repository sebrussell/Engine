#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include <vector>
#include <memory>

class Camera;

class CameraManager
{
	public:
		CameraManager() {};
		~CameraManager() {};
		int Awake();
		void PostProcessing();
		void SetMainCamera(std::weak_ptr<Camera> _camera) { m_mainCamera = _camera; }
		void SetActiveCamera(std::weak_ptr<Camera> _camera) { m_activeCamera = _camera; }
		std::weak_ptr<Camera> m_activeCamera;
	private:
		std::vector<std::shared_ptr<Camera>> m_cameras;
		std::weak_ptr<Camera> m_mainCamera;
};

#endif
