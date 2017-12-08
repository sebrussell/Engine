#version 330 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTexCoords;

out vec2 TexCoords;

uniform vec2 screenPosition;
uniform float scale;

void main()
{
    gl_Position = vec4(screenPosition.x + (aPos.x * scale), screenPosition.y + (aPos.y * scale), 0.0, 1.0); 
    TexCoords = aTexCoords;
}  