#ifndef CAMERA_H
#define CAMERA_H

#include "Component.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>
#include <memory>

class OpenGL;
class GameObject;
class Transform;
class SceneManager;
class CameraManager;

class Camera : public Component
{
	public:
		Camera() {};
		~Camera() {};
		virtual void Awake();
		glm::mat4 GetViewMatrix();
		void SetupFrameBuffer();
		void SetupFrameBuffer(int _width, int _height);
		virtual void Update();	
		void SetFBOTexture();
	private:
		std::weak_ptr<OpenGL> m_openGL;
		std::weak_ptr<Transform> m_transform;
		std::weak_ptr<CameraManager> m_cameraManager;
		unsigned int framebuffer = 0;
		unsigned int textureColorbuffer, rbo;
		float m_zoom;
		float m_maxFov = 90.0f;
};

#endif