#include "Participant.h"

Participant::Participant(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type)
	:m_topLeft(location), m_type(type), m_objectState(true)
{
	pictureArrangement(wantedSize);
	m_picture.setPosition(m_topLeft);
}


sf::Sprite Participant::getParticipantSprite() const
{
	return m_picture;
}


sf::Vector2f Participant::getTopLeft() const
{
	return m_topLeft;
}

bool Participant::getObjectState() const
{
	return m_objectState;
}

void Participant::setObjectState(bool objectState)
{
	m_objectState = objectState;
}


void Participant::pictureArrangement(const sf::Vector2f& wantedSize)
{
	switch (m_type)
	{
	case ParticipantType::Player:
		m_picture = Images::getSprite(ParticipantType::Player, wantedSize);
		break;

	case ParticipantType::SmartGuard:
		m_picture = Images::getSprite(ParticipantType::SmartGuard, wantedSize);
		break;

	case ParticipantType::StupidGuard:
		m_picture = Images::getSprite(ParticipantType::StupidGuard, wantedSize);
		break;

	case ParticipantType::Door:
		m_picture = Images::getSprite(ParticipantType::Door, wantedSize);
		break;

	case ParticipantType::Rock:
		m_picture = Images::getSprite(ParticipantType::Rock, wantedSize);
		break;

	case ParticipantType::Wall:
		m_picture = Images::getSprite(ParticipantType::Wall, wantedSize);
		break;

	case ParticipantType::Bomb:
		m_picture = Images::getSprite(ParticipantType::Bomb, wantedSize);
		break;

	case ParticipantType::BombExplosion:
		m_picture = Images::getSprite(ParticipantType::BombExplosion, wantedSize);
		break;

	case ParticipantType::GiftKillGuard:
		m_picture = Images::getSprite(ParticipantType::GiftKillGuard, wantedSize);
		break;

	case ParticipantType::GiftAddTime:
		m_picture = Images::getSprite(ParticipantType::GiftAddTime, wantedSize);
		break;

	case ParticipantType::GiftFreezeGuards:
		m_picture = Images::getSprite(ParticipantType::GiftFreezeGuards, wantedSize);
		break;

	case ParticipantType::GiftAddLife:
		m_picture = Images::getSprite(ParticipantType::GiftAddLife, wantedSize);
		break;

	default:
		break;
	}
}