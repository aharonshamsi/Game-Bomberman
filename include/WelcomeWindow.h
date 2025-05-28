#pragma once
#include "BasicWindow.h"
#include "Button.h"
#include <fstream>


class WelcomeWindow: public BasicWindow {

public:

    WelcomeWindow();

    bool managerWelcomeWindow();

private:

    Button m_start;
    Button m_help;
    Button m_exit;
    Button m_back;

    sf::Text m_textHelp;

    void infoHelp();

    std::string readInfoHelpToFile();
    void drawAll();
    void drawHelp();


    bool isMoveStart(const sf::Vector2f& locMouse);
    bool isMoveHelp(const sf::Vector2f& locMouse);
    bool isMoveExit(const sf::Vector2f& locMouse);
    bool isMoveBack(const sf::Vector2f& locMouse);

    bool isClickStart(const sf::Vector2f& locMouse);
    bool isClickHelp(const sf::Vector2f& locMouse);
    bool isClickExit(const sf::Vector2f& locMouse);
    bool isClickBack(const sf::Vector2f& locMouse);

    void managerMove(const sf::Vector2f& locMove, bool& isHelp);
    void mamagerPressed(const sf::Vector2f& locPressed, bool& isHelp, bool& start);

};
