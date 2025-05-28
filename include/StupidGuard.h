#pragma once
#include "DynamicParticipant.h"

class StupidGuard : public DynamicParticipant {

public:
	//constructor
	StupidGuard(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	//public functions
	bool gotToTopLeft() const override;
	const sf::Vector2f getWantedDirection( GameInfo& gameInfo) const override;
	void move(const float& seconds) override;
	void finalMovement(const sf::Vector2f& newTopLeft, const sf::Vector2f& newDirection);
	void resetToStartPosition(GameInfo& gameInfo)override;
	void checkFreez(GameInfo& gameInfo, sf::Vector2f& newDirection)override;


	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Participant& object)override;
	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Player& player)override;
	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, SmartGuard& smartGuard)override {};
	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, StupidGuard& stupidGuard)override {};
	void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Bomb& bomb)override;

private:
	sf::Vector2f m_prevLocation;
	sf::Vector2f getNewLocation(const float& seconds) const;
};