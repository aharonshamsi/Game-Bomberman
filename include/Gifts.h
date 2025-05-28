#pragma once
#include "StaticParticipant.h"

class Gifts : public StaticParticipant {

public:
	Gifts(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type);

};

