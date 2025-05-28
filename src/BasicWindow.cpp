#include "BasicWindow.h"

BasicWindow::BasicWindow(const sf::Vector2f& size, const std::string& nameWindow, const sf::Sprite& backgroundPicture)
	:m_windowSize(size), m_window(sf::VideoMode(unsigned (m_windowSize.x), unsigned(m_windowSize.y)), nameWindow) ,
	m_backgroundPicture(backgroundPicture)
{
}

bool BasicWindow::isopen() const
{
	return m_window.isOpen();
}

void BasicWindow::close()
{
	m_window.close();
}

void BasicWindow::clear()
{
	m_window.clear();
}

void BasicWindow::display()
{
	m_window.display();
}

void BasicWindow::playBackgroundMusicMusic()
{
	m_backgroundMusic.play();
}

void BasicWindow::stopBackgroundMusicMusic()
{
	m_backgroundMusic.stop();
}

void BasicWindow::setBackgroundLoop(bool loop)
{
	m_backgroundMusic.setLoop(loop);
}

void BasicWindow::drawBackgroundPicture()
{
	m_window.draw(m_backgroundPicture);
}
