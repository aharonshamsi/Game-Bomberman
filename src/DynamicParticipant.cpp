#include "DynamicParticipant.h"

DynamicParticipant::DynamicParticipant(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type)
	:Participant(location, wantedSize, type), m_direction(0.f, 0.f), m_curLocation(location), m_firstLocation(location)
{}


sf::Vector2f DynamicParticipant::randDirection() const
{
	int directionRandom = std::rand() % 4;
	switch (directionRandom)
	{
	case  0:
		return MovementConsts::DIRECTION_RIGHT;
		break;
	case 1:
		return MovementConsts::DIRECTION_LEFT;
		break;
	case 2:
		return MovementConsts::DIRECTION_UP;
		break;
	case 3:
		return MovementConsts::DIRECTION_DOWN;
		break;
	};
	return MovementConsts::NO_DIRECTION;
}


sf::Vector2f DynamicParticipant::getFirstLoc()
{
	return m_firstLocation;
}
