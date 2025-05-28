#pragma once
#include "Images.h"
#include "ParticipantType.h"
#include "MovementConsts.h"
#include "GameInfo.h"


class Player;
class SmartGuard;
class StupidGuard;
class Rock;
class Door;
class Wall;
class Bomb;
class GiftKillGuard;
class GiftAddTime;
class GiftFreezeGuards;
class GiftAddLife;


class Participant
{
public:
	Participant(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type);

	virtual ~Participant() = default;

	sf::Sprite getParticipantSprite() const;
	sf::Vector2f getTopLeft() const;

	bool getObjectState()const;
	void setObjectState(bool objectState);

	virtual void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Participant& object) = 0;

	virtual void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Player& player) = 0;
	virtual void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, SmartGuard& smartGuard) = 0;
	virtual void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, StupidGuard& stupidGuard) = 0;
	virtual void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Bomb& bomb) = 0;


protected:

	sf::Vector2f m_topLeft;
	sf::Sprite m_picture;
	ParticipantType m_type;
	bool m_objectState; 

	void pictureArrangement(const sf::Vector2f& wantedSize);
};