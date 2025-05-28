#include "GiftAddTime.h"


GiftAddTime::GiftAddTime(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Gifts(location, wantedSize, ParticipantType::GiftAddTime)
{}


void GiftAddTime::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Player& player)
{
	if (m_topLeft == newTopLeft) {
		gameInfo.playTakingGift();
		gameInfo.setmCountDown(gameInfo.getCountDown() + GameInfoConst::ADD_TIME);
		m_objectState = false;
	}
}


void GiftAddTime::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Bomb& bomb)
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
