#ifndef MESHMANAGER_H
#define MESHMANAGER_H

#include <vector>
#include <memory>
#include <map>
#include <string>

class SceneManager;
class Model;

enum Type
{
	CUBE,
	PLANE,
	QUAD,
	SKYBOX,
	TRANSPARENT_WINDOW,
	REFLECT_CUBE,
	MODEL
};

class MeshManager
{
	public:
		MeshManager() {};
		~MeshManager() {};
		int Awake();
		void SetSceneManager(std::weak_ptr<SceneManager> _sceneManager);
		std::weak_ptr<Model> AddModel(Type _type, std::string _path = "");
	private:
		std::weak_ptr<SceneManager> m_sceneManager;
		std::map<std::string, std::shared_ptr<Model>> m_models;
};

#endif
