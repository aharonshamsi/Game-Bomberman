#include "FontHolder.h"
#include <iostream>

sf::Font FontHolder::m_font;

void FontHolder::loadFont()
{
	if (!m_font.loadFromFile(WelcomeConst::NAME_FONT))
		std::cerr << "Loading the font file failed";
}

sf::Text FontHolder::getText()
{
	sf::Text text;
	text.setFont(m_font);
	text.setCharacterSize(100);
	return text;
}

