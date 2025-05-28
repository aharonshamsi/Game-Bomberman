#pragma once
#include <fstream>
#include <iostream>
#include <algorithm>
#include "BasicWindow.h"
#include "GameWindowConst.h"
#include "GameInfoConst.h"
#include "MovementConsts.h"


class GameWindow: public BasicWindow {

public:

	GameWindow();

	sf::Vector2f getTopLeft(const sf::Vector2f& pressedLoc)const;
	sf::Vector2f getIndexPixel(const size_t row, const size_t col);
	sf::Vector2f getNextTopLeft(const sf::Vector2f& location, const sf::Vector2f& direction) const;

	void resetLevelSize(size_t row, size_t col);
	void resetIndex();

	const sf::Vector2f getSizeTile()const;
	const sf::Event pollEvent();

	void playerFailedMusicPlay();
	void playerFailedMusicStop();
	void playerMoveMusicPlay();
	void playerMoveMusicStop();
	void finishGameMusicPlay();
	void finishGameMusicStop();
	void drawImageStopGame();

	void draw(const sf::RectangleShape& shape);
	void draw(const sf::Text& text);
	void draw(const sf::Sprite& sprite);


private:

	size_t m_rows;
	size_t m_cols;
	sf::Vector2f m_sizeTile;
	std::vector<std::vector<sf::Vector2f>> m_boardIndex;

	sf::Music m_playerFailedMusic;
	sf::Music m_finishGameMusic;
	sf::Music m_moveLevelMusic;

	sf::Sprite m_stopGame;

	bool inArea(const sf::Vector2f& newLocation) const;
	void loadAllFileMusic();
};
