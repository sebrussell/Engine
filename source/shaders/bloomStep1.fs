#version 330 core
out vec4 FragColor;
  
in vec2 TexCoords;

uniform sampler2D screenTexture;

void main()
{ 
    vec4 brightColour;

	vec4 colour = texture(screenTexture, TexCoords);
	
    float brightness = dot(colour.rgb, vec3(0.2126, 0.7152, 0.0722));
	
    if(brightness > 0.99)
        brightColour = vec4(colour.rgb, 1.0);
    else
        brightColour = vec4(0.0, 0.0, 0.0, 1.0);
		
	FragColor = brightColour;
}