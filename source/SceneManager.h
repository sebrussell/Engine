#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "OpenGL.h"

#include <vector>
#include <memory>

#include "CameraManager.h"
#include "Skybox.h"
#include "GameObject.h"

class SceneManager
{
	public:
		SceneManager() {};
		~SceneManager() {};
		int Awake();
		void Update();
		std::shared_ptr<CameraManager> m_cameraManager;
		std::shared_ptr<Skybox> m_skybox;		
	private:
		std::vector<std::shared_ptr<GameObject>> m_gameObjects;
};

#endif
