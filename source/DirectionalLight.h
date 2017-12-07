#include "Light.h"
#include "Component.h"

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
		virtual void Awake();
	private:	
		glm::vec3 m_direction;
  
		glm::vec3 m_ambient;
		glm::vec3 m_diffuse;
		glm::vec3 m_specular;
};
