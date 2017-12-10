#include "Component.h"
#include "reactphysics3d.h"
#include <memory>
#include <iostream>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Physics;
class Transform;

//using namespace reactphysics3d;

class Rigidbody : public Component
{
	public:
		Rigidbody();
		~Rigidbody();
		virtual void Update();
		virtual void Awake();
		void GravityProperty(bool _on);
		void SetStatic();
		void SetPosition(glm::vec3 _position);
	private:	
		std::weak_ptr<Physics> m_physics;
		std::weak_ptr<rp3d::DynamicsWorld> m_world;
		std::weak_ptr<Transform> m_transform;
		
		std::shared_ptr<rp3d::RigidBody> m_body;
		
		std::shared_ptr<rp3d::ProxyShape> m_shape;
		rp3d::Transform m_physicsTransform;
		glm::vec3 m_position;
		rp3d::decimal m_mass;
		rp3d::Vector3 halfDimension;
		std::shared_ptr<rp3d::BoxShape> boxShape;
		
};

