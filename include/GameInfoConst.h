#pragma once

namespace GameInfoConst {

	const sf::Vector2f SIZE_INFO(1000.f, 500.f); // גודל הצורה
	const sf::Vector2f LOC_SHAPE(0.f,1000.f); // מיקום הצורה
	const sf::Vector2f LOC_TEXT(50.f, 1070.f); // מיקום הטקסט
	const sf::Color COLOR_SHAPE_INFO = sf::Color(103, -0, 30); // צבע המלבן
	const unsigned int SIZE_CHARACTER = 70; // גודל פונט הכיתוב

	const int LIFE = 4;
	const int KILL_GUARD = 5;
	const int LEVEL_GUARD = 3;
	const int END_LEVEL = 25;

	const int NUM_GIFTS_UNDER_ROKE = 2; // רנדומלאלי סיכוי 50 אחוז למתנה מתחת לסלע
	const int NUM_GIFTS_IN_SPACE = 25; // רנדומלאלי סיכוי אחד חלקי 20 למתנה כללי בלוח המשחק 

	const float TIME_LEVEL_ONE = 2 * 60.f;   // דקות לשלב 1
	const float TIME_LEVEL_TWO = 3 * 60.f;   // דקות לשלב 2
	const float TIME_ALL_LEVEL = 4 * 60.f; // דקות לכל השלבים 3

	const float ADD_TIME = 30.f;

	const float GUARD_FREEZE_TIME = 4.f; // זמן הקפאה שומרים


	const std::string LEVEL_OUTPUT = "Level: ";
	const std::string LIVES_OUTPUT = "\nLives: ";
	const std::string SCORE_OUTPUT = "\nScore: ";
	const std::string TIMER_OUTPUT = "\nTimer: ";

	const std::string NAME_THROW_BOMB_MUSIC = "throwBombMusic.wav"; // שמע זריקת פצצה
	const std::string NAME_TAKING_GIFT_MUSIC = "PlayTakingGiftMusic.mp3"; // שמע איסוף מתנה

}