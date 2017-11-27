#include "Renderer.h"
#include "Mesh.h"
#include "GameObject.h"
#include "SceneManager.h"
#include "CameraManager.h"
#include "Shader.h"
#include "Transform.h"
#include "Camera.h"
#include "Material.h"

Renderer::Renderer()
{
	
}

Renderer::~Renderer()
{

}

void Renderer::SetMesh(Type _type, std::string _path)
{
	switch(_type)
	{
		case CUBE:
			m_mesh->MakeCube();
			break;
		case PLANE:
			//m_mesh.MakePlane();
			break;
		case QUAD:
			//m_mesh.MakeQuad();
			break;
		case SKYBOX:
			//m_mesh.MakeSkybox();
		case REFLECT_CUBE:
			//m_mesh.MakeReflectCube();
		case MODEL:
			//load MODEL
		default:
			break;			
	}
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
	m_material = std::make_shared<Material.h">();
	m_mesh = std::make_shared<Mesh>();

}

void Renderer::Update()
{
	std::shared_ptr<Shader> shader = m_shader.lock();
	
	shader->Use();
	
	shader->SetMat4("model", m_transform.lock()->GetModelMatrix());
	shader->UpdateMatrix(m_activeCamera.lock()->GetProjectionMatrix(), m_activeCamera.lock()->GetViewMatrix());
	//apply shader values
	m_mesh->Draw();
}

void Renderer::Delete()
{
	m_mesh->Delete();
}

void Renderer::SetShader(std::weak_ptr<Shader> _shader)
{
	m_shader = _shader;
	
}

std::weak_ptr<Shader> Renderer::GetShader()
{
	return m_shader;
}