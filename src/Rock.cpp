#include "Rock.h"

Rock::Rock(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:StaticParticipant(location, wantedSize, ParticipantType::Rock)
{
}

void Rock::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Participant& object)
{
	if (m_topLeft == newTopLeft) {
		newTopLeft = object.getTopLeft();
		newDirection = MovementConsts::NO_DIRECTION;
	}
}

void Rock::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Player& player)
{
	if (m_topLeft == newTopLeft) {
		newTopLeft = player.getTopLeft();
		newDirection = MovementConsts::NO_DIRECTION;
	}
}

void Rock::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, SmartGuard& smartGuard)
{
	if (m_topLeft == newTopLeft) {
		newTopLeft = smartGuard.getTopLeft();
		newDirection = MovementConsts::NO_DIRECTION;
	}
}

void Rock::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, StupidGuard& stupidGuard)
{
	if (m_topLeft == newTopLeft) {
		newTopLeft = stupidGuard.getTopLeft();
		newDirection = MovementConsts::NO_DIRECTION;
	}
}

void Rock::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Bomb& bomb)
{
	if (m_topLeft == newTopLeft) {
		setObjectState(false);
		gameInfo.setNewGift(true);
		gameInfo.setLocGift(m_topLeft);
	}
}


