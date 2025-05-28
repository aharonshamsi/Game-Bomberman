#pragma once
#include <iostream>
#include <memory>
#include "WelcomeWindow.h"
#include "GameWindow.h"
#include "GameInfo.h"
#include "CharacterId.h"


#include "Player.h"
#include "SmartGuard.h"
#include "StupidGuard.h"
#include "Wall.h"
#include "Door.h"
#include "Rock.h"
#include "Bomb.h"
#include "GiftKillGuard.h"
#include "GiftAddTime.h"
#include "GiftFreezeGuards.h"
#include "GiftAddLife.h"


class GameManager {

public:
	GameManager();

	void runGameMamager();

private:
	GameWindow m_gameWindow;
	GameInfo m_gameInfo;

	std::vector <std::unique_ptr<DynamicParticipant>> m_dynamic;
	std::vector <std::unique_ptr<StaticParticipant>> m_static;
	std::vector < std::unique_ptr<Bomb>> m_bombs;

	bool m_levelReady; // Game window loading finished

	void managerCollision(sf::Vector2f& newDirection, sf::Vector2f& newTopLeft, const int i);
	void managerBombCollision(sf::Vector2f& newDirection, sf::Vector2f& newTopLeft, const int i);

	void readFileLevel(std::fstream& fileLevel, size_t& rows, size_t& cols);
	void initializerVectorFromFile(std::fstream& fileLevel, size_t& guards);
	void handleMovement(sf::Clock& clock);
	void updateWindow(); 

	void deleteParticipantBombs();
	void deleteParticipantDynamic();
	void deleteParticipantStatic();
	
	void addGifts(const sf::Vector2f& locGift, const int randGift);
	void playerLostLife();
	void playerMoveLevel();
	void finishGame();
	void stopGame();
};
