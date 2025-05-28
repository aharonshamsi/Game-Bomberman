#include "GiftFreezeGuards.h"

GiftFreezeGuards::GiftFreezeGuards(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Gifts(location, wantedSize, ParticipantType::GiftFreezeGuards)
{}


void GiftFreezeGuards::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Player& player)
{
	if (gameInfo.getLocPlayer() == m_topLeft)
	{
		gameInfo.playTakingGift();
		gameInfo.setFreezeGuards();
		m_objectState = false;
		newTopLeft = player.getTopLeft();
	}

}


void GiftFreezeGuards::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Bomb& bomb)
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
