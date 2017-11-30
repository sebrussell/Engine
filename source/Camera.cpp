#include "Camera.h"
#include "Transform.h"
#include "GameObject.h"				//this is wrong
#include "OpenGL.h"
#include "SceneManager.h"
#include "CameraManager.h"

void Camera::Awake()
{
	m_openGL = m_gameObject.lock()->m_sceneManager.lock()->m_openGL; 	
	m_cameraManager = m_gameObject.lock()->m_sceneManager.lock()->m_cameraManager;		
	m_transform = m_gameObject.lock()->GetComponent<Transform>();
	if(m_transform.expired())
	{
		m_transform = m_gameObject.lock()->AddComponent<Transform>();
	}
	m_maxViewDistance = m_gameObject.lock()->m_sceneManager.lock()->m_maxViewDistance;
	m_minViewDistance = m_gameObject.lock()->m_sceneManager.lock()->m_minViewDistance;
	m_zoom = m_maxFov;
	m_aspectRatio = m_openGL.lock()->m_aspectRatio;
}

glm::mat4 Camera::GetViewMatrix()
{
	return m_transform.lock()->GetLookAt();   
}

glm::vec3 Camera::GetPosition()
{
	return m_transform.lock()->m_position; 
}

glm::mat4 Camera::GetProjectionMatrix()
{
	return glm::perspective(glm::radians(m_zoom), m_aspectRatio, m_minViewDistance, m_maxViewDistance);
}

void Camera::SetupFrameBuffer()
{
	SetupFrameBuffer(m_openGL.lock()->GetWindowWidth(), m_openGL.lock()->GetWindowHeight());
}

void Camera::SetupFrameBuffer(int _width, int _height)
{	
	glGenFramebuffers(1, &framebuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
		// create a color attachment texture
	glGenTextures(1, &textureColorbuffer);
	glBindTexture(GL_TEXTURE_2D, textureColorbuffer);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureColorbuffer, 0);
		// create a renderbuffer object for depth and stencil attachment (we won't be sampling these)
	glGenRenderbuffers(1, &rbo);
	glBindRenderbuffer(GL_RENDERBUFFER, rbo);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, _width, _height); // use a single renderbuffer object for both a depth AND stencil buffer.
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo); // now actually attach it
	// now that we actually created the framebuffer and added all attachments we want to check if it is actually complete now
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
		std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
	}
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void Camera::SetupShadowBuffer(int _width, int _height)
{
	m_shadowWidth = _width; 
	m_shadowHeight = _height;
	
    glGenFramebuffers(1, &framebuffer);
    // create depth texture
    glGenTextures(1, &textureColorbuffer);
    glBindTexture(GL_TEXTURE_2D, textureColorbuffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, m_shadowWidth, m_shadowHeight, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // attach depth texture as FBO's depth buffer
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, textureColorbuffer, 0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);
	
	// now that we actually created the framebuffer and added all attachments we want to check if it is actually complete now
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
		std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
	}
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void Camera::DrawShadowBuffer()
{
	glViewport(0, 0, m_shadowWidth, m_shadowHeight);
	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	//glClear(GL_DEPTH_BUFFER_BIT);
}

void Camera::Clear()
{
	glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void Camera::ResetFBO()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void Camera::Use(bool _depthTest)
{
	if(framebuffer > 0)
	{
		glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	}		
	else
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}		
	if(_depthTest)
	{
		//glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);
	}
	else{
		//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		//glClear(GL_COLOR_BUFFER_BIT);
		glDisable(GL_DEPTH_TEST);
	}
}

unsigned int Camera::GetFBOTexture()
{
	return textureColorbuffer;
}