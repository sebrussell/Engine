#ifndef LIGHTMANAGER_H
#define LIGHTMANAGER_H

#include <vector>
#include <memory>

class SceneManager;
class Shader;
class Light;

class LightManager
{
	public:
		LightManager() {};
		~LightManager() {};
		int Awake();
	private:
		std::weak_ptr<SceneManager> m_sceneManager;

};

#endif
