#include "GiftAddLife.h"

GiftAddLife::GiftAddLife(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Gifts(location, wantedSize, ParticipantType::GiftAddLife)
{}


void GiftAddLife::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Player& player)
{
	if (m_topLeft == newTopLeft) {
		gameInfo.playTakingGift();
		gameInfo.setLives(gameInfo.getLives() + 1);
		m_objectState = false;
	}
}


void GiftAddLife::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Bomb& bomb)
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
