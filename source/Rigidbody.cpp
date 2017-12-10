#include "Rigidbody.h"
#include "Transform.h"
#include "GameObject.h"
#include "SceneManager.h"
#include "Physics.h"
#include "Renderer.h"
#include "Model.h"

Rigidbody::Rigidbody()
{

}

Rigidbody::~Rigidbody()
{

}

void Rigidbody::Awake()
{
	m_physics = m_gameObject.lock()->m_sceneManager.lock()->m_physics;
	m_world = m_physics.lock()->GetWorld();
	m_transform = m_gameObject.lock()->GetComponent<Transform>();
	if(m_transform.expired())
	{
		m_transform = m_gameObject.lock()->AddComponent<Transform>();
	}
	
	glm::vec3 position = m_transform.lock()->GetPosition();
	rp3d::Vector3 initPosition(position.x, position.y, position.z) ;
	rp3d::Quaternion initOrientation = rp3d::Quaternion::identity();
	rp3d::Transform transform(initPosition, initOrientation);
	
	
	
	m_body = std::shared_ptr<rp3d::RigidBody>(m_world.lock()->createRigidBody(transform));
	
	//m_body->setType(rp3d::KINEMATIC);
	
	rp3d::Material& material = m_body->getMaterial();
	material.setBounciness(rp3d::decimal(0.0)); 
	
	glm::vec3 dimensions = m_gameObject.lock()->GetComponent<Renderer>()->m_model.lock()->GetModelDimensions();
	dimensions.x *= 0.5;
	dimensions.y *= 0.5;
	dimensions.z *= 0.5;
	
	
	halfDimension.x = dimensions.x;
	halfDimension.y = dimensions.y;
	halfDimension.z = dimensions.z;

	
	boxShape = std::make_shared<rp3d::BoxShape>(halfDimension);
	
	
	
	glm::vec3 m_pos = m_transform.lock()->GetLocalPosition();
	//m_pos -= dimensions;
	
	//std::cout << m_pos.x << " " << m_pos.y << " " << m_pos.z << std::endl;
	
	rp3d::Vector3 initPos(m_pos.x, m_pos.y, m_pos.z) ;
	m_pos = m_transform.lock()->GetRotation();
	initOrientation = rp3d::Quaternion(m_pos.x, m_pos.y, m_pos.z);
	std::cout << m_pos.x << " " << m_pos.y << " " << m_pos.z << std::endl;
	rp3d::Transform m_localSpace(initPos, initOrientation);
	
	m_mass = rp3d::decimal(40.0);
	
	//std::shared_ptr<rp3d::ProxyShape> proxyTemp();
	//m_shape = proxyTemp;	

	m_body->addCollisionShape(boxShape.get(), m_localSpace, m_mass);
	
}

void Rigidbody::Update()
{
	m_physicsTransform = m_body->getTransform();
	
	rp3d::Vector3 m_pos =  m_physicsTransform.getPosition();
	m_position.x = m_pos.x;
	m_position.y = m_pos.y - halfDimension.y;
	m_position.z = m_pos.z;
	
	//std::cout << m_position.x << " " << m_position.y << " " << m_position.z << std::endl;
	
	rp3d::Quaternion rotation = m_body->getTransform().getOrientation();
	
	m_transform.lock()->SetPosition(m_position);
}

void Rigidbody::GravityProperty(bool _on)
{
	m_body->enableGravity(_on);
}

void Rigidbody::SetStatic()
{
	m_body->setType(rp3d::STATIC);
}

void Rigidbody::SetPosition(glm::vec3 _position)
{
	//rp3d::Vector3 position(_position.x, _position.y, _position.z); 
	//m_physicsTransform = m_body->getTransform();
	//m_physicsTransform.setPosition(position);
}
