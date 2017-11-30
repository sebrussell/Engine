#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include <vector>
#include <memory>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera;
class SceneManager;
class GameObject;
class Renderer;
class Shader;

class CameraManager
{
	public:
		CameraManager() {};
		~CameraManager() {};
		int Awake();
		void SetupPostProcessing();
		void PostProcessingCall1();
		void PostProcessingCall2();
		void ShadowPass();
		void GammaCorrection();
		void TransparentCall();
		void SetSceneManager(std::weak_ptr<SceneManager> _sceneManager);
		void SetMainCamera(std::weak_ptr<Camera> _camera);
		void SetActiveCamera(std::weak_ptr<Camera> _camera);
		void AddCamera(std::weak_ptr<Camera> _camera);
		std::weak_ptr<Camera> m_activeCamera;
		std::weak_ptr<Camera> m_mainCamera;
		std::weak_ptr<Shader> m_shadowShader;
	private:
		std::vector<std::weak_ptr<Camera>> m_cameras;
		
		std::weak_ptr<SceneManager> m_sceneManager;
		float m_gamma = 0.5;
		
		std::weak_ptr<Shader> m_gammaShader;
		std::weak_ptr<Shader> m_blurShader;
		std::weak_ptr<Shader> m_defaultShader;
		std::weak_ptr<Shader> m_depthShader;			
		
		std::weak_ptr<Camera> m_postProcessing1, m_postProcessing2, m_gammaCamera, m_shadowCamera;
		std::weak_ptr<Renderer> m_postProcessingQuad;
};

#endif
