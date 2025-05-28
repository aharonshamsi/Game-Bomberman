#include "Door.h"

Door::Door(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:StaticParticipant(location, wantedSize, ParticipantType::Door)
{
}

void Door::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Player& player)
{	
	if (m_topLeft == newTopLeft)
		gameInfo.setLevel(gameInfo.getLevel() + 1);
}

void Door::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, SmartGuard& smartGuard)
{
	if (m_topLeft == newTopLeft) {
		newTopLeft = smartGuard.getTopLeft();
		newDirection = MovementConsts::NO_DIRECTION;
	}
}

void Door::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, StupidGuard& stupidGuard)
{
	if (m_topLeft == newTopLeft) {
		newTopLeft = stupidGuard.getTopLeft();
		newDirection = MovementConsts::NO_DIRECTION;
	}
}

void Door::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Bomb& bomb)
{
	if (m_topLeft == bomb.getExplosionLocRight())
		bomb.setExplodeRight(false);

	else if (m_topLeft == bomb.getExplosionLocLeft())
		bomb.setExplodeLeft(false);

	else if (m_topLeft == bomb.getExplosionLocUp())
		bomb.setExplodeUp(false);

	else if (m_topLeft == bomb.getExplosionLocDown())
		bomb.setExplodeDown(false);
}
