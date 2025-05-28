#pragma once
#include "Participant.h"
#include "GameWindow.h"
#include "BombConst.h"

class Bomb : public Participant {

public:
	Bomb(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	bool hasExploded() const;
	bool shouldRemove() const;
	void exploded();


	sf::Vector2f getExplosionLocRight()const;
	sf::Vector2f getExplosionLocLeft()const;
	sf::Vector2f getExplosionLocUp()const;
	sf::Vector2f getExplosionLocDown()const;

	void setExplodeRight(bool explodeRight);
	void setExplodeLeft(bool explodeLeft);
	void setExplodeUp(bool explodeUp);
	void setExplodeDown(bool explodeDown);

	void draw(GameWindow& gameWindow);

	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Participant& object)override;
	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Player& player)override {};
	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, SmartGuard& object)override {};
	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, StupidGuard& stupidGuard)override {};
	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Bomb& bomb)override {};

private:

	sf::Sprite m_bombExplosion;
	sf::Clock m_launchTime;
	sf::Time m_countDown;
	sf::Time m_explosionTime;
	sf::Music m_countDownMusic;
	sf::Text m_countDownText;
	sf::Vector2f m_tileSize;
	sf::Music m_bombExplodeMusic; 

	bool m_countDownPlay;
	bool m_soundPlayed;
	bool m_isExploded;

	// location Bomb
	sf::Vector2f m_explosionLocCenter;
	sf::Vector2f m_explosionLocRight;
	sf::Vector2f m_explosionLocLeft;
	sf::Vector2f m_explosionLocUp;
	sf::Vector2f m_explosionLocDown;

	bool m_explodeRight;
	bool m_explodeLeft;
	bool m_explodeUp;
	bool m_explodeDown;

	void loadFileMusic();
	void locationCountDown();
};
