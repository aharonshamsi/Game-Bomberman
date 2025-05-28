#pragma once
#include "Participant.h"
#include "Bomb.h"


class DynamicParticipant : public Participant
{
public:

	DynamicParticipant(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type);
	virtual ~DynamicParticipant() = default;

	virtual void finalMovement(const sf::Vector2f& newTopLeft, const sf::Vector2f& newDirection) = 0;
	virtual bool gotToTopLeft() const = 0;
	virtual void move(const float& seconds) = 0;
	virtual void resetToStartPosition(GameInfo& gameInfo) = 0;
	virtual void checkFreez(GameInfo& gameInfo, sf::Vector2f& newDirection) = 0;
	virtual const sf::Vector2f getWantedDirection(GameInfo& gameInfo) const = 0;
	virtual void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Participant& object) = 0;

protected:

	sf::Vector2f m_curLocation;
	sf::Vector2f m_direction;
	const sf::Vector2f m_firstLocation;

	sf::Vector2f getFirstLoc();
	sf::Vector2f randDirection()const;

};