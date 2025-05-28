#pragma once
#include <SFML/Graphics.hpp>
#include "FontHolder.h"
#include "GameInfoConst.h"
#include <SFML/Audio.hpp>


class GameInfo {

public:
	GameInfo();

	unsigned int getLevel()const;
	unsigned int getScore()const;
	int getLives()const;

	bool getKillGuard()const;
	const sf::RectangleShape& getShapeInfo()const;
	const sf::Text& getTextInfo()const;
	float getCountDown()const;
	const sf::Vector2f getLocPlayer()const;
	sf::Vector2f getLocGift()const;
	bool getActiveBomb()const;
	bool getNewGift()const;
	void getThrowBombPlay();
	void playTakingGift();
	bool getFreezeGuards();

	void setLocPlayer(const sf::Vector2f locPlayer);
	void setActiveBomb(bool activeBomb);
	void setLevel(unsigned int level);
	void setLives(int lives);
	void setScore(unsigned int score);
	void setmCountDown(const float countDown);
	void setKillGuard(const bool killGuard);
	void setNewGift(bool newGift);
	void setLocGift(sf::Vector2f locGift);
	void setFreezeGuards();

	void initializer(size_t guards);
	void updateInfo();


private:
	
	sf::RectangleShape m_shape;
	sf::Text m_text;

	unsigned int m_level;
	unsigned int m_score;
	unsigned int m_possiblePoints;
	int m_lives;

	sf::Clock m_timer;
	float m_countDown;

	sf::Vector2f m_locPlayer; 
	bool m_activeBomb;

	bool m_killGuard;
	bool m_newGift; 

	sf::Vector2f m_locGift; 
	sf::Music m_throwBombMusic;
	sf::Music m_takingGift;
	
	sf::Time m_freezeTime;
	sf::Clock m_freezeClock;
	bool m_freezeGuards;

	void updateRemainingTime(int& minutes, int& seconds);
	void loadFile();
};

