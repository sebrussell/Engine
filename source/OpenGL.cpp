#include "OpenGL.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);


OpenGL::OpenGL()
{

}

int OpenGL::Setup()
{
	//------------------SETUP-------------------------------------------------------------
    if (!glfwInit())
	{
		std::cout << "GLFW Failed to initialise." << std::endl;
	}
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	SCR_WIDTH = 800;
	SCR_HEIGHT = 600;
	
	#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
	#endif
	
	m_window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Game Engine", NULL, NULL);
	if (m_window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(m_window);
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}
	
	
	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //wireframe mode
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //regular
	
	m_camera = std::weak_ptr<Camera>();
	
	
	glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
	
	
	/*
    glEnable(GL_STENCIL_TEST);
    glStencilFunc(GL_NOTEQUAL, 1, 0xFF);	
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	glEnable(GL_BLEND);  	
	glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO);
	//glEnable(GL_CULL_FACE); //this SPEEEDS IT UP LOADS - doesnt work with transpare tho
	*/
   
	glfwSetKeyCallback(m_window, key_callback);
	glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
	glfwSetCursorPosCallback(m_window, mouse_callback);  //register mouse callback function
	glfwSetScrollCallback(m_window, scroll_callback);
	glfwSetErrorCallback(error_callback);
	
	
	
	std::cout << "OpenGL Setup Completed" << std::endl;
	return 0;
	
	//-------------------------END SETUP ------------------------------------
}

OpenGL::~OpenGL()
{
	glBindVertexArray(0);
	glfwTerminate();
}

void OpenGL::SetupFrameBuffer()
{
    glGenFramebuffers(1, &framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
    // create a color attachment texture
    glGenTextures(1, &textureColorbuffer);
    glBindTexture(GL_TEXTURE_2D, textureColorbuffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureColorbuffer, 0);
    // create a renderbuffer object for depth and stencil attachment (we won't be sampling these)
    glGenRenderbuffers(1, &rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, SCR_WIDTH, SCR_HEIGHT); // use a single renderbuffer object for both a depth AND stencil buffer.
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo); // now actually attach it
    // now that we actually created the framebuffer and added all attachments we want to check if it is actually complete now
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void OpenGL::FrameBufferFirstCall()
{
	// bind to framebuffer and draw scene as we normally would to color texture 
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
    glEnable(GL_DEPTH_TEST); // enable depth testing (is disabled for rendering screen-space quad)
}

void OpenGL::FrameBufferSecondCall()
{
	    // now bind back to default framebuffer and draw a quad plane with the attached framebuffer color texture
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glDisable(GL_DEPTH_TEST); // disable depth test so screen-space quad isn't discarded due to depth test.
        // clear all relevant buffers
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // set clear color to white (not really necessery actually, since we won't be able to see behind the quad anyways)
        glClear(GL_COLOR_BUFFER_BIT);
		glBindTexture(GL_TEXTURE_2D, textureColorbuffer);
}

void OpenGL::SwapBuffers()
{
	glfwSwapBuffers(m_window);
	glfwPollEvents();

}

bool OpenGL::ShouldWindowClose()
{  
	float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
	return !glfwWindowShouldClose(m_window);
	
}
void OpenGL::ProcessInput()
{
	float cameraSpeed = 2.5f * deltaTime; // adjust accordingly
	
    if(glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
        glfwSetWindowShouldClose(m_window, true);	
	}
    if (glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS)
	{
        m_camera.lock()->ProcessKeyboard(FORWARD, deltaTime);
	}
    if (glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS)
	{
        m_camera.lock()->ProcessKeyboard(BACKWARD, deltaTime);
	}
    if (glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS)
	{
        m_camera.lock()->ProcessKeyboard(LEFT, deltaTime);
	}
    if (glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS)
	{
        m_camera.lock()->ProcessKeyboard(RIGHT, deltaTime);
	}
	
	

	
}

void OpenGL::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void OpenGL::error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}


void OpenGL::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void OpenGL::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{	
	//cameraMain.ProcessMouseMovement(xpos, ypos);
}

void OpenGL::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	//cameraMain.ProcessMouseScroll(yoffset);
}

