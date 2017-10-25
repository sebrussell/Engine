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

class Model 
{
    public:
        /*  Functions   */
        Model(std::string path);
		void MakeCube();
		void MakePlane();
        void Draw(Shader shader);	
    private:
        /*  Model Data  */
		std::vector<Texture> textures_loaded; 
        std::vector<Mesh> meshes;
        std::string directory;
		Mesh _mesh;
        /*  Functions   */
        void loadModel(std::string path);
        void processNode(aiNode *node, const aiScene *scene);
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);
        std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
		unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma);
};



#endif