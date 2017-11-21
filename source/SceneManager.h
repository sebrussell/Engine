#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

class OpenGL;
class GameObject;

#include "CameraManager.h"
#include "Skybox.h"

#include <vector>
#include <memory>


class SceneManager
{
	public:
		SceneManager() {};
		~SceneManager() {};
		int Awake();
		void Update();
		std::shared_ptr<CameraManager>  m_cameraManager;
		std::shared_ptr<Skybox> m_skybox;	
		std::shared_ptr<OpenGL> m_openGL;
	private:
		std::vector<std::shared_ptr<GameObject>> m_gameObjects;
};

#endif
