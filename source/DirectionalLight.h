#include "Light.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class DirectionalLight : public Light
{
	public:
		DirectionalLight();
		DirectionalLight(glm::vec3 _direction, glm::vec3 _ambient, glm::vec3 _diffuse, glm::vec3 _specular);
		~DirectionalLight();
		virtual void Update();
	private:	
		glm::vec3 m_ambient, m_diffuse, m_specular, m_direction;
};
