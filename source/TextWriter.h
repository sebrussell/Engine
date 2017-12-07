#ifndef TEXT_H
#define TEXT_H


#include <ft2build.h>
#include FT_FREETYPE_H  

#include <iostream>

class Text
{
	public:
		Text();
		~Text();
		void Awake();
	
	private:
		FT_Library m_freeType;
		FT_Face m_face;
};

#endif