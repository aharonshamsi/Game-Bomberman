#pragma once
#include <SFML/Graphics.hpp>
#include "FontHolder.h"
#include "ButtonConst.h"


class Button
{

public:

	Button(const sf::Vector2f& size, const sf::Vector2f& loc, const std::string& buttonName);
	
	void drawButton(sf::RenderWindow& window);
	void setOutlineColor(const sf::Color& color);

private:

	sf::RectangleShape m_shape;
	const sf::Vector2f m_location;
	sf::Text m_text;

	void loadShape();
	void loadText(const std::string& buttonName);
};
