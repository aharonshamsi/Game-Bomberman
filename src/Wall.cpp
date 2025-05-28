#include "Wall.h"

Wall::Wall(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:StaticParticipant(location, wantedSize, ParticipantType::Wall)
{
}


void Wall::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Participant& object)
{
	if (newTopLeft == m_topLeft) {
		newTopLeft = object.getTopLeft();
		newDirection = MovementConsts::NO_DIRECTION;
	}
}


void Wall::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Player& player)
{
	if (m_topLeft == newTopLeft) {
		newTopLeft = player.getTopLeft();
		newDirection = MovementConsts::NO_DIRECTION;
	}
}


void Wall::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, SmartGuard& smartGuard)
{
	if (newTopLeft == m_topLeft) {
		newTopLeft = smartGuard.getTopLeft();
		newDirection = MovementConsts::NO_DIRECTION;
	}
}


void Wall::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, StupidGuard& stupidGuard)
{
	if (newTopLeft == m_topLeft) {
		newTopLeft = stupidGuard.getTopLeft();
		newDirection = MovementConsts::NO_DIRECTION;
	}
}


void Wall::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Bomb& bomb)
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


