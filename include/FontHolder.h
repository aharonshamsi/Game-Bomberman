#pragma once
#include <SFML/Graphics.hpp>
#include "WelcomeConst.h"


class FontHolder {

public:
	static void loadFont();
	static sf::Text getText();

private:
	static sf::Font m_font;

};
