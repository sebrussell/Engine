#ifndef LIGHTMANAGER_H
#define LIGHTMANAGER_H

#include <vector>
#include <memory>

class SceneManager;
class Shader;
class PointLight;
class DirectionalLight;
class Component;
class GameObject;

class LightManager
{
	public:
		LightManager() {};
		~LightManager() {};
		int Awake();
		void AddPointLight(std::weak_ptr<GameObject> _light);
		void SetDirectionalLight(std::weak_ptr<GameObject> _light);
	private:
		std::weak_ptr<SceneManager> m_sceneManager;
		std::vector<std::weak_ptr<PointLight>> m_pointLights;		
		std::weak_ptr<DirectionalLight> m_directionalLight;
		const int m_maxSpotLight = 2;
};

#endif
