#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec3 Position;
in vec2 TexCoords;

uniform vec3 cameraPos;
uniform sampler2D texture_regular1;
uniform sampler2D texture_diffuse1;
uniform sampler2D texture_environment1;
uniform samplerCube skybox;

void main()
{             
    vec3 I = normalize(Position - cameraPos);
    vec3 R = reflect(I, normalize(Normal));
	
	vec3 reflect = texture(skybox, R).rgb * texture(texture_environment1, TexCoords).rgb;
	vec3 other = texture(texture_regular1, TexCoords).rgb * (1 - texture(texture_environment1, TexCoords).rgb);
	vec3 more = texture(texture_diffuse1, TexCoords).rgb * (1 - texture(texture_environment1, TexCoords).rgb);
	
	vec3 result = mix(other, reflect, 0.5f);
	result = mix(more, reflect, 0.5f);

	FragColor = vec4(result, 1.0);
}  