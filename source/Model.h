#ifndef MODEL_H
#define MODEL_H

#include "stb_image.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

class Shader;

#include "Mesh.h"

enum Type
{
	CUBE,
	PLANE,
	QUAD,
	SKYBOX,
	REFLECT_CUBE,
	MODEL
};

class Model 
{
    public:
        /*  Functions   */
		Model(Type _type);
		Model(Type _type, std::string path);
		~Model();
		bool gammaCorrection;
		void ChangeTexture(unsigned int texture);
		std::vector<Texture> textures_loaded; 
        void Draw(Shader shader);	
		std::vector<Mesh> meshes;
    private:
        /*  Model Data  */
		
        
        std::string directory;
		Mesh _mesh;
        /*  Functions   */
		void LoadPrimitive(Type _type);
        void loadModel(std::string path);		
        void processNode(aiNode *node, const aiScene *scene);
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);
        std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
		unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma);
};



#endif