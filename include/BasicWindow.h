#pragma once
#include  <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Images.h"


class BasicWindow {

public:

	BasicWindow(const sf::Vector2f& size, const std::string& nameWindow, const sf::Sprite& backgroundPicture);

	bool isopen() const;
	void close();
	void clear();
	void display();

	void playBackgroundMusicMusic();
	void stopBackgroundMusicMusic();
	void setBackgroundLoop(bool loop);
	void drawBackgroundPicture();


protected:

	const sf::Vector2f m_windowSize;
	sf::RenderWindow m_window;
	sf::Music m_backgroundMusic;
	sf::Sprite m_backgroundPicture;
	
};
