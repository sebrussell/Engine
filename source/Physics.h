#ifndef PHYSICS_H
#define PHYSICS_H

#include <iostream>
#include <memory>
#include <vector>
#include "reactphysics3d.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


class Physics
{
	public:
		Physics();
		~Physics();
		void Awake();
		void Update();
		std::shared_ptr<rp3d::DynamicsWorld> GetWorld() { return m_world; }
	private:
		std::shared_ptr<rp3d::DynamicsWorld> m_world;
		const float m_timeStep = 1.0 / 60.0;
	
		double m_currentFrameTime, m_previousFrameTime, m_accumulator, m_deltaTime;
};

#endif