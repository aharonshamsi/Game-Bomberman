#include "Player.h"


Player::Player(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:DynamicParticipant(location, wantedSize, ParticipantType::Player)
{}


bool Player::gotToTopLeft() const
{
	return m_curLocation == m_topLeft;
}


const sf::Vector2f Player::getWantedDirection(GameInfo& gameInfo) const
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		return MovementConsts::DIRECTION_RIGHT;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		return MovementConsts::DIRECTION_LEFT;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		return MovementConsts::DIRECTION_UP;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		return MovementConsts::DIRECTION_DOWN;

	return MovementConsts::NO_DIRECTION;
}

void Player::resetToStartPosition(GameInfo& gameInfo)
{
	m_topLeft = m_firstLocation;
	gameInfo.setLocPlayer(m_firstLocation); // עידכון מיקום השחקן להתחלה
	m_curLocation = m_firstLocation;
	m_picture.setPosition(m_topLeft);
	m_direction = MovementConsts::NO_DIRECTION;
}


void Player::finalMovement(const sf::Vector2f& newTopLeft, const sf::Vector2f& newDirection)
{
	m_topLeft = newTopLeft;
	m_direction = newDirection;
}


void Player::move(const float& seconds)
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



sf::Vector2f Player::getNewLocation(const float& seconds) const
{
	return sf::Vector2f(m_curLocation.x + m_direction.x * seconds * MovementConsts::MOVE_PIXEL_PLAYER,
		m_curLocation.y + m_direction.y * seconds * MovementConsts::MOVE_PIXEL_PLAYER);
}


void Player::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Participant& object)
{
	object.handleCollision(gameInfo, newTopLeft, newDirection ,*this);
	gameInfo.setLocPlayer(newTopLeft); // Player location update

}


void Player::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, SmartGuard& smartGuard)
{
	if (m_topLeft == newTopLeft)
		gameInfo.setLives(gameInfo.getLives() - 1);
}


void Player::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, StupidGuard& stupidGuard)
{
	if (m_topLeft == newTopLeft)
		gameInfo.setLives(gameInfo.getLives() - 1);
}


void Player::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Bomb& bomb)
{
	if (m_topLeft == newTopLeft) {
		gameInfo.setLives(gameInfo.getLives() - 1); 
	}
}
