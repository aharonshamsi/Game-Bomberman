#pragma once
#include "DynamicParticipant.h"


class Player : public DynamicParticipant
{
public:
	//constructor
	Player(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	//public functions
	bool gotToTopLeft() const override;
	const sf::Vector2f getWantedDirection(GameInfo& gameInfo) const override;
	void resetToStartPosition(GameInfo& gameInfo)override;

	void move(const float& seconds) override;
	void finalMovement(const sf::Vector2f& newTopLeft, const sf::Vector2f& newDirection);
	void checkFreez(GameInfo& gameInfo, sf::Vector2f& newDirection)override {};
	
	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Participant& object)override;

	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Player& player)override {};
	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, SmartGuard& smartGuard)override;
	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, StupidGuard& stupidGuard)override;
	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Bomb& bomb)override;


private:

	sf::Vector2f m_prevLocation;
	bool m_hitByBomb = false;

	sf::Vector2f getNewLocation(const float& seconds) const;

};