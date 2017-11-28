#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D texture_regular1;
uniform sampler2D texture_diffuse1;

void main()
{    	
	//FragColor =  mix(texture(texture_regular1, TexCoords), texture(texture_diffuse1, TexCoords), 0.2);
	vec4 texColor = texture(texture_regular1, TexCoords);
	FragColor = texColor;
	//FragColor = vec4(TexCoords, 0.0, 0.0);
}