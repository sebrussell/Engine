#include "CameraManager.h"
#include "GameObject.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Camera.h"
#include "Renderer.h"
#include "Material.h"
#include "ShaderManager.h"
#include "Shader.h"
#include "InputHandlerScript.h"

int CameraManager::Awake()
{
	std::weak_ptr<GameObject> m_gameObject = m_sceneManager.lock()->CreateGameObject();	
	m_activeCamera = m_gameObject.lock()->AddComponent<Camera>();
	m_gameObject.lock()->AddComponent<Transform>();	
	m_gameObject.lock()->GetComponent<Transform>()->m_position = glm::vec3(0.0f, 0.0f, 3.0f);
	m_mainCamera = m_activeCamera;
	m_gameObject.lock()->AddComponent<InputHandler>();
	
	//m_gameObject.lock()->m_shouldUpdate = false;
	
	std::weak_ptr<GameObject> m_rendererQuad = m_sceneManager.lock()->CreateGameObject();	
	m_postProcessingQuad = m_rendererQuad.lock()->AddComponent<Renderer>();	
	m_rendererQuad.lock()->m_shouldUpdate = false;
	
	std::weak_ptr<GameObject> camera1 = m_sceneManager.lock()->CreateGameObject();	
	m_postProcessing1 = camera1.lock()->AddComponent<Camera>();
	camera1.lock()->m_shouldUpdate = false;	
	
	std::weak_ptr<GameObject> camera2 = m_sceneManager.lock()->CreateGameObject();	
	m_postProcessing2 = camera2.lock()->AddComponent<Camera>();
	camera2.lock()->m_shouldUpdate = false;
	
	std::weak_ptr<GameObject> camera3 = m_sceneManager.lock()->CreateGameObject();	
	m_gammaCamera = camera3.lock()->AddComponent<Camera>();
	camera3.lock()->m_shouldUpdate = false;
	
	std::weak_ptr<GameObject> camera4 = m_sceneManager.lock()->CreateGameObject();	
	m_shadowCamera = camera4.lock()->AddComponent<Camera>();
	camera4.lock()->m_shouldUpdate = false;

	return 0;	
}

void CameraManager::AddSpotLight(std::weak_ptr<Transform> _transform)
{
	m_spotLightTransform.push_back(_transform);
}

int CameraManager::GetSpotLightSize()
{
	return m_spotLightTransform.size();
}

void CameraManager::SetSceneManager(std::weak_ptr<SceneManager> _sceneManager)
{
	m_sceneManager = _sceneManager;
}

void CameraManager::SetMainCamera(std::weak_ptr<Camera> _camera) 
{
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
	m_gammaCamera.lock()->SetupFrameBuffer();
	m_shadowCamera.lock()->CreateDepthMap(1024, 1024);
	



	m_blurShader = m_sceneManager.lock()->m_shaderManager->AddShader("..//source/shaders/bloomBlur.vs", "..//source/shaders/bloomBlur.fs");
	m_blurShader.lock()->Use();
	m_blurShader.lock()->SetInt("screenTexture", 0);
	
	m_defaultShader = m_sceneManager.lock()->m_shaderManager->AddShader("..//source/shaders/blankPostShader.vs", "..//source/shaders/blankPostShader.fs");
	m_defaultShader.lock()->Use();
	m_defaultShader.lock()->SetInt("screenTexture", 0);
	
	
	m_gammaShader = m_sceneManager.lock()->m_shaderManager->AddShader("..//source/shaders/blankPostShader.vs", "..//source/shaders/gammaShader.fs");
	m_gammaShader.lock()->Use();
	m_gammaShader.lock()->SetInt("screenTexture", 0);
	m_gammaShader.lock()->SetFloat("gamma", m_gamma);
	
	m_bloomShader1 = m_sceneManager.lock()->m_shaderManager->AddShader("..//source/shaders/bloomStep1.vs", "..//source/shaders/bloomStep1.fs");
	m_bloomShader1.lock()->Use();
	m_bloomShader1.lock()->SetInt("screenTexture", 0);
	
	m_bloomShader2 = m_sceneManager.lock()->m_shaderManager->AddShader("..//source/shaders/bloomStep2.vs", "..//source/shaders/bloomStep2.fs");
	m_bloomShader2.lock()->Use();
	m_bloomShader2.lock()->SetInt("scene", 0);
	m_bloomShader2.lock()->SetInt("bloomBlur", 1);
	
	m_shadowShader = m_sceneManager.lock()->m_shaderManager->AddShader("..//source/shaders/pointShadow/depthShader.vs", "..//source/shaders/pointShadow/depthShader.fs", "..//source/shaders/pointShadow/depthShader.gs");
	
	m_depthShader = m_sceneManager.lock()->m_shaderManager->AddShader("..//source/shaders/depthViewer.vs", "..//source/shaders/depthViewer.fs");
	m_depthShader.lock()->Use();
	m_depthShader.lock()->SetInt("depthMap", 0);

	
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
	GammaCorrection();
	
	m_postProcessing2.lock()->Use(false);
	m_postProcessingQuad.lock()->SetShader(m_bloomShader1);
	m_postProcessingQuad.lock()->m_material->SetTexture(m_gammaCamera.lock()->GetFBOTexture());	
	m_postProcessingQuad.lock()->Update();
	
	bool horizontal = true;
	int amount = 10;

	for (unsigned int i = 0; i < amount; i++)
	{
		if(horizontal)
		{
			m_postProcessing1.lock()->Use(false);
			m_postProcessingQuad.lock()->SetShader(m_blurShader);
			m_postProcessingQuad.lock()->m_material->SetTexture(m_postProcessing2.lock()->GetFBOTexture());	
			m_blurShader.lock()->SetInt("horizontal", horizontal);
			m_postProcessingQuad.lock()->Update();
		}
		else
		{
			m_postProcessing2.lock()->Use(false);
			m_postProcessingQuad.lock()->SetShader(m_blurShader);
			m_postProcessingQuad.lock()->m_material->SetTexture(m_postProcessing1.lock()->GetFBOTexture());	
			m_blurShader.lock()->SetInt("horizontal", horizontal);
			m_postProcessingQuad.lock()->Update();
		}

		horizontal = !horizontal;
	}

	m_postProcessing1.lock()->Use(false);
	m_postProcessingQuad.lock()->SetShader(m_blurShader);
	m_postProcessingQuad.lock()->m_material->SetTexture(m_postProcessing2.lock()->GetFBOTexture());	
	m_postProcessingQuad.lock()->Update();
	
	m_postProcessing2.lock()->Use(false);
	m_postProcessingQuad.lock()->SetShader(m_bloomShader2);
	m_postProcessingQuad.lock()->m_material->SetTexture(m_gammaCamera.lock()->GetFBOTexture());
	m_postProcessingQuad.lock()->m_material->SetTexture(m_postProcessing1.lock()->GetFBOTexture(), 1);		
	m_postProcessingQuad.lock()->Update();
	
	//exposure -= 0.001;
	
	m_bloomShader2.lock()->SetFloat("exposure", exposure);
	

	m_mainCamera.lock()->Use(false);
	m_postProcessingQuad.lock()->SetShader(m_defaultShader);
	m_postProcessingQuad.lock()->m_material->SetTexture(m_postProcessing2.lock()->GetFBOTexture());
	m_postProcessingQuad.lock()->Update();
	
	//set main camera
	//set blank screen shader
	//set material
	//draw
	
}

void CameraManager::GammaCorrection()
{
	m_gammaCamera.lock()->Use(false);	
	m_postProcessingQuad.lock()->SetShader(m_gammaShader);
	m_postProcessingQuad.lock()->m_material->SetTexture(m_postProcessing1.lock()->GetFBOTexture());		
	m_postProcessingQuad.lock()->Update();
	
	
		

}


void CameraManager::ShadowPass(int i)
{	
	glm::vec3 lightPos = m_spotLightTransform.at(i).lock()->m_position;
	
	shadowTransforms.clear();
	glm::mat4 shadowProj = glm::perspective(glm::radians(90.0f), (float)1024 / (float)1024, near_plane, far_plane);
    shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec3(0.0f, -1.0f,  0.0f)));
    shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec3(0.0f, -1.0f,  0.0f)));
    shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3( 0.0f,  1.0f,  0.0f), glm::vec3(0.0f,  0.0f,  1.0f)));
    shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec3(0.0f,  0.0f, -1.0f)));
    shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec3(0.0f, -1.0f,  0.0f)));
    shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec3(0.0f, -1.0f,  0.0f)));
	
	m_shadowShader.lock()->Use();
	
    for (unsigned int i = 0; i < shadowTransforms.size(); i++)
	{
        m_shadowShader.lock()->SetMat4("shadowMatrices[" + std::to_string(i) + "]", shadowTransforms[i]);
	}

    m_shadowShader.lock()->SetFloat("far_plane", far_plane);    
	m_shadowShader.lock()->SetVec3("lightPos", lightPos);
	

}
