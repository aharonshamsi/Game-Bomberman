#include "GiftKillGuard.h"

GiftKillGuard::GiftKillGuard(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Gifts(location, wantedSize, ParticipantType::GiftKillGuard)
{}


void GiftKillGuard::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Player& player)
{
	if (m_topLeft == newTopLeft) {
		gameInfo.playTakingGift();
		gameInfo.setScore(gameInfo.getScore() + GameInfoConst::LEVEL_GUARD);
		gameInfo.setKillGuard(true);
		m_objectState = false;
		newTopLeft = player.getTopLeft();
	}
}


void GiftKillGuard::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Bomb& bomb)
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
