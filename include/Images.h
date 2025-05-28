#pragma once
#include <SFML/Graphics.hpp>
#include "ParticipantType.h"
#include "ImagesConst.h"
#include <vector>


class Images
{

public:

	static void loadAllTextures();
	static sf::Sprite getSprite(const ParticipantType& type, const sf::Vector2f& wantedSize);

private:

	static std::vector <sf::Texture> m_pictures;

	//private funcdtions
	static void loadPlayer();
	static void loadSmartGuard();
	static void loadStupidGuard();
	static void loadWall();
	static void loadRock();
	static void loadDoor();
	static void loadBomb();
	static void loadBombExplosion();
	static void loadGiftKillGuard();
	static void loadGiftAddTime();
	static void loadGiftFreezeGuards();
	static void loadGiftAddLife();

	static void loadWelcomGame(); // Game Backgtound inmage
	static void loadFinishGame(); // Game finish inmage
	static void loadStopGame(); // Game stop inmage

};