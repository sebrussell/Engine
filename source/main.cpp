#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Model.h"

#include "OpenGL.h"

#include "Shader.h"
#include "stb_image.h"

#include "Skybox.h"
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
std::shared_ptr<Camera> cameraFBO1 = std::make_shared<Camera>(Camera());
std::shared_ptr<Camera> cameraFBO2 = std::make_shared<Camera>(Camera());

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
	
	cameraFBO1->SetupFrameBuffer(openGL.GetWindowWidth(), openGL.GetWindowHeight());
	cameraFBO2->SetupFrameBuffer(openGL.GetWindowWidth(), openGL.GetWindowHeight());
	

	
	//shaders
	Shader ourShader("..//source/shaders/defaultShader.vs", "..//source/shaders/defaultShader.fs");	
	ourShader.CreateMatrixBuffer();
	//Shader screenShader("..//source/shaders/postProcShader.vs", "..//source/shaders/postProcShader.fs");
	//Shader greyscaleShader("..//source/shaders/postProcShader.vs", "..//source/shaders/greyscale.fs");
	//Shader blurShader("..//source/shaders/postProcShader.vs", "..//source/shaders/blur.fs");
	//Shader skyboxShader("..//source/shaders/skyboxShader.vs", "..//source/shaders/skyboxShader.fs");
	//Shader reflectShader("..//source/shaders/reflectShader.vs", "..//source/shaders/reflectShader.fs");
	//Shader blankScreenShader("..//source/shaders/blankPostShader.vs", "..//source/shaders/blankPostShader.fs");
	
	Shader geometryShader("..//source/shaders/geometryShader/normals/geometryShader.vs", "..//source/shaders/geometryShader/normals/geometryShader.fs", "..//source/shaders/geometryShader/normals/geometryShader.gs");
	
	//Shader lightingShader("..//source/shaders/lightingShader.vs", "..//source/shaders/lightingShader.fs");	
	
	//Shader instancingShader("..//source/shaders/instancing/basic.vs", "..//source/shaders/instancing/basic.fs");
	
	//Shader lampShader("..//source/shaders/lampShader.vs", "..//source/shaders/lampShader.fs");	

	//Shader singleColour("..//source/shaders/shader.vs", "..//source/shaders/shaderSingleColour.fs");
	
	Model cube(CUBE);
	Model quad(QUAD);
	Model reflect(REFLECT_CUBE);
	Model plane(PLANE);
	
	
	Skybox skybox;
	skybox.loadCubemap();
	
	
	//Model ourModel(MODEL, "..//source/models/nanosuit2/nanosuit.obj");
	//Model planet(MODEL, "..//source/models/planet/planet.obj");
	//Model rock(MODEL, "..//source/models/rock/rock.obj");
	
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
	
	/*
    unsigned int amount = 100000;
    glm::mat4* modelMatrices;
    modelMatrices = new glm::mat4[amount];
    srand(glfwGetTime()); // initialize random seed	
    float radius = 150.0;
    float offset = 25.0f;
    for (unsigned int i = 0; i < amount; i++)
    {
        glm::mat4 model;
        // 1. translation: displace along circle with 'radius' in range [-offset, offset]
        float angle = (float)i / (float)amount * 360.0f;
        float displacement = (rand() % (int)(2 * offset * 100)) / 100.0f - offset;
        float x = sin(angle) * radius + displacement;
        displacement = (rand() % (int)(2 * offset * 100)) / 100.0f - offset;
        float y = displacement * 0.4f; // keep height of asteroid field smaller compared to width of x and z
        displacement = (rand() % (int)(2 * offset * 100)) / 100.0f - offset;
        float z = cos(angle) * radius + displacement;
        model = glm::translate(model, glm::vec3(x, y, z));

        // 2. scale: Scale between 0.05 and 0.25f
        float scale = (rand() % 20) / 100.0f + 0.05;
        model = glm::scale(model, glm::vec3(scale));

        // 3. rotation: add random rotation around a (semi)randomly picked rotation axis vector
        float rotAngle = (rand() % 360);
        model = glm::rotate(model, rotAngle, glm::vec3(0.4f, 0.6f, 0.8f));

        // 4. now add to list of matrices
        modelMatrices[i] = model;
    }
	
	// configure instanced array
    // -------------------------
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, amount * sizeof(glm::mat4), &modelMatrices[0], GL_STATIC_DRAW);

    // set transformation matrices as an instance vertex attribute (with divisor 1)
    // note: we're cheating a little by taking the, now publicly declared, VAO of the model's mesh(es) and adding new vertexAttribPointers
    // normally you'd want to do this in a more organized fashion, but for learning purposes this will do.
    // -----------------------------------------------------------------------------------------------------------------------------------
    
	for (unsigned int i = 0; i < rock.meshes.size(); i++)
    {
        unsigned int VAO = rock.meshes[i].VAO;
        glBindVertexArray(VAO);
        // set attribute pointers for matrix (4 times vec4)
        glEnableVertexAttribArray(3);
        glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)0);
        glEnableVertexAttribArray(4);
        glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(glm::vec4)));
        glEnableVertexAttribArray(5);
        glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(2 * sizeof(glm::vec4)));
        glEnableVertexAttribArray(6);
        glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(3 * sizeof(glm::vec4)));


        glVertexAttribDivisor(3, 1);
        glVertexAttribDivisor(4, 1);
        glVertexAttribDivisor(5, 1);
        glVertexAttribDivisor(6, 1);

        glBindVertexArray(0);
    }
	*/
	
	
	while(openGL.ShouldWindowClose())
	{		

        deltaTime = openGL.deltaTime;
		openGL.ProcessInput();
		
		//set first camera fbo
		//cameraFBO1->Use(true);
		
		glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		glm::mat4 model = glm::mat4();		
        glm::mat4 view = cameraMain->GetViewMatrix();
        glm::mat4 projection = glm::perspective(glm::radians(cameraMain->Zoom), (float)openGL.GetWindowWidth() / (float)openGL.GetWindowHeight(), 0.1f, 1000.0f);
		ourShader.UpdateMatrix(projection, view);
		
		// draw Planet
		ourShader.use();
		cube.ChangeTexture(diffuseMap);
		cube.Draw(ourShader);

		
		ourShader.use();
		plane.ChangeTexture(planeTexture);
		model = glm::mat4();
		model = glm::translate(model, glm::vec3(0.0f, -2.75f, 0.0f));
		ourShader.setMat4("model", model);
		plane.Draw(ourShader);
		 
		/*
        instancingShader.use();
		instancingShader.setMat4("view", view);
		instancingShader.setMat4("projection", projection);
        instancingShader.setInt("texture_diffuse1", 0);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, rock.textures_loaded[0].id); // note: we also made the textures_loaded vector public (instead of private) from the model class.
        for (unsigned int i = 0; i < rock.meshes.size(); i++)
        {
            glBindVertexArray(rock.meshes[i].VAO);
            glDrawElementsInstanced(GL_TRIANGLES, rock.meshes[i].indices.size(), GL_UNSIGNED_INT, 0, amount);
            glBindVertexArray(0);
        }
		*/

		//cameraMain->Use(false);
		openGL.SwapBuffers(); 
		
		/*
		glm::mat4 model;		
        glm::mat4 view = cameraMain->GetViewMatrix();
        glm::mat4 projection = glm::perspective(glm::radians(cameraMain->Zoom), (float)openGL.GetWindowWidth() / (float)openGL.GetWindowHeight(), 0.1f, 100.0f);
		
		ourShader.use();
		
		
		ourShader.use();
		model = glm::translate(model, pointLightPositions[1]);		
        ourShader.setMat4("model", model);
		glBindTexture(GL_TEXTURE_2D, diffuseMap);
		cube.Draw(ourShader);
		
		reflectShader.use();
		model = glm::translate(model, pointLightPositions[0]);		
        reflectShader.setMat4("model", model);
        reflectShader.setVec3("cameraPos", cameraMain->Position);
        // cubes
        glBindTexture(GL_TEXTURE_CUBE_MAP, skybox.GetSkyboxTexture());
		reflect.Draw(reflectShader);
		*/
		
		/*
		ourShader.use();
        ourShader.setMat4("projection", projection);
        ourShader.setMat4("view", view);
		model = glm::mat4();
        ourShader.setMat4("model", model);
        ourModel.Draw(ourShader);
		*/
		
		/*
		skyboxShader.use();
		view = glm::mat4(glm::mat3(cameraMain->GetViewMatrix())); 
		projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);		
		skyboxShader.setMat4("view", view);
		skyboxShader.setMat4("projection", projection);
		skybox.Draw(skyboxShader);
		*/
		
		//cameraFBO1->SetFBOTexture();
		//cameraFBO2->Use(false);
		//screenShader.use();
		//quad.Draw(screenShader);

		//ourModel.ChangeTexture(cameraFBO1->textureColorbuffer);
		
		//cameraFBO2->SetFBOTexture();
		//cameraFBO1->Use(false);
		//greyscaleShader.use();
		//quad.Draw(greyscaleShader);
		
		//cameraFBO1->SetFBOTexture();
		//cameraFBO2->Use(false);
		//blurShader.use();
		//quad.Draw(blurShader);
		
		/*
		cameraFBO1->SetFBOTexture();
		cameraMain->Use(false);
		blankScreenShader.use();
		quad.Draw(blankScreenShader);
		
		
		
		
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






