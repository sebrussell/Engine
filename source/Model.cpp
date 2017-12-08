#include "Model.h"
#include "Mesh.h"

Model::Model()
{
	
}

Model::~Model()
{
	
}

void Model::MakeCube()
{
	std::shared_ptr<Mesh> m_mesh(new Mesh);
	m_mesh->MakeCube();
	m_meshes.push_back(m_mesh);
}

void Model::MakeSkybox()
{
	std::shared_ptr<Mesh> m_mesh(new Mesh);
	m_mesh->MakeSkybox();
	m_meshes.push_back(m_mesh);
}

void Model::MakeQuad()
{
	std::shared_ptr<Mesh> m_mesh(new Mesh);
	m_mesh->MakeQuad();
	m_meshes.push_back(m_mesh);
}

void Model::MakeTransparent()
{
	std::shared_ptr<Mesh> m_mesh(new Mesh);
	m_mesh->MakeTransparent();
	m_meshes.push_back(m_mesh);
}

void Model::MakePlane()
{
	std::shared_ptr<Mesh> m_mesh(new Mesh);
	m_mesh->MakePlane();
	m_meshes.push_back(m_mesh);
}

void Model::Draw()
{
	for(int i = 0; i < m_meshes.size(); i++)
	{
		m_meshes.at(i)->Draw();
	}
}

void Model::MakeModel(std::string _path)
{
	Assimp::Importer importer; 
	const aiScene* scene = importer.ReadFile(_path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

	if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) 
    {
        std::cout << "ERROR::ASSIMP::" << std::endl;
        return;
    }
	
	ProcessNode(scene->mRootNode, scene);
}

void Model::ProcessNode(aiNode *node, const aiScene *scene)
{
    for(unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]]; 
        m_meshes.push_back(ProcessMesh(mesh, scene));			
    }

    for(unsigned int i = 0; i < node->mNumChildren; i++)
    {
        ProcessNode(node->mChildren[i], scene);
    }
} 


std::shared_ptr<Mesh> Model::ProcessMesh(aiMesh *mesh, const aiScene *scene)
{
    // data to fill
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

    // Walk through each of the mesh's vertices
    for(unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        Vertex vertex;
        glm::vec3 vector; // we declare a placeholder vector since assimp uses its own vector class that doesn't directly convert to glm's vec3 class so we transfer the data to this placeholder glm::vec3 first.
        // positions
        vector.x = mesh->mVertices[i].x;
        vector.y = mesh->mVertices[i].y;
        vector.z = mesh->mVertices[i].z;
        vertex.Position = vector;
        // normals
        vector.x = mesh->mNormals[i].x;
        vector.y = mesh->mNormals[i].y;
        vector.z = mesh->mNormals[i].z;
        vertex.Normal = vector;
        // texture coordinates
        if(mesh->mTextureCoords[0]) // does the mesh contain texture coordinates?
        {
            glm::vec2 vec;
            // a vertex can contain up to 8 different texture coordinates. We thus make the assumption that we won't 
            // use models where a vertex can have multiple texture coordinates so we always take the first set (0).
            vec.x = mesh->mTextureCoords[0][i].x; 
            vec.y = mesh->mTextureCoords[0][i].y;
            vertex.TexCoords = vec;
        }
        else
            vertex.TexCoords = glm::vec2(0.0f, 0.0f);
            vertices.push_back(vertex);
    }
    // now wak through each of the mesh's faces (a face is a mesh its triangle) and retrieve the corresponding vertex indices.
    for(unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        // retrieve all indices of the face and store them in the indices vector
        for(unsigned int j = 0; j < face.mNumIndices; j++)
		{
            indices.push_back(face.mIndices[j]);
        }
	}
	std::shared_ptr<Mesh> meshCreated(new Mesh);
	meshCreated->MakeModel(vertices, indices);
    return meshCreated;
}