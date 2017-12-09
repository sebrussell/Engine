#include "Rigidbody.h"
#include "Transform.h"
#include "GameObject.h"
#include "SceneManager.h"
#include "Physics.h"

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
	
	std::shared_ptr<rp3d::RigidBody> temp(m_world.lock()->createRigidBody(transform));
	
	m_body = temp;
	
	rp3d::Material& material = m_body->getMaterial();
	
	//m_body->setType(KINEMATIC);
	
}

void Rigidbody::Update()
{
	m_physicsTransform = m_body->getTransform();
	m_position.x = m_physicsTransform.getPosition().x;
	m_position.y = m_physicsTransform.getPosition().y;
	m_position.z = m_physicsTransform.getPosition().z;
	m_transform.lock()->SetPosition(m_position);
}

void Rigidbody::GravityProperty(bool _on)
{
	m_body->enableGravity(_on);
}
