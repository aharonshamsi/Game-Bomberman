#pragma once
#include "StaticParticipant.h"

class Rock : public StaticParticipant {

public:
	Rock(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Participant& object)override;

	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Player& player)override;
	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, SmartGuard& smartGurard)override;
	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, StupidGuard& stupidGuard)override;
	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Bomb& bomb)override;

};
