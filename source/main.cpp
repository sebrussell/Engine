#include <glad/glad.h>
#include <GLFW/glfw3.h>

//#include "Model.h"
//#include "OpenGL.h"
#include "Shader.h"
//#include "stb_image.h"

#include "SceneManager.h"
#include "CameraManager.h"
#include "ShaderManager.h"
#include "GameObject.h"
#include "Camera.h"
#include "Transform.h"
#include "OpenGL.h"
#include "Material.h"
#include "Skybox.h"
#include "MeshManager.h"
#include "DirectionalLight.h"
#include "Light.h"
#include "Mesh.h"


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stdio.h>
#include <math.h>


#include "Renderer.h"

float deltaTime = 0.0f;	// Time between current frame and last frame

glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

int main(int argc, char* argv[]) {	

	std::shared_ptr<SceneManager> sceneManager(new SceneManager);	
	sceneManager->Awake();
	
	/*
	std::weak_ptr<GameObject> cubeOne = sceneManager->CreateGameObject();
	cubeOne.lock()->AddComponent<Renderer>();	
	cubeOne.lock()->GetComponent<Renderer>()->Awake();
	cubeOne.lock()->GetComponent<Renderer>()->SetMesh(CUBE);
	cubeOne.lock()->GetComponent<Renderer>()->SetShader(sceneManager->m_shaderManager->AddShader("..//source/shaders/reflectShader.vs", "..//source/shaders/reflectShader.fs"));
	cubeOne.lock()->GetComponent<Renderer>()->GetShader().lock()->CreateMatrixBuffer();
	cubeOne.lock()->GetComponent<Renderer>()->GetShader().lock()->Use();
	cubeOne.lock()->GetComponent<Renderer>()->GetShader().lock()->SetInt("texture_regular1", 0);
	cubeOne.lock()->GetComponent<Renderer>()->GetShader().lock()->SetInt("texture_diffuse1", 1);
	cubeOne.lock()->GetComponent<Renderer>()->GetShader().lock()->SetInt("texture_environment1", 2);
	cubeOne.lock()->GetComponent<Transform>()->m_position = glm::vec3(0.0f, 0.0f, -2.0f);
	cubeOne.lock()->GetComponent<Renderer>()->m_material->LoadTexture("..//source/textures/container2.png");
	cubeOne.lock()->GetComponent<Renderer>()->m_material->LoadTexture("..//source/textures/arrow.jpg");
	cubeOne.lock()->GetComponent<Renderer>()->m_material->LoadTexture("..//source/textures/container2_environment.png");
	cubeOne.lock()->GetComponent<Renderer>()->m_material->LoadTexture(sceneManager->m_skybox->GetSkyboxTexture(), CubeMap);
	*/
	
	std::weak_ptr<GameObject> light = sceneManager->CreateGameObject();
	light.lock()->AddComponent<Renderer>();	
	light.lock()->GetComponent<Renderer>()->Awake();
	light.lock()->GetComponent<Renderer>()->SetMesh(CUBE);
	light.lock()->GetComponent<Renderer>()->SetShader(sceneManager->m_shaderManager->AddShader("..//source/shaders/defaultShader.vs", "..//source/shaders/defaultShader.fs"));
	light.lock()->GetComponent<Renderer>()->GetShader().lock()->CreateMatrixBuffer();
	light.lock()->GetComponent<Renderer>()->GetShader().lock()->Use();
	light.lock()->GetComponent<Renderer>()->m_material->SetColour(glm::vec3(1.0, 1.0, 1.0));
	light.lock()->GetComponent<Transform>()->m_position = glm::vec3(5.0f, 0.0f, -2.0f);
	
	std::weak_ptr<GameObject> dirLight = sceneManager->CreateGameObject();
	dirLight.lock()->AddComponent<DirectionalLight>();	
	dirLight.lock()->GetComponent<DirectionalLight>()->Awake();
	dirLight.lock()->GetComponent<DirectionalLight>()->SetShader(sceneManager->m_shaderManager->AddShader("..//source/shaders/lightingShader.vs", "..//source/shaders/lightingShader.fs"));
	dirLight.lock()->GetComponent<DirectionalLight>()->GetShader();
	
	
	std::weak_ptr<GameObject> cubeTwo = sceneManager->CreateGameObject();
	cubeTwo.lock()->AddComponent<Renderer>();	
	cubeTwo.lock()->GetComponent<Renderer>()->Awake();
	cubeTwo.lock()->GetComponent<Renderer>()->SetMesh(TRANSPARENT_WINDOW);
	cubeTwo.lock()->GetComponent<Renderer>()->SetShader(sceneManager->m_shaderManager->AddShader("..//source/shaders/lightingShader.vs", "..//source/shaders/lightingShader.fs"));
	cubeTwo.lock()->GetComponent<Renderer>()->GetShader().lock()->CreateMatrixBuffer();
	cubeTwo.lock()->GetComponent<Renderer>()->GetShader().lock()->Use();
	cubeTwo.lock()->GetComponent<Renderer>()->GetShader().lock()->SetInt("material.diffuseTexture", 0);
	cubeTwo.lock()->GetComponent<Renderer>()->GetShader().lock()->SetInt("material.specularTexture", 1);
	cubeTwo.lock()->GetComponent<Renderer>()->GetShader().lock()->SetInt("material.environmentTexture", 2);
	cubeTwo.lock()->GetComponent<Renderer>()->GetShader().lock()->SetInt("skybox", 3);
	cubeTwo.lock()->GetComponent<Renderer>()->GetShader().lock()->SetFloat("material.shininess", 64.0f);
	cubeTwo.lock()->GetComponent<Transform>()->m_position = glm::vec3(1.0f, 0.0f, -4.0f);
	cubeTwo.lock()->GetComponent<Renderer>()->m_material->LoadTexture("..//source/textures/blending_transparent_window.png", false);
	cubeTwo.lock()->GetComponent<Renderer>()->m_material->LoadTexture("..//source/textures/container2_specular.jpg", false);
	cubeTwo.lock()->GetComponent<Renderer>()->m_material->LoadTexture("..//source/textures/container2_environment.png", false);
	cubeTwo.lock()->GetComponent<Renderer>()->m_material->LoadTexture(sceneManager->m_skybox->GetSkyboxTexture(), CubeMap);
	cubeTwo.lock()->m_transparent = true;
	
	
	std::weak_ptr<GameObject> cubeThree = sceneManager->CreateGameObject();
	cubeThree.lock()->AddComponent<Renderer>();	
	cubeThree.lock()->GetComponent<Renderer>()->Awake();
	cubeThree.lock()->GetComponent<Renderer>()->SetMesh(CUBE);
	cubeThree.lock()->GetComponent<Renderer>()->SetShader(sceneManager->m_shaderManager->AddShader("..//source/shaders/lightingShader.vs", "..//source/shaders/lightingShader.fs"));
	cubeThree.lock()->GetComponent<Renderer>()->GetShader().lock()->Use();
	cubeThree.lock()->GetComponent<Renderer>()->GetShader().lock()->SetFloat("material.shininess", 30.0f);
	cubeThree.lock()->GetComponent<Transform>()->m_position = glm::vec3(1.0f, 0.0f, -6.0f);
	cubeThree.lock()->GetComponent<Renderer>()->m_material->LoadTexture("..//source/textures/container2.png", false);
	cubeThree.lock()->GetComponent<Renderer>()->m_material->LoadTexture("..//source/textures/container2_specular.jpg", false);
	cubeThree.lock()->GetComponent<Renderer>()->m_material->LoadTexture("..//source/textures/container2_specular.jpg", false);
	cubeThree.lock()->GetComponent<Renderer>()->m_material->LoadTexture(sceneManager->m_skybox->GetSkyboxTexture(), CubeMap);
	cubeThree.lock()->m_transparent = false;
	
	std::weak_ptr<GameObject> plane = sceneManager->CreateGameObject();
	plane.lock()->AddComponent<Renderer>();	
	plane.lock()->GetComponent<Renderer>()->Awake();
	plane.lock()->GetComponent<Renderer>()->SetMesh(PLANE);
	plane.lock()->GetComponent<Renderer>()->SetShader(sceneManager->m_shaderManager->AddShader("..//source/shaders/lightingShader.vs", "..//source/shaders/lightingShader.fs"));
	plane.lock()->GetComponent<Renderer>()->GetShader().lock()->Use();
	plane.lock()->GetComponent<Renderer>()->GetShader().lock()->SetFloat("material.shininess", 30.0f);
	plane.lock()->GetComponent<Transform>()->m_position = glm::vec3(0.0f, -0.2f, 0.0f);
	plane.lock()->GetComponent<Renderer>()->m_material->LoadTexture("..//source/textures/wood.jpg", false);
	plane.lock()->GetComponent<Renderer>()->m_material->LoadTexture("..//source/textures/white.jpg", false);
	plane.lock()->GetComponent<Renderer>()->m_material->LoadTexture("..//source/textures/black.jpg", false);
	plane.lock()->GetComponent<Renderer>()->m_material->LoadTexture(sceneManager->m_skybox->GetSkyboxTexture(), CubeMap);
	
	
	while(sceneManager->m_openGL->ShouldWindowClose())
	{
		sceneManager->m_openGL->ProcessInput();
		//Scene Manager Process Input
		glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		
		
		sceneManager->Update();
		
		
		light.lock()->GetComponent<Transform>()->ChangePosition(glm::vec3(-0.01f, 0.0f, 0.0f));
		
		plane.lock()->GetComponent<Renderer>()->GetShader().lock()->Use();
        plane.lock()->GetComponent<Renderer>()->GetShader().lock()->SetVec3("viewPos", sceneManager->m_cameraManager->m_mainCamera.lock()->GetPosition());
        plane.lock()->GetComponent<Renderer>()->GetShader().lock()->SetVec3("pointLights[0].position", light.lock()->GetComponent<Transform>()->m_position);
        plane.lock()->GetComponent<Renderer>()->GetShader().lock()->SetVec3("pointLights[0].ambient", glm::vec3(0.05f, 0.05f, 0.05f));
        plane.lock()->GetComponent<Renderer>()->GetShader().lock()->SetVec3("pointLights[0].diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
        plane.lock()->GetComponent<Renderer>()->GetShader().lock()->SetVec3("pointLights[0].specular", glm::vec3(1.0f, 1.0f, 1.0f));
        plane.lock()->GetComponent<Renderer>()->GetShader().lock()->SetFloat("pointLights[0].constant", 1.0f);
        plane.lock()->GetComponent<Renderer>()->GetShader().lock()->SetFloat("pointLights[0].linear", 0.09);
        plane.lock()->GetComponent<Renderer>()->GetShader().lock()->SetFloat("pointLights[0].quadratic", 0.032);
		
		
		
		sceneManager->m_openGL->SwapBuffers(); 
	}
	
	sceneManager->Delete();
	return 0;
}

	
	//cameraFBO1->SetupFrameBuffer(openGL.GetWindowWidth(), openGL.GetWindowHeight());
	//cameraFBO2->SetupFrameBuffer(openGL.GetWindowWidth(), openGL.GetWindowHeight());
	
	/*
	
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
	
	
	//Skybox skybox;
	//skybox.loadCubemap();
	
	
	//Model ourModel(MODEL, "..//source/models/nanosuit2/nanosuit.obj");
	//Model planet(MODEL, "..//source/models/planet/planet.obj");
	//Model rock(MODEL, "..//source/models/rock/rock.obj");
	
	unsigned int diffuseMap = loadTexture("..//source/textures/container2.png");
	unsigned int planeTexture = loadTexture("..//source/textures/arrow.jpg");
	
	

	
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
	/*
	
	while(openGL.ShouldWindowClose())
	{		
		openGL.ProcessInput();
		
		//set first camera fbo
		//cameraFBO1->Use(true);
		
		glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		glm::mat4 model = glm::mat4();		
        glm::mat4 view;// = cameraMain->GetViewMatrix();
        glm::mat4 projection;// = glm::perspective(glm::radians(cameraMain->Zoom), (float)openGL.GetWindowWidth() / (float)openGL.GetWindowHeight(), 0.1f, 1000.0f);
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
		//openGL.SwapBuffers(); 
		
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
		
		*/
		
		/*
		*/
		
		/*
		*/
		/*
		
        /*
		
		std::map<float, glm::vec3> sorted;
        for (unsigned int i = 0; i < vegetation.size(); i++)
        {
            float distance = glm::length(cameraMain.Position - vegetation[i]);
            sorted[distance] = vegetation[i];
        }
		*/

		
		
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
		*/
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
		*/
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
*/





