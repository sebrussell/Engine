#ifndef CAMERA_H
#define CAMERA_H

class SceneManager;
class Component;
class OpenGL;

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <iostream>

class Camera : public Component
{

	public:
		unsigned int framebuffer = 0;
		unsigned int textureColorbuffer, rbo;
		float m_zoom;
		float m_maxFov = 90.0f;
		
	// Constructor with vectors
    Camera()
    {
		m_openGL = m_gameObject.lock()->m_sceneManager.lock()->m_openGL; 
		m_zoom = m_maxFov;
    }
	
	// Returns the view matrix calculated using Eular Angles and the LookAt Matrix
    glm::mat4 GetViewMatrix()
    {
        //return glm::lookAt(Position, Position + Front, Up);
    }
	
	void SetupFrameBuffer(int _width, int _height)
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
	
	virtual void Update()
	{
		// bind to framebuffer and draw scene as we normally would to color texture 
		if(framebuffer > 0)
		{
			glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
			glEnable(GL_DEPTH_TEST);
			//glBindTexture(GL_TEXTURE_2D, textureColorbuffer);
		}		
		else
		{
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
			glDisable(GL_DEPTH_TEST);
			//glDisable(GL_DEPTH_TEST); // disable depth test so screen-space quad isn't discarded due to depth test.
		}		
	}
	
	void SetFBOTexture()
	{
		glBindTexture(GL_TEXTURE_2D, textureColorbuffer);
	}
	
	private:
		std::weak_ptr<OpenGL> m_openGL;
		
};

#endif