#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Model.h"

#include "OpenGL.h"

#include "Shader.h"
#include "stb_image.h"
//#include "Camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stdio.h>
#include <math.h>

#include "GameObject.h"
#include "Renderer.h"


unsigned int loadTexture(char const * path);

float deltaTime = 0.0f;	// Time between current frame and last frame




std::shared_ptr<Camera> cameraMain = std::make_shared<Camera>(Camera());

glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

int main(int argc, char* argv[]) {	

	//GameObject gameObject;
	//std::shared_ptr<Renderer> _ren = gameObject.AddComponent<Renderer>();
	//gameObject.Update();

	
	glm::vec3 pointLightPositions[] = {
        glm::vec3( 0.7f,  0.2f,  2.0f),
        glm::vec3( 2.3f, -3.3f, -4.0f),
        glm::vec3(-4.0f,  2.0f, -12.0f),
        glm::vec3( 0.0f,  0.0f, -3.0f)
    };
	

	OpenGL openGL;
	openGL.Setup();
	openGL.SetCamera(cameraMain);
	
	
	//shaders
	Shader ourShader("..//source/shaders/shader.vs", "..//source/shaders/shader.fs");	
	
	//Shader lightingShader("..//source/shaders/lightingShader.vs", "..//source/shaders/lightingShader.fs");	
	
	//Shader lampShader("..//source/shaders/lampShader.vs", "..//source/shaders/lampShader.fs");	

	//Shader singleColour("..//source/shaders/shader.vs", "..//source/shaders/shaderSingleColour.fs");
	
	Model cube("PLANE");
	
	//Model ourModel("..//source/models/nanosuit2/nanosuit.obj");
	
	unsigned int diffuseMap = loadTexture("..//source/textures/container2.png");
	unsigned int planeTexture = loadTexture("..//source/textures/arrow.jpg");
	
	//GRASS
	/*
	std::vector<glm::vec3> vegetation;
	vegetation.push_back(glm::vec3(-1.5f,  0.0f, -0.48f));
	vegetation.push_back(glm::vec3( 1.5f,  0.0f,  0.51f));
	vegetation.push_back(glm::vec3( 0.0f,  0.0f,  0.7f));
	vegetation.push_back(glm::vec3(-0.3f,  0.0f, -2.3f));
	vegetation.push_back(glm::vec3( 0.5f,  0.0f, -0.6f));

	unsigned int grassTexture = loadTexture("..//source/textures/blending_transparent_window.png");
	
	
	
	
	
	ourShader.use();
	ourShader.setInt("texture1", 0);
	

	lightingShader.use(); 
    lightingShader.setInt("material.diffuse", 0);
	lightingShader.setInt("material.specular", 1);
	*/
	/*
	float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top   
    }; 
	*/
	
		glm::vec3 cubePositions[] = {
		glm::vec3( 0.0f,  0.0f,  0.0f), 
		glm::vec3( 2.0f,  5.0f, -15.0f), 
		glm::vec3(-1.5f, -2.2f, -2.5f),  
		glm::vec3(-3.8f, -2.0f, -12.3f),  
		glm::vec3( 2.4f, -0.4f, -3.5f),  
		glm::vec3(-1.7f,  3.0f, -7.5f),  
		glm::vec3( 1.3f, -2.0f, -2.5f),  
		glm::vec3( 1.5f,  2.0f, -2.5f), 
		glm::vec3( 1.5f,  0.2f, -1.5f), 
		glm::vec3(-1.3f,  1.0f, -1.5f)  
	};
	
	

	while(openGL.ShouldWindowClose())
	{		

        deltaTime = openGL.deltaTime;
		openGL.ProcessInput();
		
		glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		
		ourShader.use();
		
        glm::mat4 view;
        glm::mat4 projection;
		view = cameraMain->GetViewMatrix();
        projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);
		ourShader.setMat4("view", view);
		ourShader.setMat4("projection", projection);
	
		glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, planeTexture);
		
        for (unsigned int i = 0; i < 10; i++)
        {
            // calculate the model matrix for each object and pass it to shader before drawing
            glm::mat4 model;
            model = glm::translate(model, cubePositions[i]);
            float angle = 20.0f * i;
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            ourShader.setMat4("model", model);

            cube.Draw(ourShader);
        }
		
		openGL.SwapBuffers(); 
		 

        /*
		
		std::map<float, glm::vec3> sorted;
        for (unsigned int i = 0; i < vegetation.size(); i++)
        {
            float distance = glm::length(cameraMain.Position - vegetation[i]);
            sorted[distance] = vegetation[i];
        }


		
		
		/*
		projection = glm::perspective(glm::radians(cameraMain.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        view = cameraMain.GetViewMatrix();

         // also draw the lamp object(s)
         lampShader.use();
         lampShader.setMat4("projection", projection);
         lampShader.setMat4("view", view);
    
         // we now draw as many light bulbs as we have point lights.
         glBindVertexArray(lightVAO);
         for (unsigned int i = 0; i < 4; i++)
         {
             model = glm::mat4();
             model = glm::translate(model, pointLightPositions[i]);
             model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
             lampShader.setMat4("model", model);
             glDrawArrays(GL_TRIANGLES, 0, 36);
         }
		
        ourShader.use();
		
		
        // view/projection transformations
		lightingShader.use();
        glm::mat4 projection = glm::perspective(glm::radians(cameraMain->Zoom), (float)openGL.GetWindowWidth() / (float)openGL.GetWindowHeight(), 0.1f, 100.0f);
        glm::mat4 view = cameraMain->GetViewMatrix();
        lightingShader.setMat4("projection", projection);
        lightingShader.setMat4("view", view);
		
        // render the loaded model
		glm::mat4 model = glm::mat4();
        model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // translate it down so it's at the center of the scene
        model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// it's a bit too big for our scene, so scale it down
        lightingShader.setMat4("model", model);
        ourModel.Draw(lightingShader);
		
		
		
		//PLANE
		ourShader.use();
        ourShader.setMat4("view", view);
        ourShader.setMat4("projection", projection);
		glStencilMask(0x00);
        // floor
        glBindVertexArray(planeVAO);
        glBindTexture(GL_TEXTURE_2D, planeTexture);
        ourShader.setMat4("model", glm::mat4());
        glDrawArrays(GL_TRIANGLES, 0, 6);
		
		/*
		//outline a box
		singleColour.use();
        model = glm::mat4();
        view = cameraMain.GetViewMatrix();
        projection = glm::perspective(glm::radians(cameraMain.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        singleColour.setMat4("view", view);
        singleColour.setMat4("projection", projection);

        ourShader.use();
        ourShader.setMat4("view", view);
        ourShader.setMat4("projection", projection);
		
		
        glStencilFunc(GL_ALWAYS, 1, 0xFF);
        glStencilMask(0xFF);
        // cubes
		
		
		
        glBindVertexArray(VAO);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, diffuseMap);
        model = glm::translate(model, glm::vec3(-1.0f, 0.0f, -1.0f));
        ourShader.setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        model = glm::mat4();
        model = glm::translate(model, glm::vec3(2.0f, 0.0f, 0.0f));
        ourShader.setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 36);
		/*
        // 2nd. render pass: now draw slightly scaled versions of the objects, this time disabling stencil writing.
        // Because the stencil buffer is now filled with several 1s. The parts of the buffer that are 1 are not drawn, thus only drawing 
        // the objects' size differences, making it look like borders.
        // -----------------------------------------------------------------------------------------------------------------------------
        glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
        glStencilMask(0x00);
        glDisable(GL_DEPTH_TEST);
        singleColour.use();
        float scale = 1.1;
        // cubes
        glBindVertexArray(VAO);
        glBindTexture(GL_TEXTURE_2D, diffuseMap);
        model = glm::mat4();
        model = glm::translate(model, glm::vec3(-1.0f, 0.0f, -1.0f));
        model = glm::scale(model, glm::vec3(scale, scale, scale));
        singleColour.setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        model = glm::mat4();
        model = glm::translate(model, glm::vec3(2.0f, 0.0f, 0.0f));
        model = glm::scale(model, glm::vec3(scale, scale, scale));
        singleColour.setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);
        glStencilMask(0xFF);
        glEnable(GL_DEPTH_TEST);
		
		
		//GRASS
		glBindVertexArray(VAO);
		glBindTexture(GL_TEXTURE_2D, grassTexture);  
       for (std::map<float, glm::vec3>::reverse_iterator it = sorted.rbegin(); it != sorted.rend(); ++it)
        {
            model = glm::mat4();
            model = glm::translate(model, it->second);
            ourShader.setMat4("model", model);
            glDrawArrays(GL_TRIANGLES, 0, 6);
        }
		
		*/
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
	}  
    return 0; 
}

unsigned int loadTexture(char const * path)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT); // for this tutorial: use GL_CLAMP_TO_EDGE to prevent semi-transparent borders. Due to interpolation it takes texels from next repeat 
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}






