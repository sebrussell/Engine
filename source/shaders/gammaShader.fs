#version 330 core
out vec4 FragColor;
  
in vec2 TexCoords;

uniform sampler2D screenTexture;
uniform float gamma = 2.2;

void main()
{ 
	vec4 colour = texture(screenTexture, TexCoords);
	vec4 result = pow(colour, vec4(1.0/gamma));
    FragColor = result;
}