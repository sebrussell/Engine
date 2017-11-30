#include "Skybox.h"
#include "Mesh.h"
#include "Shader.h"
#include "MeshManager.h"
#include "Transform.h"

void Skybox::Awake()
{
	m_skyboxMesh = m_meshManager.lock()->AddMesh(SKYBOX);
	m_faces.push_back("..//source/textures/skybox/right.jpg");
	m_faces.push_back("..//source/textures/skybox/left.jpg");
	m_faces.push_back("..//source/textures/skybox/top.jpg");
	m_faces.push_back("..//source/textures/skybox/bottom.jpg");
	m_faces.push_back("..//source/textures/skybox/back.jpg");
	m_faces.push_back("..//source/textures/skybox/front.jpg");
	m_cubemapTexture = loadCubemap();
}

void Skybox::SetShader(std::weak_ptr<Shader> _shader)
{
	m_shader = _shader;
	m_shader.lock()->Use();
	m_shader.lock()->CreateMatrixBuffer();
	
}

void Skybox::SetMeshManager(std::weak_ptr<MeshManager> _manager)
{
	m_meshManager = _manager;
}

void Skybox::SetCameraTransform(std::weak_ptr<Transform> _transform)
{
	m_cameraTransform = _transform;
}

void Skybox::Draw()
{
	m_shader.lock()->Use();	
	m_shader.lock()->SetVec3("aPos", m_cameraTransform.lock()->GetPosition());
	m_shader.lock()->SetMat4("skyboxView", glm::mat4(glm::mat3(m_cameraTransform.lock()->GetLookAt())));
	glDepthFunc(GL_LEQUAL);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_cubemapTexture);	
	m_skyboxMesh.lock()->Draw();
	glDepthFunc(GL_LESS);	
}

unsigned int Skybox::loadCubemap()
{	
    unsigned int textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

    int width, height, nrChannels;
    for (unsigned int i = 0; i < m_faces.size(); i++)
    {
        unsigned char *data = stbi_load(m_faces[i].c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_SRGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
        }
        else
        {
            std::cout << "Cubemap texture failed to load at path: " << m_faces[i] << std::endl;
            stbi_image_free(data);
        }
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    return textureID;
	
}