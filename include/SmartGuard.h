#pragma once
#include "DynamicParticipant.h"


class SmartGuard : public DynamicParticipant
{
public:

	SmartGuard(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	bool gotToTopLeft() const override;
	const sf::Vector2f getWantedDirection(GameInfo& gameInfo) const override;
	void move(const float& seconds) override;

	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Participant& object)override;
	void resetToStartPosition(GameInfo& gameInfo)override;
	void checkFreez(GameInfo& gameInfo, sf::Vector2f& newDirection)override;
	void finalMovement(const sf::Vector2f& newTopLeft, const sf::Vector2f& newDirection);


	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Player& object)override;
	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, SmartGuard& smartGuard)override {};
	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, StupidGuard& stupidGuard)override {};
	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Bomb& bomb)override;

private:
	sf::Vector2f m_prevLocation;
	sf::Vector2f getNewLocation(const float& seconds) const;
};