#version 330 core
out vec4 FragColor;
  
in vec2 TexCoords;

uniform sampler2D screenTexture;

void main()
{ 
    vec4 colour = texture(screenTexture, TexCoords);
	if(colour.w == 0.0)
	{
		FragColor = vec4(0.0, 0.0, 0.0, 0.0);
	}
	else
	{
		FragColor = vec4(1.0, 1.0, 0.0, colour.r);
	}
}