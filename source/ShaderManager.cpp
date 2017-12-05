#include "ShaderManager.h"
#include "Shader.h"

int ShaderManager::Awake()
{	
	return 0;	
}

std::weak_ptr<Shader> ShaderManager::AddShader(const char* vertexPath, const char* fragmentPath, const char* geometryPath)
{		
	std::weak_ptr<Shader> m_returnShader;
	std::string buffer(vertexPath);
	buffer.append(fragmentPath);
	if(geometryPath)
	{
		buffer.append(geometryPath);
	}		
	
	if(!m_shaders[buffer])
	{		
		std::shared_ptr<Shader> shader(new Shader(vertexPath, fragmentPath, geometryPath));	
		shader->CreateMatrixBuffer();
		m_shaders[buffer] = shader;			
	}
	m_returnShader = m_shaders[buffer];

	return m_returnShader;
}