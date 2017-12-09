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
	private:	
		std::weak_ptr<Physics> m_physics;
		std::weak_ptr<rp3d::DynamicsWorld> m_world;
		std::weak_ptr<Transform> m_transform;
		std::shared_ptr<rp3d::RigidBody> m_body;
		rp3d::Transform m_physicsTransform;
		glm::vec3 m_position;
};

