#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H

#include <vector>
#include <memory>
#include <map>
#include <string>

class Shader;

class ShaderManager
{
	public:
		ShaderManager() {};
		~ShaderManager() {};
		int Awake();
		std::weak_ptr<Shader> AddShader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);
	private:
		std::map<std::string, std::shared_ptr<Shader>> m_shaders;

};

#endif
