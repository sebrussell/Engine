#include "CameraManager.h"
#include "GameObject.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Camera.h"
#include "Renderer.h"
#include "Material.h"
#include "ShaderManager.h"
#include "Shader.h"

int CameraManager::Awake()
{
	std::weak_ptr<GameObject> m_gameObject = m_sceneManager.lock()->CreateGameObject();	
	m_activeCamera = m_gameObject.lock()->AddComponent<Camera>();
	m_gameObject.lock()->AddComponent<Transform>();	
	m_gameObject.lock()->GetComponent<Transform>()->m_position = glm::vec3(0.0f, 0.0f, 15.0f);
	m_mainCamera = m_activeCamera;
	
	std::weak_ptr<GameObject> m_rendererQuad = m_sceneManager.lock()->CreateGameObject();	
	m_postProcessingQuad = m_rendererQuad.lock()->AddComponent<Renderer>();	
	m_rendererQuad.lock()->m_shouldUpdate = false;
	
	std::weak_ptr<GameObject> camera1 = m_sceneManager.lock()->CreateGameObject();	
	m_postProcessing1 = camera1.lock()->AddComponent<Camera>();
	camera1.lock()->m_shouldUpdate = false;	
	
	std::weak_ptr<GameObject> camera2 = m_sceneManager.lock()->CreateGameObject();	
	m_postProcessing2 = camera2.lock()->AddComponent<Camera>();
	camera2.lock()->m_shouldUpdate = false;


	return 0;	
}

void CameraManager::SetSceneManager(std::weak_ptr<SceneManager> _sceneManager)
{
	m_sceneManager = _sceneManager;
}

void CameraManager::SetMainCamera(std::weak_ptr<Camera> _camera) { 

	m_mainCamera = _camera; 

}

void CameraManager::SetActiveCamera(std::weak_ptr<Camera> _camera) 
{ 
	m_activeCamera = _camera; 
}

void CameraManager::AddCamera(std::weak_ptr<Camera> _camera)
{
	m_cameras.push_back(_camera);
}

void CameraManager::SetupPostProcessing()
{
	m_postProcessingQuad.lock()->SetMesh(QUAD);
	m_postProcessing1.lock()->SetupFrameBuffer();

	m_postProcessing2.lock()->SetupFrameBuffer();

	m_blurShader = m_sceneManager.lock()->m_shaderManager->AddShader("..//source/shaders/postProcShader.vs", "..//source/shaders/blankPostShader.fs");
	m_blurShader.lock()->Use();
	m_blurShader.lock()->SetInt("screenTexture", 0);
	
	m_defaultShader = m_sceneManager.lock()->m_shaderManager->AddShader("..//source/shaders/blankPostShader.vs", "..//source/shaders/blankPostShader.fs");
	m_defaultShader.lock()->Use();
	m_defaultShader.lock()->SetInt("screenTexture", 0);
}

void CameraManager::PostProcessingCall1()
{
	m_postProcessing1.lock()->Use(true);
	m_postProcessing1.lock()->Clear();
}

void CameraManager::TransparentCall()
{
	m_postProcessing2.lock()->Use(true);
}


void CameraManager::PostProcessingCall2()
{
	//m_postProcessing2.lock()->Use(false);
	//m_postProcessingQuad.lock()->SetShader(m_blurShader);
	//m_postProcessingQuad.lock()->m_material->SetTexture(m_postProcessing1.lock()->GetFBOTexture());	
	//m_postProcessingQuad.lock()->Update();
	
	m_mainCamera.lock()->Use(false);
	m_postProcessingQuad.lock()->SetShader(m_defaultShader);
	m_postProcessingQuad.lock()->m_material->SetTexture(m_postProcessing1.lock()->GetFBOTexture());	
	m_postProcessingQuad.lock()->Update();
	//set main camera
	//set blank screen shader
	//set material
	//draw
}
