#ifndef MESHMANAGER_H
#define MESHMANAGER_H

#include <vector>
#include <memory>

class SceneManager;
class Mesh;

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
		std::weak_ptr<Mesh> AddMesh(Type _type, std::string _path = "");
	private:
		std::weak_ptr<SceneManager> m_sceneManager;
		std::vector<std::shared_ptr<Mesh>> m_meshes;
};

#endif
