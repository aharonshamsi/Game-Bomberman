#include <SFML/Graphics.hpp>
#include <string>


namespace WelcomeConst {

	const sf::Vector2f SIZE_WINDOW(1000.f, 1500.f);

	const std::string NAME_HELP = "Help";
	const std::string NAME_START = "Start";
	const std::string NAME_EXIT = "Exit";
	const std::string NAME_BACK = "X";

	const sf::Vector2f SIZE_BUTTON(300.f, 110.f); // גודל כפתור
	const sf::Vector2f SIZE_BUTTON_BACK(80.f, 80.f); // גודל כפתור חזרה

	const sf::Vector2f LOC_START(345.f, 920.f); // מיקום כפתור
	const sf::Vector2f LOC_HELP(345.f, 1045.f);
	const sf::Vector2f LOC_EXIT(345.f, 1170.f);
	const sf::Vector2f LOC_BACK(0.f, 0.f); // מיקום כפתור חזרה

	const std::string NAME_PLAYER = "Bomberman game menu";
	const std::string NAME_FONT = "Athelas.ttc";
	const std::string NAME_FILE_INFO_HELP = "informationHelp.txt";
	const std::string NAME_FILE_MUSIC = "welcomeMusic.ogg";

	const sf::Vector2f LOC_INFO_HELP(120.f, 120.f); // מיקום אינפורמציה עזרה על החלון
	const int SIZE_FONT_HELP = 45;
	const int SIZE_FONT_BUTTON = 70; // גודל כיתוב בכפתור

}