#include "GameInfo.h"

#include "iostream"

GameInfo::GameInfo()
	:m_shape(GameInfoConst::SIZE_INFO), m_text(FontHolder::getText()), 
	m_level(1), 
	m_score(0), 
	m_countDown(0), 
	m_lives(0), 
	m_possiblePoints(0), 
	m_timer(), 
	m_locPlayer(0.f,0.f),
	m_activeBomb(false), // throw Bomb
	m_killGuard(false),
	m_newGift(false),
	m_freezeGuards(false),
	m_freezeTime(sf::seconds(GameInfoConst::GUARD_FREEZE_TIME)),
	m_freezeClock(),
	m_locGift(0.f, 0.f)
{
	m_shape.setPosition(GameInfoConst::LOC_SHAPE);
	m_shape.setFillColor(GameInfoConst::COLOR_SHAPE_INFO);
	m_text.setPosition(GameInfoConst::LOC_TEXT);
	m_text.setCharacterSize(GameInfoConst::SIZE_CHARACTER);

	loadFile();
}


void GameInfo::setLevel(unsigned int level)
{
	m_level = level;
}

void GameInfo::setLives(int lives)
{
	m_lives = lives;
}

void GameInfo::setScore(unsigned int score)
{
	m_score = score;
}

const sf::RectangleShape& GameInfo::getShapeInfo() const
{
	return m_shape;
}

const sf::Text& GameInfo::getTextInfo() const
{
	return m_text;
}

unsigned int GameInfo::getLevel() const
{
	return m_level;
}

unsigned int GameInfo::getScore() const
{
	return m_score;
}

int GameInfo::getLives() const
{
	return m_lives;
}

float GameInfo::getCountDown() const
{
	return m_countDown;
}

const sf::Vector2f GameInfo::getLocPlayer() const
{
	return m_locPlayer;
}

void GameInfo::setLocPlayer(const sf::Vector2f locPlayer)
{
	m_locPlayer = locPlayer;
}

void GameInfo::setActiveBomb(bool activeBomb)
{
	m_activeBomb = activeBomb;
}

bool GameInfo::getActiveBomb() const
{
	return m_activeBomb;
}

bool GameInfo::getNewGift() const
{
	return m_newGift;
}

void GameInfo::setNewGift(bool newGift)
{
	m_newGift = newGift;
}

sf::Vector2f GameInfo::getLocGift() const
{
	return m_locGift;
}

void GameInfo::setLocGift(sf::Vector2f locGift)
{
	m_locGift = locGift;
}

bool GameInfo::getKillGuard() const
{
	return m_killGuard;
}

void GameInfo::setKillGuard(const bool killGuard)
{
	m_killGuard = killGuard;
}

void GameInfo::setmCountDown(const float countDown)
{
	m_countDown = countDown;
}


void GameInfo::initializer(size_t guards)
{
	m_score += m_possiblePoints;
	m_lives = GameInfoConst::LIFE;
	m_possiblePoints = static_cast<unsigned int> (GameInfoConst::END_LEVEL + GameInfoConst::LEVEL_GUARD * guards);
	m_timer.restart();

	switch (m_level)
	{
	case 1:
		m_countDown = GameInfoConst::TIME_LEVEL_ONE;
		break;
	case 2:
		m_countDown = GameInfoConst::TIME_LEVEL_TWO;
		break;
	default:
		m_countDown = GameInfoConst::TIME_ALL_LEVEL;
		break;
	}

	updateInfo();
}


void GameInfo::setFreezeGuards()
{
	m_freezeGuards = true;
	m_freezeClock.restart();
}


bool GameInfo::getFreezeGuards()
{
	if (m_freezeGuards && m_freezeClock.getElapsedTime() >= m_freezeTime)
		m_freezeGuards = false;
	return m_freezeGuards;
}


void GameInfo::updateInfo()
{
	int minutes, seconds;
	updateRemainingTime(minutes, seconds);

	m_text.setString(GameInfoConst::LEVEL_OUTPUT + std::to_string(m_level) +
					GameInfoConst::LIVES_OUTPUT + std::to_string(m_lives) +
					GameInfoConst::SCORE_OUTPUT + std::to_string(m_score) +
					GameInfoConst::TIMER_OUTPUT + std::to_string(minutes) + 
					":" + (seconds < 10 ? "0" : "") + std::to_string(seconds));
}


void GameInfo::updateRemainingTime(int& minutes, int& seconds)
{
	float elapsedTime = m_timer.restart().asSeconds();
	m_countDown -= elapsedTime;
	minutes = static_cast<int> (m_countDown) / 60;
	seconds = static_cast<int> (m_countDown) % 60;
}


void GameInfo::loadFile()
{
	if (!m_throwBombMusic.openFromFile(GameInfoConst::NAME_THROW_BOMB_MUSIC))
		std::cerr << "The image " << GameInfoConst::NAME_THROW_BOMB_MUSIC << " was not loaded\n";

	if (!m_takingGift.openFromFile(GameInfoConst::NAME_TAKING_GIFT_MUSIC))
		std::cerr << "The image " << GameInfoConst::NAME_TAKING_GIFT_MUSIC << " was not loaded\n";
}


void GameInfo::getThrowBombPlay()
{
	m_throwBombMusic.play();
}

void GameInfo::playTakingGift()
{
	m_takingGift.play();
}
