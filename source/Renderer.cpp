#include "Renderer.h"
#include "Mesh.h"
#include "GameObject.h"
#include "SceneManager.h"
#include "CameraManager.h"
#include "Shader.h"
#include "Transform.h"
#include "Camera.h"
#include "Material.h"
#include "MeshManager.h"

Renderer::Renderer()
{
	
}

Renderer::~Renderer()
{

}

void Renderer::SetMesh(Type _type, std::string _path)
{
	m_mesh = m_meshManager.lock()->AddMesh(_type, _path);
}

void Renderer::Awake()
{
	//m_openGL = m_gameObject.lock()->m_sceneManager.lock()->m_openGL; 	
	m_activeCamera = m_gameObject.lock()->m_sceneManager.lock()->m_cameraManager->m_activeCamera;		
	m_transform = m_gameObject.lock()->GetComponent<Transform>();
	if(m_transform.expired())
	{
		m_transform = m_gameObject.lock()->AddComponent<Transform>();
	}
	m_material = std::make_shared<Material>();
	m_meshManager = m_gameObject.lock()->m_sceneManager.lock()->m_meshManager;	
	m_gameObject.lock()->m_renderer = m_gameObject.lock()->GetComponent<Renderer>();
}

void Renderer::ShadowDraw(std::weak_ptr<Shader> _shader)
{
	_shader.lock()->SetMat4("model", m_transform.lock()->GetModelMatrix());
	m_mesh.lock()->Draw();
}

void Renderer::Update()
{
	std::shared_ptr<Shader> shader = m_shader.lock();	
	shader->Use();	
	shader->SetMat4("model", m_transform.lock()->GetModelMatrix());
	shader->UpdateMatrix(m_activeCamera.lock()->GetProjectionMatrix(), m_activeCamera.lock()->GetViewMatrix());
	//apply shader values
	m_material->Apply();
	m_mesh.lock()->Draw();
}

void Renderer::Delete()
{
	m_mesh.lock()->Delete();
}

void Renderer::SetShader(std::weak_ptr<Shader> _shader)
{
	m_shader = _shader;
	m_material->SetShader(m_shader);
}

std::weak_ptr<Shader> Renderer::GetShader()
{
	return m_shader;
}