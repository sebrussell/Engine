#include "ShaderManager.h"
#include "Shader.h"

int ShaderManager::Awake()
{	
	return 0;	
}

std::weak_ptr<Shader> ShaderManager::AddShader(const char* vertexPath, const char* fragmentPath, const char* geometryPath)
{		
	std::shared_ptr<Shader> shader(new Shader(vertexPath, fragmentPath, geometryPath));	
	m_shaders.push_back(shader);
	return shader;
}