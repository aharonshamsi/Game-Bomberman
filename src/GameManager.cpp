#include "GameManager.h"

GameManager::GameManager()
	:m_gameWindow(), m_gameInfo(), m_levelReady(false)
{
}

//====================== run Game Mamager ===============================
void GameManager::runGameMamager()
{
	std::srand(static_cast<int>(std::time(0)));
	std::fstream filePlaylist(GameWindowConst::NAME_PLAYLIST_LEVELS);
	std::string nameLevel; 

	while (std::getline(filePlaylist, nameLevel)) {

		std::fstream fileLevel(nameLevel);
		size_t rows = 0;
		size_t cols = 0;
		size_t guards = 0;
		m_levelReady = false;

		readFileLevel(fileLevel, rows, cols); 
		m_gameWindow.resetLevelSize(rows, cols);
		initializerVectorFromFile(fileLevel, guards);
		m_gameInfo.initializer(guards); 

		sf::Clock clock;
		m_gameWindow.playBackgroundMusicMusic();
		m_gameWindow.setBackgroundLoop(true);

		if (m_gameInfo.getLevel() > 1) {
			playerMoveLevel();
			clock.restart();
		}

		unsigned int currentLevel = m_gameInfo.getLevel();
		clock.restart();
		while (m_gameWindow.isopen() && currentLevel == m_gameInfo.getLevel())
		{
			if (m_gameInfo.getCountDown() <= 0 || m_gameInfo.getLives() <= 0) {
				finishGame(); 
				return;
			}

			sf::Event event = m_gameWindow.pollEvent();
			if (event.type == sf::Event::Closed)
			{
				m_gameWindow.close();
				break;
			}
			else if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::B) {
					m_gameInfo.getThrowBombPlay();
					m_gameInfo.setActiveBomb(true);
				}

			}

			handleMovement(clock);
			updateWindow();
		}

		if (m_gameInfo.getCountDown() <= 0 || m_gameInfo.getLives() <= 0)
		{
			m_gameWindow.close();
			return;
		}

		nameLevel.clear(); 
		m_bombs.clear();
	}

	finishGame();
}


//====================== handle Movement =================================================
void GameManager::handleMovement(sf::Clock& clock)
{
	if (!m_levelReady)
		return;

	for (int i = 0; i < m_dynamic.size(); i++)
	{
		int prevLives = m_gameInfo.getLives(); 

		if (m_gameInfo.getActiveBomb()) {
			m_bombs.push_back(std::make_unique<Bomb>(m_gameInfo.getLocPlayer(), m_gameWindow.getSizeTile()));
			m_gameInfo.setActiveBomb(false);
		}

		if (m_dynamic[i]->gotToTopLeft())
		{
			sf::Vector2f newDirection = m_dynamic[i]->getWantedDirection(m_gameInfo);
			sf::Vector2f newTopLeft = m_gameWindow.getNextTopLeft(m_dynamic[i]->getTopLeft(), newDirection);

			m_dynamic[i]->checkFreez(m_gameInfo, newDirection);

			// Manager all collisions dynamic & atatic & bomb
			if (newDirection != MovementConsts::NO_DIRECTION) {
				managerCollision(newDirection, newTopLeft, i);
			}

			// Manager all collisions with bomb
			managerBombCollision(newDirection, newTopLeft, i);

			if (m_gameInfo.getNewGift()) {
				addGifts(m_gameInfo.getLocGift(), GameInfoConst::NUM_GIFTS_UNDER_ROKE);
				m_gameInfo.setNewGift(false);
			}


			if (m_gameInfo.getLives() < prevLives) {
				playerLostLife();
				clock.restart();
				return;
			}

		}
		m_dynamic[i]->move(clock.getElapsedTime().asSeconds());

		deleteParticipantBombs();
		deleteParticipantDynamic();
		deleteParticipantStatic();
	}
	clock.restart();
}


//====================== Manager all collisions dynamic & atatic ========================================
void GameManager::managerCollision(sf::Vector2f& newDirection, sf::Vector2f& newTopLeft, const int i)
{
	for (int j = 0; j < m_dynamic.size(); j++) {
		if (i != j)
			m_dynamic[i]->handleCollision(m_gameInfo, newTopLeft, newDirection, *m_dynamic[j]);
	}

	for (int k = 0; k < m_static.size(); k++)
		m_dynamic[i]->handleCollision(m_gameInfo, newTopLeft, newDirection, *m_static[k]);

	managerBombCollision(newDirection, newTopLeft, i);

	m_dynamic[i]->finalMovement(newTopLeft, newDirection);
}

//====================== Manager all collisions with bomb ================================================
void GameManager::managerBombCollision(sf::Vector2f& newDirection, sf::Vector2f& newTopLeft, const int i)
{
	for (int x = 0; x < m_bombs.size(); x++) {
		if (m_bombs[x]->hasExploded()) {
			m_bombs[x]->exploded();
			m_bombs[x]->handleCollision(m_gameInfo, newTopLeft, newDirection, *m_dynamic[i]);

			for (int k = 0; k < m_static.size(); k++) {
				m_bombs[x]->handleCollision(m_gameInfo, newTopLeft, newDirection, *m_static[k]);
			}
		}
	}
}


void GameManager::readFileLevel(std::fstream& fileLevel, size_t& rows, size_t& cols)
{
	std::string line;

	while (std::getline(fileLevel, line)) {
		rows++;
		cols = static_cast<int> (line.size());
	}

}



void GameManager::initializerVectorFromFile(std::fstream& fileLevel, size_t& guards)
{
	fileLevel.clear();
	fileLevel.seekg(0);

	m_dynamic.clear();
	m_static.clear();

	std::string line;
	size_t row = 0;
	char ch = ' ';

	while (std::getline(fileLevel, line)) {
		for (size_t col = 0; col < line.size(); col++) {
			ch = line[col];

			switch (ch)
			{
			case CharacterId::PLAYER_ID:
				m_dynamic.push_back(std::make_unique<Player>(m_gameWindow.getIndexPixel(row, col), m_gameWindow.getSizeTile()));
				m_gameInfo.setLocPlayer(m_gameWindow.getIndexPixel(row, col)); // Initialize player position
				break;

			case CharacterId::GUARD_ID:
				guards++;

				if ((guards + 4) % 5 == 0) { // Smart guard
					m_dynamic.push_back(std::make_unique<SmartGuard>(m_gameWindow.getIndexPixel(row, col), m_gameWindow.getSizeTile()));
				}
				else { // stupid guard
					m_dynamic.push_back(std::make_unique<StupidGuard>(m_gameWindow.getIndexPixel(row, col), m_gameWindow.getSizeTile()));
				}
				break;

			case CharacterId::DOOR_ID:
				m_static.push_back(std::make_unique<Door>(m_gameWindow.getIndexPixel(row, col), m_gameWindow.getSizeTile()));
				break;

			case CharacterId::ROCK_ID:
				m_static.push_back(std::make_unique<Rock>(m_gameWindow.getIndexPixel(row, col), m_gameWindow.getSizeTile()));
				break;

			case CharacterId::WALL_ID:
				m_static.push_back(std::make_unique<Wall>(m_gameWindow.getIndexPixel(row, col), m_gameWindow.getSizeTile()));
				break;

			case CharacterId::SPACE_ID:
				addGifts(m_gameWindow.getIndexPixel(row, col), GameInfoConst::NUM_GIFTS_IN_SPACE);
				break;

			default:
				break;
			}
		}
		row++;
	}
	m_levelReady = true;

}


void GameManager::updateWindow()
{
	m_gameWindow.clear();
	m_gameInfo.updateInfo();
	m_gameWindow.draw(m_gameInfo.getShapeInfo());
	m_gameWindow.draw(m_gameInfo.getTextInfo());

	for (size_t i = 0; i < m_static.size(); i++)
		m_gameWindow.draw(m_static[i]->getParticipantSprite());

	for (size_t i = 0; i < m_bombs.size(); i++)
		m_bombs[i]->draw(m_gameWindow);

	for (int i = 0; i < m_dynamic.size(); i++)
		m_gameWindow.draw(m_dynamic[i]->getParticipantSprite());

	m_gameWindow.display();
}


// Delete all vectors unique_ptr
void GameManager::deleteParticipantBombs()
{
	m_bombs.erase(
		std::remove_if(m_bombs.begin(), m_bombs.end(),
			[](const std::unique_ptr<Bomb>& bomb) { return bomb->shouldRemove(); }),
		m_bombs.end()
	);
}

void GameManager::deleteParticipantDynamic()
{
	m_dynamic.erase(
		std::remove_if(m_dynamic.begin(), m_dynamic.end(),
			[](const std::unique_ptr<DynamicParticipant>& dynamic)
			{return !dynamic->getObjectState(); }),
		m_dynamic.end()
	);
}

void GameManager::deleteParticipantStatic()
{
	m_static.erase(
		std::remove_if(m_static.begin(), m_static.end(),
			[](const std::unique_ptr<StaticParticipant>& static_participant)
			{return !static_participant->getObjectState(); }),
		m_static.end()
	);
}


void GameManager::addGifts(const sf::Vector2f& locGift, const int randGift)
{
	if (std::rand() % randGift == 0) 
	{
		int choisGift = std::rand() % 4;

		switch (choisGift)
		{
		case 0:
			m_static.push_back(std::make_unique<GiftKillGuard>(locGift, m_gameWindow.getSizeTile()));
			break;
		case 1:
			m_static.push_back(std::make_unique<GiftAddTime>(locGift, m_gameWindow.getSizeTile()));
			break;
		case 2:
			m_static.push_back(std::make_unique<GiftFreezeGuards>(locGift, m_gameWindow.getSizeTile()));
			break;
		case 3:
			m_static.push_back(std::make_unique<GiftAddLife>(locGift, m_gameWindow.getSizeTile()));
			break;
		}
	}
}

void GameManager::playerLostLife()
{
	m_bombs.clear();

	if (m_gameInfo.getLives() <= 0)

		finishGame();
	else {
		stopGame();

		for (int i = 0; i < m_dynamic.size(); i++) {
			m_dynamic[i]->resetToStartPosition(m_gameInfo);
		}
		m_gameWindow.playBackgroundMusicMusic();
	}
}


void GameManager::playerMoveLevel()
{
	m_gameWindow.stopBackgroundMusicMusic();
	m_gameWindow.playerMoveMusicPlay();
	m_gameWindow.clear();
	m_gameWindow.drawImageStopGame();
	m_gameWindow.display();
	sf::sleep(sf::seconds(1.5));
	m_gameWindow.playerMoveMusicStop();
	m_gameWindow.playBackgroundMusicMusic();
}


void GameManager::finishGame()
{
	m_gameWindow.stopBackgroundMusicMusic();
	m_gameWindow.finishGameMusicPlay();
	m_gameWindow.clear();
	m_gameWindow.drawBackgroundPicture();
	m_gameWindow.display();
	sf::sleep(sf::seconds(6));
	m_gameWindow.finishGameMusicStop();
	m_gameWindow.close();
}


void GameManager::stopGame()
{
	m_gameWindow.stopBackgroundMusicMusic();
	m_gameWindow.playerFailedMusicPlay();
	m_gameWindow.clear();
	m_gameWindow.drawImageStopGame();
	m_gameWindow.display();
	sf::sleep(sf::seconds(4));
	m_gameWindow.playerFailedMusicStop();
}
