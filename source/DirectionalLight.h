#include "Light.h"

class DirectionalLight : public Light
{
	public:
		DirectionalLight();
		DirectionalLight(glm::vec3 _direction, glm::vec3 _ambient, glm::vec3 _diffuse, glm::vec3 _specular);
		~DirectionalLight();
	private:	
		glm::vec3 m_ambient, m_diffuse, m_specular, m_direction;
};
