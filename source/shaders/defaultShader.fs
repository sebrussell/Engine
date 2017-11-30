#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D texture_regular1;
uniform sampler2D texture_diffuse1;
uniform vec3 objectColour;
uniform bool useColour;

void main()
{    	
	vec4 texColour;
	if(useColour)
	{
		texColour = vec4(objectColour, 1.0);
	}
	else
	{
		//FragColor =  mix(texture(texture_regular1, TexCoords), texture(texture_diffuse1, TexCoords), 0.2);
		texColour = texture(texture_regular1, TexCoords);
	}
	
	FragColor = texColour;
	
	
}