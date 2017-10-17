#include "Input.h"

Input::Input()
{
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);    //hide and capture mouse position
}

