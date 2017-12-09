#include "Physics.h"

Physics::Physics()
{
	
}

Physics::~Physics()
{
	
}

void Physics::Awake()
{
	rp3d::Vector3 gravity(0.0, -9.81, 0.0);
	m_world = std::make_shared<rp3d::DynamicsWorld>(gravity);
	
	
	
}

void Physics::Update()
{
	
	m_currentFrameTime = glfwGetTime();
	
	m_deltaTime = m_currentFrameTime - m_previousFrameTime;
	
	m_previousFrameTime = m_currentFrameTime;
	
	m_accumulator += m_deltaTime;
	
	while(m_accumulator >= m_timeStep)
	{
		m_world->update(m_timeStep);
		
		m_accumulator -= m_timeStep;
	}
	
}