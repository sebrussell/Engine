#version 330 core
out vec4 FragColor;
  
in vec2 TexCoords;

uniform sampler2D scene;
uniform sampler2D bloomBlur;
uniform float exposure = 1.0;

void main()
{             
    const float gamma = 2.2;
	
    vec3 hdrColor = texture(scene, TexCoords).rgb;    
	
    vec3 bloomColor = texture(bloomBlur, TexCoords).rgb;
	
    hdrColor += bloomColor; // additive blending

    vec3 result = vec3(1.0) - exp(-hdrColor * exposure);

    FragColor = vec4(result, 1.0);
} 