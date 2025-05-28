#include "StupidGuard.h"

StupidGuard::StupidGuard(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:DynamicParticipant(location, wantedSize, ParticipantType::StupidGuard),
	m_prevLocation(0.f, 0.f)
{
}


bool StupidGuard::gotToTopLeft() const
{
	return m_curLocation == m_topLeft;
}


const sf::Vector2f StupidGuard::getWantedDirection(GameInfo& gameInfo) const
{
	return randDirection();
}


void StupidGuard::move(const float& seconds)
{
	if ((m_curLocation.x - m_topLeft.x < 6 && m_curLocation.x - m_topLeft.x > -6) &&
		(m_curLocation.y - m_topLeft.y < 6 && m_curLocation.y - m_topLeft.y > -6))
	{
		m_curLocation = m_topLeft;
		m_direction = MovementConsts::NO_DIRECTION;
		m_picture.setPosition(m_topLeft);
		return;
	}

	m_curLocation = getNewLocation(seconds);
	m_picture.setPosition(m_curLocation);
}

void StupidGuard::finalMovement(const sf::Vector2f& newTopLeft, const sf::Vector2f& newDirection)
{
	m_topLeft = newTopLeft;
	m_direction = newDirection;
}

void StupidGuard::resetToStartPosition(GameInfo& gameInfo)
{
	m_topLeft = m_firstLocation;
	m_curLocation = m_firstLocation;
	m_picture.setPosition(m_topLeft);
	m_direction = MovementConsts::NO_DIRECTION;
}

void StupidGuard::checkFreez(GameInfo& gameInfo, sf::Vector2f& newDirection)
{
	if (gameInfo.getFreezeGuards())
		newDirection = MovementConsts::NO_DIRECTION;
}


sf::Vector2f StupidGuard::getNewLocation(const float& seconds) const
{
	return sf::Vector2f(m_curLocation.x + m_direction.x * seconds * MovementConsts::MOVE_PIXEL_STUPID_GUARD,
		m_curLocation.y + m_direction.y * seconds * MovementConsts::MOVE_PIXEL_STUPID_GUARD);
}


void StupidGuard::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Participant& object)
{
	object.handleCollision(gameInfo, newTopLeft, newDirection, *this);
}


void StupidGuard::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Player& player)
{
	if (m_topLeft == newTopLeft)
		gameInfo.setLives(gameInfo.getLives() - 1);

	if (gameInfo.getKillGuard()) {
		m_objectState = false;
		gameInfo.setKillGuard(false);
	}

}


void StupidGuard::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Bomb& bomb)
{
	if (m_topLeft == newTopLeft) {
		setObjectState(false);
		gameInfo.setScore(gameInfo.getScore() + GameInfoConst::LEVEL_GUARD);
	}
}
