#include "GameWindow.h"


GameWindow::GameWindow()
	:BasicWindow(GameWindowConst::SIZE_GAME_WINDOW, GameWindowConst::NAME_GAME, 
		Images::getSprite(ParticipantType::FinishGame, GameWindowConst::SIZE_GAME_WINDOW)),
	m_stopGame(Images::getSprite(ParticipantType::StopGame, GameWindowConst::SIZE_GAME_WINDOW)),


	m_boardIndex(),
	m_rows(0), m_cols(0), m_sizeTile(0.f, 0.f)
{
	m_window.setFramerateLimit(60);
	m_backgroundPicture.setPosition(0.f, 0.f);

	loadAllFileMusic();
}



void GameWindow::resetLevelSize(size_t row, size_t col)
{
	m_rows = row;
	m_cols = col;
	m_sizeTile = sf::Vector2f(1000.f / m_cols, 1000.f / m_rows);
	resetIndex();
}

sf::Vector2f GameWindow::getIndexPixel(const size_t row, const size_t col)
{
	return m_boardIndex[row][col];
}


sf::Vector2f GameWindow::getTopLeft(const sf::Vector2f& newLocation) const
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
			if (newLocation == m_boardIndex[i][j])
				return newLocation;

	int row = static_cast <int> ((newLocation.y + 0.01) / m_sizeTile.y);
	int col = static_cast <int> ((newLocation.x + 0.01) / m_sizeTile.x);

	return m_boardIndex[row][col];
}


sf::Vector2f GameWindow::getNextTopLeft(const sf::Vector2f& location, const sf::Vector2f& direction) const
{
	if (direction == MovementConsts::NO_DIRECTION)
		return location;

	sf::Vector2f newLoc = location;
	if (direction == MovementConsts::DIRECTION_UP)
		newLoc = sf::Vector2f(location.x, location.y - m_sizeTile.y);
	else if (direction == MovementConsts::DIRECTION_DOWN)
		newLoc = sf::Vector2f(location.x, location.y + m_sizeTile.y);
	else if (direction == MovementConsts::DIRECTION_RIGHT)
		newLoc = sf::Vector2f(location.x + m_sizeTile.x, location.y);
	else if (direction == MovementConsts::DIRECTION_LEFT)
		newLoc = sf::Vector2f(location.x - m_sizeTile.x, location.y);

	if (inArea(newLoc))
		return getTopLeft(newLoc);

	return location;
}


void GameWindow::resetIndex()
{
	m_boardIndex.clear();
	m_boardIndex.resize(m_rows);
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
			m_boardIndex[i].push_back(sf::Vector2f(j * m_sizeTile.x, i * m_sizeTile.y));
}

const sf::Vector2f GameWindow::getSizeTile() const
{
	return m_sizeTile;
}


const sf::Event GameWindow::pollEvent()
{
	sf::Event event;
	if (m_window.pollEvent(event)) {
		return event;
	}
	return event;
}

void GameWindow::playerFailedMusicPlay()
{
	m_playerFailedMusic.play();
}

void GameWindow::playerFailedMusicStop()
{
	m_playerFailedMusic.stop();
}

void GameWindow::playerMoveMusicPlay()
{
	m_moveLevelMusic.play();
}

void GameWindow::playerMoveMusicStop()
{
	m_moveLevelMusic.stop();
}

void GameWindow::finishGameMusicPlay()
{
	m_finishGameMusic.play();
}

void GameWindow::finishGameMusicStop()
{
	m_finishGameMusic.stop();
}

void GameWindow::drawImageStopGame()
{
	m_window.draw(m_stopGame);
}


void GameWindow::draw(const sf::RectangleShape& rectangle)
{
	m_window.draw(rectangle);
}

void GameWindow::draw(const sf::Text& text)
{
	m_window.draw(text);
}

void GameWindow::draw(const sf::Sprite& picture)
{
	m_window.draw(picture);
}

bool GameWindow::inArea(const sf::Vector2f& newLocation) const
{
	if (newLocation.x >= 0 && newLocation.x < GameWindowConst::SIZE_GAME_WINDOW.x &&
		newLocation.y >= 0 && newLocation.y < GameWindowConst::SIZE_GAME_WINDOW.y - GameInfoConst::SIZE_INFO.y)
		return true;
	return false;
}

void GameWindow::loadAllFileMusic()
{
	if (!m_backgroundMusic.openFromFile(GameWindowConst::GAME_BACKGROUND_MUSIC))
		std::cerr << "The image named " << GameWindowConst::GAME_BACKGROUND_MUSIC << " was not loaded\n";

	if (!m_playerFailedMusic.openFromFile(GameWindowConst::PLAYER_FAILED_MUSIC))
		std::cerr << "The image named " << GameWindowConst::PLAYER_FAILED_MUSIC << " was not loaded\n";

	if (!m_finishGameMusic.openFromFile(GameWindowConst::FINISH_GAME_MUSIC))
		std::cerr << "The image named " << GameWindowConst::FINISH_GAME_MUSIC << " was not loaded\n";

	if (!m_moveLevelMusic.openFromFile(GameWindowConst::NAME_MOVE_LEVEL))
		std::cerr << "The image " << GameWindowConst::NAME_MOVE_LEVEL << " was not loaded\n";
}
