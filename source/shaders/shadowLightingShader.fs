#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

struct Material {
	sampler2D diffuseTexture;
	sampler2D specularTexture;
	sampler2D environmentTexture;
	float shininess;
	//vec3 objectColour;
};

struct DirectionalLight {
    vec3 direction;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};  

struct PointLight {    
    vec3 position;
    
    float constant;
    float linear;
    float quadratic;  

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};  
#define NR_POINT_LIGHTS 1 



uniform vec3 viewPos;

uniform DirectionalLight dirLight;
uniform PointLight pointLights[NR_POINT_LIGHTS];

uniform samplerCube skybox;
uniform Material material;


vec4 CalculateDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDir); 
vec4 CalculatePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);   


void main()
{   	
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);
	
	vec4 result = CalculateDirectionalLight(dirLight, norm, viewDir);
	
	for(int i = 0; i < NR_POINT_LIGHTS; i++)
	{
        result += CalculatePointLight(pointLights[i], norm, FragPos, viewDir);  
	}
	
	FragColor = result;
	//FragColor = vec4(dirLight.specular, 1.0);
}

vec4 CalculateDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);
    float diff = max(dot(normal, lightDir), 0.0);

    vec3 halfwayDir = normalize(lightDir + viewDir);  
    float spec = pow(max(dot(normal, halfwayDir), 0.0), material.shininess);

	vec4 ambient = vec4(light.ambient, 1.0) * vec4(texture(material.diffuseTexture, TexCoords));
    vec4 diffuse = vec4(light.diffuse, 1.0) * diff * vec4(texture(material.diffuseTexture, TexCoords));  
	vec4 specular = vec4(light.specular, 1.0) * spec * (texture(material.specularTexture, TexCoords));

    return (ambient + diffuse + specular);
}  

vec4 CalculatePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);

    float diff = max(dot(normal, lightDir), 0.0);
    vec3 halfwayDir = normalize(lightDir + viewDir);  
    float spec = pow(max(dot(normal, halfwayDir), 0.0), material.shininess);

    float distance    = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));   
	

    vec4 ambient = vec4(light.ambient, 1.0) * vec4(texture(material.diffuseTexture, TexCoords));
    vec4 diffuse = vec4(light.diffuse, 1.0) * diff * vec4(texture(material.diffuseTexture, TexCoords));  
	vec4 specular = vec4(light.specular, 1.0) * spec * (texture(material.specularTexture, TexCoords));
    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
} 

