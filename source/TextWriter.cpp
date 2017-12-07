#include "TextWriter.h"

Text::Text()
{
	
}

Text::~Text()
{
	
}

void Text::Awake()
{
	if (FT_Init_FreeType(&m_freeType))
	{
		std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
	}

	
	if (FT_New_Face(m_freeType, "fonts/arial.ttf", 0, &m_face))
	{
		std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl; 
	}
}