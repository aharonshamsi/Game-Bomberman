#pragma once
#include "Participant.h"
#include "Player.h"
#include "SmartGuard.h"
#include "StupidGuard.h"

class StaticParticipant : public Participant {

public:
	StaticParticipant(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type);

	virtual void handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Participant& object) = 0;

private:

};
