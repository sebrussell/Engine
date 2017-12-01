#version 330 core
out vec4 FragColor;

in VS_OUT {
    vec3 FragPos;
    vec3 Normal;
    vec2 TexCoords;
    vec4 FragPosLightSpace;
} fs_in;

struct Material {
	sampler2D diffuseTexture;
	sampler2D specularTexture;
	sampler2D environmentTexture;
	sampler2D shadowMap;
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

uniform vec3 lightPos;
uniform vec3 viewPos;

uniform DirectionalLight dirLight;
uniform PointLight pointLights[NR_POINT_LIGHTS];

uniform samplerCube skybox;
uniform Material material;

vec3 lightDir;

vec4 CalculateDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDir, float shadow); 
vec4 CalculatePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir, float shadow);   
float ShadowCalculation(vec4 fragPosLightSpace);
vec4 Lighting(float shadow);

void main()
{   	
    //vec3 norm = normalize(fs_in.Normal);
    //vec3 viewDir = normalize(viewPos - fs_in.FragPos);
	
	float shadow = ShadowCalculation(fs_in.FragPosLightSpace);    
	
	//vec4 result = CalculateDirectionalLight(dirLight, norm, viewDir, shadow);
	
	//for(int i = 0; i < NR_POINT_LIGHTS; i++)
	//{
    //    result += CalculatePointLight(pointLights[i], norm, fs_in.FragPos, viewDir, shadow);  
	//}
	
	FragColor = Lighting(shadow);

	//FragColor = vec4(1.0, 1.0, 1.0, 1.0);
}

vec4 Lighting(float shadow)
{
    vec3 color = texture(material.diffuseTexture, fs_in.TexCoords).rgb;
    vec3 normal = normalize(fs_in.Normal);
    vec3 lightColor = vec3(1.0);
    // ambient
    vec3 ambient = 0.15 * color;
    // diffuse
    vec3 lightDir = normalize(lightPos - fs_in.FragPos);
    float diff = max(dot(lightDir, normal), 0.0);
    vec3 diffuse = diff * lightColor;
    // specular
    vec3 viewDir = normalize(viewPos - fs_in.FragPos);
    float spec = 0.0;
    vec3 halfwayDir = normalize(lightDir + viewDir);  
    spec = pow(max(dot(normal, halfwayDir), 0.0), 64.0);
    vec3 specular = spec * lightColor;    

     
    vec3 lighting = (ambient + (1.0 - shadow) * (diffuse + specular)) * color;    
    
	//vec3 lighting = ambient + ((1.0 - shadow) * diffuse);
	
    return vec4(lighting, 1.0);
}

vec4 CalculateDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDir, float shadow)
{
    lightDir = normalize(-light.direction);
    float diff = max(dot(normal, lightDir), 0.0);

    vec3 halfwayDir = normalize(lightDir + viewDir);  
    float spec = pow(max(dot(normal, halfwayDir), 0.0), material.shininess);

	vec4 ambient = vec4(light.ambient, 1.0) * vec4(texture(material.diffuseTexture, fs_in.TexCoords));
    vec4 diffuse = vec4(light.diffuse, 1.0) * diff * vec4(texture(material.diffuseTexture, fs_in.TexCoords));  
	vec4 specular = vec4(light.specular, 1.0) * spec * (texture(material.specularTexture, fs_in.TexCoords));

    return (ambient + (1.0 - shadow) * (diffuse + specular));
}  

vec4 CalculatePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir, float shadow)
{
    lightDir = normalize(light.position - fragPos);

    float diff = max(dot(normal, lightDir), 0.0);
    vec3 halfwayDir = normalize(lightDir + viewDir);  
    float spec = pow(max(dot(normal, halfwayDir), 0.0), material.shininess);

    float distance    = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));   
	

    vec4 ambient = vec4(light.ambient, 1.0) * vec4(texture(material.diffuseTexture, fs_in.TexCoords));
    vec4 diffuse = vec4(light.diffuse, 1.0) * diff * vec4(texture(material.diffuseTexture, fs_in.TexCoords));  
	vec4 specular = vec4(light.specular, 1.0) * spec * (texture(material.specularTexture, fs_in.TexCoords));
    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;
    return (ambient + (1.0 - shadow) * (diffuse + specular));
} 

float ShadowCalculation(vec4 fragPosLightSpace)
{
    // perform perspective divide
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    // transform to [0,1] range
    projCoords = projCoords * 0.5 + 0.5;
	

	
    // get closest depth value from light's perspective (using [0,1] range fragPosLight as coords)
    float closestDepth = texture(material.shadowMap, projCoords.xy).r; 
    // get depth of current fragment from light's perspective
    float currentDepth = projCoords.z;
    // check whether current frag pos is in shadow
	float bias = max(0.05 * (1.0 - dot(fs_in.Normal, lightDir)), 0.005); 
    
	float shadow = 0.0;
	vec2 texelSize = 1.0 / textureSize(material.shadowMap, 0);
	for(int x = -1; x <= 1; ++x)
	{
		for(int y = -1; y <= 1; ++y)
		{
			float pcfDepth = texture(material.shadowMap, projCoords.xy + vec2(x, y) * texelSize).r; 
			shadow += currentDepth - bias > pcfDepth ? 1.0 : 0.0;        
		}    
	}
	shadow /= 9.0;

	if(projCoords.z > 1.0)
	{
		shadow = 0.0;
	}
	
    return shadow;
}  