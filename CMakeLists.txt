# Project definition
cmake_minimum_required(VERSION 2.6)
project(OpenGL)

include_directories(
	${PROJECT_SOURCE_DIR}/libraries/glm
	${PROJECT_SOURCE_DIR}/libraries/glfw/include
	${PROJECT_SOURCE_DIR}/libraries/glad/include
	${PROJECT_SOURCE_DIR}/libraries/assimp/include
	${PROJECT_SOURCE_DIR}/libraries/stb
)

link_directories(
	${PROJECT_SOURCE_DIR}/libraries/assimp/lib
	${PROJECT_SOURCE_DIR}/libraries/glfw/lib
)

SET(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(techdemo
	source/main.cpp
	source/stb_image.cpp	
	libraries/glad/src/glad.c
	source/Component.cpp
	source/OpenGL.cpp
	source/GameObject.cpp
	source/Skybox.cpp
	source/Shader.cpp
	source/CameraManager.cpp
	source/Transform.cpp
	source/Camera.cpp
	source/SceneManager.cpp
	source/Renderer.cpp
	source/Material.cpp
	source/Mesh.cpp
	source/ShaderManager.cpp
	source/MeshManager.cpp
	source/LightManager.cpp
	source/Light.cpp
	source/DirectionalLight.cpp
	source/Input.cpp
	source/InputHandlerScript.cpp
	source/TextWriter.cpp
	source/LightManager.cpp
	source/DirectionalLight.cpp
	source/PointLight.cpp
)

target_link_libraries(techdemo assimp glfw3)








