#include "WelcomeWindow.h"
#include <iostream>


WelcomeWindow::WelcomeWindow()
	:BasicWindow(sf::Vector2f(WelcomeConst::SIZE_WINDOW.x, WelcomeConst::SIZE_WINDOW.y), WelcomeConst::NAME_PLAYER,
		Images::getSprite(ParticipantType::welcomGame, WelcomeConst::SIZE_WINDOW)),

	m_textHelp(FontHolder::getText()),

	m_help(WelcomeConst::SIZE_BUTTON, WelcomeConst::LOC_HELP, WelcomeConst::NAME_HELP),

	m_start(WelcomeConst::SIZE_BUTTON, WelcomeConst::LOC_START, WelcomeConst::NAME_START),

	m_exit(WelcomeConst::SIZE_BUTTON, WelcomeConst::LOC_EXIT, WelcomeConst::NAME_EXIT),

	m_back(WelcomeConst::SIZE_BUTTON_BACK, WelcomeConst::LOC_BACK, WelcomeConst::NAME_BACK)
{
	infoHelp();

	if (!m_backgroundMusic.openFromFile(WelcomeConst::NAME_FILE_MUSIC))
		std::cerr << "The image named" << WelcomeConst::NAME_FILE_MUSIC << "was not loaded\n";
}


void WelcomeWindow::infoHelp()
{
	std::string infoHelp = readInfoHelpToFile();
	m_textHelp.setString(infoHelp);
	m_textHelp.setCharacterSize(WelcomeConst::SIZE_FONT_HELP); 
	m_textHelp.setPosition(WelcomeConst::LOC_INFO_HELP);
}


std::string WelcomeWindow::readInfoHelpToFile()
{
	std::fstream file(WelcomeConst::NAME_FILE_INFO_HELP);
	std::string line, infoHelp;

	while (std::getline(file, line))
		infoHelp += line + "\n";

	return infoHelp;
}


bool WelcomeWindow::managerWelcomeWindow()
{
	drawAll();

	m_backgroundMusic.setLoop(true);
	m_backgroundMusic.play();

	bool start = false;
	bool isHelp = false;

	while (m_window.isOpen() && !start) {

		sf::Event event;
		while (m_window.pollEvent(event)) {

			switch (event.type) 
			{
			case sf::Event::Closed:
				m_window.close();
				break;

			case sf::Event::MouseMoved: {
				sf::Vector2f locMove(float(event.mouseMove.x), float(event.mouseMove.y));
				managerMove(locMove, isHelp);
				break;
			}

			case sf::Event::MouseButtonPressed: {
				sf::Vector2f locMousePressed(float(event.mouseButton.x), float(event.mouseButton.y));
				mamagerPressed(locMousePressed, isHelp, start);
				break;
			}

			}

			if (!isHelp)
				drawAll();
		}
		
	}
	if (start)
		m_backgroundMusic.stop();

	return start;
}


void WelcomeWindow::drawAll()
{
	clear();
	drawBackgroundPicture();
	m_start.drawButton(m_window);
	m_help.drawButton(m_window);
	m_exit.drawButton(m_window);
	display();
}


void WelcomeWindow::drawHelp()
{
	m_window.clear();
	m_back.drawButton(m_window);
	m_window.draw(m_textHelp);
	m_window.display();
}


void WelcomeWindow::managerMove(const sf::Vector2f& locMove, bool& isHelp)
{
	if (isMoveStart(locMove) && !isHelp)
		m_start.setOutlineColor(ButtonConst::MOUSE_COLOR_MOVE);

	else if (isMoveHelp(locMove) && !isHelp)
		m_help.setOutlineColor(ButtonConst::MOUSE_COLOR_MOVE);

	else if (isMoveExit(locMove) && !isHelp)
		m_exit.setOutlineColor(ButtonConst::MOUSE_COLOR_MOVE);

	else if (isHelp && isMoveBack(locMove))
		m_back.setOutlineColor(ButtonConst::MOUSE_COLOR_MOVE);

	else if (isHelp)
		m_back.setOutlineColor(ButtonConst::COLOR_THICKNESS);

	else {
		m_start.setOutlineColor(ButtonConst::COLOR_THICKNESS);
		m_help.setOutlineColor(ButtonConst::COLOR_THICKNESS);
		m_exit.setOutlineColor(ButtonConst::COLOR_THICKNESS);
	}

	if (isHelp) {
		drawHelp();
	}
}


void WelcomeWindow::mamagerPressed(const sf::Vector2f& locPressed, bool& isHelp, bool& start)
{
	if (isClickStart(locPressed)) {
		m_window.close(); 
		start = true;
	}


	else if (isClickHelp(locPressed)) {
		m_help.setOutlineColor(ButtonConst::COLOR_THICKNESS); 
		drawHelp();
		isHelp = true;
	}

	else if (isClickBack(locPressed)) {
		m_back.setOutlineColor(ButtonConst::COLOR_THICKNESS);
		drawAll();
		isHelp = false;
	}

	else if (isClickExit(locPressed))
		m_window.close();

}



bool WelcomeWindow::isMoveStart(const sf::Vector2f& locMouse)
{
	return locMouse.x >= WelcomeConst::LOC_START.x && locMouse.x <= WelcomeConst::LOC_START.x + WelcomeConst::SIZE_BUTTON.x &&
			locMouse.y >= WelcomeConst::LOC_START.y && locMouse.y <= WelcomeConst::LOC_START.y + WelcomeConst::SIZE_BUTTON.y;
}

bool WelcomeWindow::isMoveHelp(const sf::Vector2f& locMouse)
{
	return locMouse.x >= WelcomeConst::LOC_HELP.x && locMouse.x <= WelcomeConst::LOC_EXIT.x + WelcomeConst::SIZE_BUTTON.x &&
			locMouse.y >= WelcomeConst::LOC_HELP.y && locMouse.y <= WelcomeConst::LOC_HELP.y + WelcomeConst::SIZE_BUTTON.y;
}

bool WelcomeWindow::isMoveExit(const sf::Vector2f& locMouse)
{
	return locMouse.x >= WelcomeConst::LOC_EXIT.x && locMouse.x <= WelcomeConst::LOC_EXIT.x + WelcomeConst::SIZE_BUTTON.x &&
			locMouse.y >= WelcomeConst::LOC_EXIT.y && locMouse.y <= WelcomeConst::LOC_EXIT.y + WelcomeConst::SIZE_BUTTON.y;
}

bool WelcomeWindow::isMoveBack(const sf::Vector2f& locMouse)
{
	return locMouse.x >= WelcomeConst::LOC_BACK.x && locMouse.x <= WelcomeConst::SIZE_BUTTON_BACK.x &&
			locMouse.y >= WelcomeConst::LOC_BACK.y && locMouse.y <= WelcomeConst::SIZE_BUTTON_BACK.y;
}


bool WelcomeWindow::isClickStart(const sf::Vector2f& locMouse)
{
	return isMoveStart(locMouse);
}

bool WelcomeWindow::isClickHelp(const sf::Vector2f& locMouse)
{
	return isMoveHelp(locMouse);
}

bool WelcomeWindow::isClickExit(const sf::Vector2f& locMouse)
{
	return isMoveExit(locMouse);
}

bool WelcomeWindow::isClickBack(const sf::Vector2f& locMouse)
{
	return isMoveBack(locMouse);
}
