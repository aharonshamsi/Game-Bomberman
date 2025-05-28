#include "Button.h"

Button::Button(const sf::Vector2f& size, const sf::Vector2f& loc, const std::string& buttonName)
	:m_shape(size), m_location(loc), m_text(FontHolder::getText())
{
	m_text.setCharacterSize(WelcomeConst::SIZE_FONT_BUTTON);
	loadShape();
	loadText(buttonName);
}


void Button::drawButton(sf::RenderWindow& window)
{
	window.draw(m_shape);
	window.draw(m_text);
}

void Button::setOutlineColor(const sf::Color& color)
{
	m_shape.setOutlineColor(color);
}

void Button::loadShape()
{
	m_shape.setPosition(m_location);
	m_shape.setFillColor(ButtonConst::COLOR_SHAPE); 
	m_shape.setOutlineThickness(ButtonConst::FRAME_THICKNESS); 
	m_shape.setOutlineColor(ButtonConst::COLOR_THICKNESS); 
}


void Button::loadText(const std::string& buttonName)
{
	m_text.setString(buttonName);
	m_text.setPosition(
		m_shape.getPosition().x + (m_shape.getSize().x - m_text.getGlobalBounds().width) / 2,
		m_shape.getPosition().y + (m_shape.getSize().y - m_text.getGlobalBounds().height) / 2 - m_text.getGlobalBounds().top
	);
}

