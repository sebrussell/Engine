#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

class CameraManager;
class Skybox;
class OpenGL;
class GameObject;

#include <vector>
#include <memory>


class SceneManager
{
	public:
		SceneManager() {};
		~SceneManager() {};
		int Awake();
		void Update();
		std::weak_ptr<GameObject> CreateGameOject();
		std::shared_ptr<CameraManager>  m_cameraManager;
		std::shared_ptr<Skybox> m_skybox;	
		std::shared_ptr<OpenGL> m_openGL;
	private:
		std::vector<std::shared_ptr<GameObject>> m_gameObjects;
};

#endif
