#include "TextWriter.h"

Text::Text()
{
	
}

Text::~Text()
{
	
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
}

void Text::Write(float x, float y, char *text)
{
   // assume orthographic projection with units = screen pixels, origin at top left
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, ftex);

   while (*text) {
      if (*text >= 32 && *text < 128) {
         stbtt_aligned_quad q;
         stbtt_GetBakedQuad(cdata, 512,512, *text-32, &x,&y,&q,1);//1=opengl & d3d10+,0=d3d9
		 TextQuadCoordinates temp;
		 
		 temp.position = glm::vec3(q.x0, q.y0, 0.0f);
		 temp.texCoordinate = glm::vec3(q.s0,q.t1, 0.0f);
		 m_position.push_back(temp);

		 
		 temp.position = glm::vec3(q.x1, q.y0, 0.0f);
		 temp.texCoordinate = glm::vec3(q.s1,q.t1, 0.0f);
		 m_position.push_back(temp);
		 
		 temp.position = glm::vec3(q.x1, q.y1, 0.0f);
		 temp.texCoordinate = glm::vec3(q.s1,q.t0, 0.0f);
		 m_position.push_back(temp);
		 
		 temp.position = glm::vec3(q.x0, q.y1, 0.0f);
		 temp.texCoordinate = glm::vec3(q.s0,q.t0, 0.0f);
		 m_position.push_back(temp);

      }
      ++text;
   }
   //glEnd();
}