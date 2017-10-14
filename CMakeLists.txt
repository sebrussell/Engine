# Project definition
cmake_minimum_required(VERSION 2.6)
project(OpenGL)

include_directories(
	${PROJECT_SOURCE_DIR}/libraries/glm
	${PROJECT_SOURCE_DIR}/libraries/glfw/include
	${PROJECT_SOURCE_DIR}/libraries/glad/include
	${PROJECT_SOURCE_DIR}/libraries/assimp/include
)

link_directories(
	${PROJECT_SOURCE_DIR}/libraries/assimp/lib
	${PROJECT_SOURCE_DIR}/libraries/glfw/lib
)



add_executable(techdemo
	source/main.cpp
	source/stb_image.cpp
	libraries/glad/src/glad.c
	#source/Mesh.cpp
	#source/Model.cpp
)

target_link_libraries(techdemo assimp glfw3) 








