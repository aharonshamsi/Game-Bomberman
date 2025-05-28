#include "GeneralManager.h"

GeneralManager::GeneralManager()
	:m_welcomeWindow()
{}

void GeneralManager::runProgram()
{
	if (m_welcomeWindow.managerWelcomeWindow()) {
		GameManager game;
		game.runGameMamager();
	}
}
