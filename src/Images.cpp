#include "Images.h"

std::vector <sf::Texture> Images::m_pictures;


void Images::loadAllTextures()
{
	loadPlayer();
	loadSmartGuard();
	loadStupidGuard();
	loadDoor();
	loadRock();
	loadWall();
	loadBomb();
	loadBombExplosion();
	loadGiftKillGuard();
	loadGiftAddTime();
	loadGiftFreezeGuards();
	loadGiftAddLife();

	loadWelcomGame();
	loadFinishGame();
	loadStopGame();

}


sf::Sprite Images::getSprite(const ParticipantType& type, const sf::Vector2f& wantedSize)
{
	int index = static_cast<int>(type);

	sf::Sprite sprite;
	sprite.setTexture(m_pictures[index]);
	float scaleX = wantedSize.x / m_pictures[index].getSize().x;
	float scaleY = wantedSize.y / m_pictures[index].getSize().y;
	sprite.setScale(sf::Vector2f(scaleX, scaleY));

	return sprite;
}



void Images::loadPlayer()
{
	if (!m_pictures.emplace_back().loadFromFile(ImagesConst::NAME_PLAYER))
		std::cerr << "The image named " << ImagesConst::NAME_PLAYER << " was not loaded\n";
}


void Images::loadSmartGuard()
{
	if (!m_pictures.emplace_back().loadFromFile(ImagesConst::NAME_SMART_GUARD))
		std::cerr << "The image named " << ImagesConst::NAME_SMART_GUARD << " was not loaded\n";

}

void Images::loadStupidGuard()
{
	if (!m_pictures.emplace_back().loadFromFile(ImagesConst::NAME_STUPID_GUARD))
		std::cerr << "The image named " << ImagesConst::NAME_STUPID_GUARD << " was not loaded\n";
}


void Images::loadWall()
{
	if (!m_pictures.emplace_back().loadFromFile(ImagesConst::NAME_WALL))
		std::cerr << "The image named " << ImagesConst::NAME_WALL << " was not loaded\n";

}

void Images::loadRock()
{
	if (!m_pictures.emplace_back().loadFromFile(ImagesConst::NAME_ROCK))
		std::cerr << "The image named " << ImagesConst::NAME_ROCK << " was not loaded\n";
}

void Images::loadDoor()
{
	if (!m_pictures.emplace_back().loadFromFile(ImagesConst::NAME_DOOR))
		std::cerr << "The image named " << ImagesConst::NAME_DOOR << " was not loaded\n";
}

void Images::loadGiftKillGuard()
{
	if (!m_pictures.emplace_back().loadFromFile(ImagesConst::NAME_GIFT_KILL_GUARD))
		std::cerr << "The image named " << ImagesConst::NAME_GIFT_KILL_GUARD << " was not loaded\n";
}

void Images::loadGiftAddTime()
{
	if (!m_pictures.emplace_back().loadFromFile(ImagesConst::NAME_GIFT_ADD_TIME))
		std::cerr << "The image named " << ImagesConst::NAME_GIFT_ADD_TIME << " was not loaded\n";
}

void Images::loadGiftFreezeGuards()
{
	if (!m_pictures.emplace_back().loadFromFile(ImagesConst::NAME_GIFT_FREEZE_GUARDS))
		std::cerr << "The image named " << ImagesConst::NAME_GIFT_FREEZE_GUARDS << " was not loaded\n";
}

void Images::loadGiftAddLife()
{
	if (!m_pictures.emplace_back().loadFromFile(ImagesConst::NAME_GIFT_ADD_LIFE))
		std::cerr << "The image named " << ImagesConst::NAME_GIFT_ADD_LIFE << " was not loaded\n";
}

void Images::loadBomb()
{
	if (!m_pictures.emplace_back().loadFromFile(ImagesConst::NAME_BOMB))
		std::cerr << "The image named " << ImagesConst::NAME_BOMB << " was not loaded\n";
}

void Images::loadBombExplosion()
{
	if (!m_pictures.emplace_back().loadFromFile(ImagesConst::NAME_BOMB_EXPLOSION))
		std::cerr << "The image named " << ImagesConst::NAME_BOMB_EXPLOSION << " was not loaded\n";
}

void Images::loadWelcomGame()
{
	if (!m_pictures.emplace_back().loadFromFile(ImagesConst::NAME_WELCOM_GAME))
		std::cerr << "The image named " << ImagesConst::NAME_WELCOM_GAME << " was not loaded\n";
}

void Images::loadFinishGame()
{
	if (!m_pictures.emplace_back().loadFromFile(ImagesConst::NAME_FINISH_GAME))
		std::cerr << "The image named " << ImagesConst::NAME_FINISH_GAME << " was not loaded\n";
}

void Images::loadStopGame()
{
	if (!m_pictures.emplace_back().loadFromFile(ImagesConst::NAME_IMAGE_STOP_GAME))
		std::cerr << "The image named " << ImagesConst::NAME_IMAGE_STOP_GAME << " was not loaded\n";
}
