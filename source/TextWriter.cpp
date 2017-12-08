#include "TextWriter.h"
#include "SceneManager.h"
#include "ShaderManager.h"
#include "Shader.h"

Text::Text()
{
	
}

Text::~Text()
{
	
}

void Text::SetSceneManager(std::weak_ptr<SceneManager> _sceneManager)
{
	m_sceneManager = _sceneManager;
}

void Text::Awake()
{
   fread(ttf_buffer, 1, 1<<20, fopen("c:/windows/fonts/times.ttf", "rb"));
   stbtt_BakeFontBitmap(ttf_buffer,0, 32.0, temp_bitmap,512,512, 32,96, cdata); // no guarantee this fits!
   // can free ttf_buffer at this point
   glGenTextures(1, &ftex);
   glBindTexture(GL_TEXTURE_2D, ftex);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, 512,512, 0, GL_ALPHA, GL_UNSIGNED_BYTE, temp_bitmap);
   // can free temp_bitmap at this point
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   
   m_shader = m_sceneManager.lock()->m_shaderManager->AddShader("..//source/shaders/blankPostShader.vs", "..//source/shaders/blankPostShader.fs");
   m_shader.lock()->Use();
   m_shader.lock()->SetInt("screenTexture", 0);
}

void Text::Write(float x, float y, char *text)
{
   // assume orthographic projection with units = screen pixels, origin at top left
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, ftex);
   
   int count = 0;

   
   while (*text) {
      if (*text >= 32 && *text < 128) {
         stbtt_aligned_quad q;
         stbtt_GetBakedQuad(cdata, 512,512, *text-32, &x,&y,&q,1);//1=opengl & d3d10+,0=d3d9
		 
		 TextQuadCoordinates temp;
		 
		 temp.position[0] = q.x0;
		 temp.position[1] = q.y0;
		 temp.position[2] = 0.0f;		 
		 temp.texCoordinate[0] = q.s0;
		 temp.texCoordinate[1] = q.t1;
		 m_position.push_back(temp);
		 
		 
		 temp.position[0] = q.x1;
		 temp.position[1] = q.y0;
		 temp.position[2] = 0.0f;		 
		 temp.texCoordinate[0] = q.s1;
		 temp.texCoordinate[1] = q.t1;		 
		 m_position.push_back(temp);
		 

		 temp.position[0] = q.x1;
		 temp.position[1] = q.y1;
		 temp.position[2] = 0.0f;		 
		 temp.texCoordinate[0] = q.s1;
		 temp.texCoordinate[1] = q.t0;
		 m_position.push_back(temp);
		 

		 temp.position[0] = q.x0;
		 temp.position[1] = q.y1;
		 temp.position[2] = 0.0f;		 
		 temp.texCoordinate[0] = q.s0;
		 temp.texCoordinate[1] = q.t0;
		 m_position.push_back(temp);
		 
		 count += 4;

      }
      ++text;
   }
   
   float vertices[count * 5];
   
   for(int i = 0; i < m_position.size(); i++)
   {
	   vertices[i * 5] = m_position.at(i).position[0];
	   vertices[(i * 5) + 1] = m_position.at(i).position[1];
	   vertices[(i * 5) + 2] = m_position.at(i).position[2];
	   vertices[(i * 5) + 3] = m_position.at(i).texCoordinate[0];
	   vertices[(i * 5) + 4] = m_position.at(i).texCoordinate[1];
	   
   }
	
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);	
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	
	m_amountOfVertices = count;
   
   //MakeQuad(m_position, count); 
}

void Text::MakeQuad(std::vector<TextQuadCoordinates> m_position, int amount)
{
	
	float* cubeVertices = &m_position[0].position[0];
	
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), &cubeVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	
	m_amountOfVertices = amount;
	
}

void Text::Draw()
{
	m_shader.lock()->Use();
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, ftex);
	glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, m_amountOfVertices);	
	glBindVertexArray(0);
	glActiveTexture(GL_TEXTURE0);
}