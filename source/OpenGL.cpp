#include "OpenGL.h"
#include "Transform.h"
#include "Input.h"
#include "SceneManager.h"

std::shared_ptr<Input> g_input;

OpenGL::OpenGL()
{

}

int OpenGL::Setup(int _windowWidth, int _windowHeight)
{
	//------------------SETUP-------------------------------------------------------------
    if (!glfwInit())
	{
		std::cout << "GLFW Failed to initialise." << std::endl;
	}
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	glfwWindowHint(GLFW_SAMPLES, 4); //multisampling
	
	
	m_windowWidth = _windowWidth;
	m_windowHeight = _windowHeight;
	
	#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
	#endif
	
	m_window = glfwCreateWindow(m_windowWidth, m_windowHeight, "Game Engine", NULL, NULL);
	
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
	
	
	glViewport(0, 0, m_windowWidth, m_windowHeight);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //wireframe mode
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //regular
	
	glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
	glEnable(GL_MULTISAMPLE);  
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_FRAMEBUFFER_SRGB); 
	
	
	/*
    glEnable(GL_STENCIL_TEST);
    glStencilFunc(GL_NOTEQUAL, 1, 0xFF);	
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	//glEnable(GL_CULL_FACE); //this SPEEEDS IT UP LOADS - doesnt work with transpare tho
	*/
   
	glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);  
   
	glfwSetFramebufferSizeCallback(m_window, FrameBufferSizeCallBack);
	glfwSetCursorPosCallback(m_window, MouseCallBack);  //register mouse callback function
	glfwSetScrollCallback(m_window, ScrollCallBack);
	glfwSetErrorCallback(ErrorCallBack);
	
	//glEnable(GL_PROGRAM_POINT_SIZE);  
	//glEnable(GL_CULL_FACE);
	
	m_aspectRatio = (float)m_windowWidth / (float)m_windowHeight;
	
	g_input = std::make_shared<Input>();
	g_input->Awake();
	m_sceneManager.lock()->m_input = g_input;
	
	std::cout << "OpenGL Setup Completed" << std::endl;
	return 0;
	
	//-------------------------END SETUP ------------------------------------
}

OpenGL::~OpenGL()
{
	glBindVertexArray(0);
	glfwTerminate();
}

void OpenGL::SetViewPort(int _width, int _height)
{
	glViewport(0, 0, _width, _height);
}

void OpenGL::SwapBuffers()
{
	glfwSwapBuffers(m_window);
	glfwPollEvents();
}

void OpenGL::SetCameraMainTransform(std::weak_ptr<Transform> _transform)
{
	m_cameraMain = _transform;
}

void OpenGL::SetSceneManager(std::weak_ptr<SceneManager> _manager)
{
	m_sceneManager = _manager;
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
	g_input->ProcessKey(m_window);
}

void OpenGL::MouseCallBack(GLFWwindow* window, double xpos, double ypos)
{	
	g_input->ProcessMouse(xpos, ypos);
}

void OpenGL::ErrorCallBack(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}


void OpenGL::FrameBufferSizeCallBack(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void OpenGL::ScrollCallBack(GLFWwindow* window, double xoffset, double yoffset)
{
	g_input->ProcessScroll(xoffset, yoffset);
}

void OpenGL::SetAlphaFunction()
{
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void OpenGL::ResetAlphaFunction()
{
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}



