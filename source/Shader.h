#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    unsigned int m_ID;	
    Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);
	~Shader();

    void Use();
    void SetBool(const std::string &name, bool value) const;
    void SetInt(const std::string &name, int value) const;
    void SetFloat(const std::string &name, float value) const;
	void SetMat4(const std::string &name, glm::mat4 value) const;
	void SetVec3(const std::string &name, glm::vec3 value) const;
	void CreateMatrixBuffer();	
	void UpdateMatrix(glm::mat4 projection, glm::mat4 view);
private:
	unsigned int m_uboMatrices;
    void CheckCompileErrors(unsigned int shader, std::string type);

};
#endif