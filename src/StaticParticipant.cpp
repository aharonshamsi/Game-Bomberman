#include "StaticParticipant.h"

StaticParticipant::StaticParticipant(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type)
	:Participant(location, wantedSize, type)
{}
