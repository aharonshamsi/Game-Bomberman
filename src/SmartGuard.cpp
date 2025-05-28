#include "SmartGuard.h"


SmartGuard::SmartGuard(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:DynamicParticipant(location, wantedSize, ParticipantType::SmartGuard), m_prevLocation(0.f, 0.f)
{}


bool SmartGuard::gotToTopLeft() const
{
	return m_curLocation == m_topLeft;
}


const sf::Vector2f SmartGuard::getWantedDirection(GameInfo& gameInfo) const
{
	if (m_topLeft != m_prevLocation) {
		if (gameInfo.getLocPlayer().x > m_topLeft.x)
			return MovementConsts::DIRECTION_RIGHT;
		if (gameInfo.getLocPlayer().x < m_topLeft.x)
			return MovementConsts::DIRECTION_LEFT;
		if (gameInfo.getLocPlayer().y < m_topLeft.y)
			return MovementConsts::DIRECTION_UP;
		if (gameInfo.getLocPlayer().y > m_topLeft.y)
			return MovementConsts::DIRECTION_DOWN;
		else
			return MovementConsts::NO_DIRECTION;
	}

	else
		return randDirection();
}


void SmartGuard::move(const float& seconds)
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


sf::Vector2f SmartGuard::getNewLocation(const float& seconds) const
{
	return sf::Vector2f(m_curLocation.x + m_direction.x * seconds * MovementConsts::MOVE_PIXEL_SMART_GUARD,
		m_curLocation.y + m_direction.y * seconds * MovementConsts::MOVE_PIXEL_SMART_GUARD);
}


void SmartGuard::finalMovement(const sf::Vector2f& newTopLeft, const sf::Vector2f& newDirection)
{
	m_prevLocation = m_topLeft;
	m_topLeft = newTopLeft;
	m_direction = newDirection;
}


void SmartGuard::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Participant& object)
{
	object.handleCollision(gameInfo, newTopLeft, newDirection, *this);
}


void SmartGuard::resetToStartPosition(GameInfo& gameInfo)
{
	m_topLeft = m_firstLocation;
	m_curLocation = m_firstLocation;
	m_picture.setPosition(m_topLeft);
	m_direction = MovementConsts::NO_DIRECTION;
}


void SmartGuard::checkFreez(GameInfo& gameInfo, sf::Vector2f& newDirection)
{
	if (gameInfo.getFreezeGuards())
		newDirection = MovementConsts::NO_DIRECTION;
}


void SmartGuard::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Player& player)
{
	if (m_topLeft == newTopLeft)
		gameInfo.setLives(gameInfo.getLives() - 1);
}


void SmartGuard::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Bomb& bomb)
{
	if (m_topLeft == newTopLeft) {
		setObjectState(false);
		gameInfo.setScore(gameInfo.getScore() + GameInfoConst::LEVEL_GUARD);
	}
}
