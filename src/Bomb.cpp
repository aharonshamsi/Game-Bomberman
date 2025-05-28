#include "Bomb.h"

Bomb::Bomb(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Participant(location, wantedSize, ParticipantType::Bomb), 
	m_countDown(BombConst::COUNT_DOWN_BOMB),
	m_bombExplosion(Images::getSprite(ParticipantType::BombExplosion, wantedSize)),
	m_isExploded(false),

	m_explosionLocCenter(location), // location bomb
	m_explosionLocRight(location.x + wantedSize.x, location.y),
	m_explosionLocLeft(location.x - wantedSize.x, location.y), 
	m_explosionLocUp(location.x, location.y + wantedSize.y), 
	m_explosionLocDown(location.x, location.y - wantedSize.y),

	m_explodeRight(true), m_explodeLeft(true), m_explodeUp(true), m_explodeDown(true),  // איתחול כיווני הפיצוץ

	m_countDownPlay(false),
	m_countDownText(FontHolder::getText()),
	m_tileSize(wantedSize),
	m_soundPlayed(false)

{
	loadFileMusic();

	m_countDownMusic.setLoop(true);
	m_countDownMusic.play();
}


bool Bomb::hasExploded() const
{	
	return m_launchTime.getElapsedTime() >= m_countDown;
}

bool Bomb::shouldRemove() const {
	return m_isExploded && m_launchTime.getElapsedTime() >= m_explosionTime;
}

void Bomb::exploded() {
	if (!m_isExploded) {
		m_isExploded = true;
		m_explosionTime = m_launchTime.getElapsedTime() + BombConst::EXPLOSION_TIME;
		m_countDownMusic.stop(); 
	}
}

sf::Vector2f Bomb::getExplosionLocRight() const
{
	return m_explosionLocRight;
}

sf::Vector2f Bomb::getExplosionLocLeft() const
{
	return m_explosionLocLeft;
}

sf::Vector2f Bomb::getExplosionLocUp() const
{
	return m_explosionLocUp;
}

sf::Vector2f Bomb::getExplosionLocDown() const
{
	return m_explosionLocDown;
}

void Bomb::setExplodeRight(bool explodeRight)
{
	m_explodeRight = explodeRight;
}

void Bomb::setExplodeLeft(bool explodeLeft)
{
	m_explodeLeft = explodeLeft;
}

void Bomb::setExplodeUp(bool explodeUp)
{
	m_explodeUp = explodeUp;
}

void Bomb::setExplodeDown(bool explodeDown)
{
	m_explodeDown = explodeDown;
}



void Bomb::draw(GameWindow& gameWindow)
{
	if (m_isExploded) {

		if (m_launchTime.getElapsedTime() < m_explosionTime) {

			if (!m_soundPlayed) {
				m_bombExplodeMusic.play();
				m_soundPlayed = true;
			}
			// Sprite Bomb
			sf::Sprite explosionSprites[5] = { m_bombExplosion, m_bombExplosion, m_bombExplosion , m_bombExplosion, m_bombExplosion };

			// location bomb
			explosionSprites[0].setPosition(m_explosionLocCenter);
			explosionSprites[1].setPosition(m_explosionLocRight);
			explosionSprites[2].setPosition(m_explosionLocLeft);
			explosionSprites[3].setPosition(m_explosionLocUp);
			explosionSprites[4].setPosition(m_explosionLocDown);

			gameWindow.draw(explosionSprites[0]);

			// choies collision bomb
			if (m_explodeRight)
				gameWindow.draw(explosionSprites[1]);
			if (m_explodeLeft)
				gameWindow.draw(explosionSprites[2]);
			if (m_explodeUp)
				gameWindow.draw(explosionSprites[3]);
			if (m_explodeDown)
				gameWindow.draw(explosionSprites[4]);
		}
	}
	else {
		gameWindow.draw(m_picture);

		m_countDownText.setFillColor(sf::Color::Red);
		m_countDownText.setCharacterSize(40);

		locationCountDown();

		if (!m_isExploded) {
			gameWindow.draw(m_countDownText);
		}

	}

}

void Bomb::handleCollision(GameInfo& gameInfo, sf::Vector2f& newTopLeft, sf::Vector2f& newDirection, Participant& object)
{
	object.handleCollision(gameInfo, m_explosionLocCenter, newDirection, *this);
	object.handleCollision(gameInfo, m_explosionLocRight, newDirection, *this);
	object.handleCollision(gameInfo, m_explosionLocLeft, newDirection, *this);
	object.handleCollision(gameInfo, m_explosionLocUp, newDirection, *this);
	object.handleCollision(gameInfo, m_explosionLocDown, newDirection, *this);
}


void Bomb::locationCountDown()
{
	int timeLeft = static_cast<int>((m_countDown - m_launchTime.getElapsedTime()).asSeconds());
	m_countDownText.setString(std::to_string(timeLeft));

	sf::FloatRect textBounds = m_countDownText.getLocalBounds();
	m_countDownText.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
	m_countDownText.setPosition(m_picture.getPosition().x + (m_tileSize.x / 2), m_picture.getPosition().y + (m_tileSize.y / 2));
}


void Bomb::loadFileMusic()
{
	if (!m_bombExplodeMusic.openFromFile(BombConst::NAME_BOMB_EXPLODE_MUSIC))
		std::cerr << "The image " << BombConst::NAME_BOMB_EXPLODE_MUSIC << " was not loaded\n";

	if (!m_countDownMusic.openFromFile(BombConst::NAME_COUNT_DOWN_MUSIC))
		std::cerr << "The image " << BombConst::NAME_COUNT_DOWN_MUSIC << " was not loaded\n";
}
