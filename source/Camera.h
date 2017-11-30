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
		glm::mat4 GetProjectionMatrix();
		glm::vec3 GetPosition();
		void SetupFrameBuffer();
		void SetupFrameBuffer(int _width, int _height);
		void SetupShadowBuffer(int _width, int _height);
		void DrawShadowBuffer();
		void ResetFBO();
		void Use(bool _depthTest);
		void Clear();
		unsigned int GetFBOTexture();
		std::weak_ptr<Transform> m_transform;
	private:
		std::weak_ptr<OpenGL> m_openGL;
		
		std::weak_ptr<CameraManager> m_cameraManager;
		unsigned int framebuffer = 0;
		unsigned int textureColorbuffer, rbo;
		float m_zoom;
		float m_maxFov = 90.0f;
		
		int m_shadowWidth, m_shadowHeight;
		
		float m_aspectRatio;
		float m_maxViewDistance;
		float m_minViewDistance;
};

#endif