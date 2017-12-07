#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <vector>
#include <memory>
#include <map>

class CameraManager;
class Skybox;
class OpenGL;
class GameObject;
class ShaderManager;
class MeshManager;
class Input;
class Text;
class LightManager;




class SceneManager : public std::enable_shared_from_this<SceneManager>
{
	public:
		SceneManager() {};
		~SceneManager() {};
		int Awake();
		void Update();
		void Delete();
		std::weak_ptr<GameObject> CreateGameObject();
		std::shared_ptr<CameraManager>  m_cameraManager;
		std::shared_ptr<Skybox> m_skybox;	
		std::shared_ptr<OpenGL> m_openGL;
		std::shared_ptr<MeshManager> m_meshManager;
		std::shared_ptr<ShaderManager> m_shaderManager;
		std::shared_ptr<Text> m_textWriter;
		std::shared_ptr<Input> m_input;
		std::shared_ptr<LightManager> m_lightManager;
		float m_maxViewDistance, m_minViewDistance;
	private:
		std::vector<std::shared_ptr<GameObject>> m_gameObjects;	
		std::map<float, std::weak_ptr<GameObject>> m_sorted;		
};

#endif
