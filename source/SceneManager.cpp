#include "SceneManager.h"
#include "OpenGL.h"
#include "CameraManager.h"
#include "Skybox.h"
#include "GameObject.h"
#include "ShaderManager.h"
#include "MeshManager.h"
#include "Camera.h"
#include "Transform.h"
#include "Camera.h"
#include "Renderer.h"
#include "Shader.h"
#include "Input.h"


int SceneManager::Awake()
{
	m_openGL = std::make_shared<OpenGL>();
	m_openGL->SetSceneManager(shared_from_this());
	m_openGL->Setup(800, 600);
	
	m_maxViewDistance = 500.0f;
	m_minViewDistance = 0.1f;
		
	m_cameraManager = std::make_shared<CameraManager>();	
	m_cameraManager->SetSceneManager(shared_from_this());
	m_cameraManager->Awake();
	
	
	m_meshManager = std::make_shared<MeshManager>();
	
	m_shaderManager = std::make_shared<ShaderManager>();
	m_shaderManager->Awake();

	m_skybox  = std::make_shared<Skybox>();
	m_skybox->SetMeshManager(m_meshManager);
	m_skybox->Awake();
	m_skybox->SetShader(m_shaderManager->AddShader("..//source/shaders/skyboxShader.vs", "..//source/shaders/skyboxShader.fs"));
	
	
	for(int i = 0; i < m_gameObjects.size(); i++)
	{		
		m_gameObjects.at(i)->Awake();
	}
	m_skybox->SetCameraTransform(m_cameraManager->m_mainCamera.lock()->m_transform);
	m_openGL->SetCameraMainTransform(m_cameraManager->m_mainCamera.lock()->m_transform);
	m_cameraManager->SetupPostProcessing();

	return 0;
}

std::weak_ptr<GameObject> SceneManager::CreateGameObject()
{
	std::shared_ptr<GameObject> gameObject(new GameObject);
	gameObject->m_sceneManager = shared_from_this();
	m_gameObjects.push_back(gameObject);
	return gameObject;
}

void SceneManager::Update()
{
	m_cameraManager->m_shadowCamera.lock()->DrawShadowBuffer();
	
	for(int i = 0; i < m_cameraManager->GetSpotLightSize(); i++)
	{
		m_cameraManager->ShadowPass(i);
	
	
		for(int i = 0; i < m_gameObjects.size(); i++)
		{
			if(m_gameObjects.at(i)->m_renderer && !m_gameObjects.at(i)->m_transparent)
			{
				m_gameObjects.at(i)->m_renderer->ShadowDraw(m_cameraManager->m_shadowShader);
			}		
		}
	}	
	
	//// DRAW NORMALLY
	
	m_openGL->SetViewPort();
	m_cameraManager->PostProcessingCall1();
	
	//m_cameraManager->m_mainCamera.lock()->Use(true);
	
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		if(m_gameObjects.at(i)->m_shouldUpdate && !m_gameObjects.at(i)->m_transparent)
		{
			m_gameObjects.at(i)->Update();
		}		
		if(m_gameObjects.at(i)->m_transparent)
		{
			float distance = glm::length(m_cameraManager->m_mainCamera.lock()->m_transform.lock()->GetPosition() - m_gameObjects.at(i)->m_transform->GetPosition());
			m_sorted[distance] = m_gameObjects.at(i);
		}
	}	

	m_skybox->Draw();

	for(int i = m_sorted.size() - 1; i >= 0; i--)
	{
		if(m_sorted.at(i).lock()->m_shouldUpdate && m_sorted.at(i).lock()->m_transparent)
		{
			m_sorted.at(i).lock()->Update();
		}		
	}

	//draw instanced gameobjects

	//draw transparent gameobjects
	
	
	
	//draw cameras for mirrors
	//post processing
	//enable main camera
	
	m_cameraManager->PostProcessingCall2();
}

void SceneManager::Delete()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects.at(i)->Delete();
	}
	glfwTerminate();
}

