#pragma once
#include <SFML/Graphics.hpp>

namespace BombConst {

	const sf::Time COUNT_DOWN_BOMB = sf::seconds(3.f); // ספירה לאחור לפיצוץ
	const sf::Time EXPLOSION_TIME = sf::seconds(1.5); // זמן השארות הפיצוץ

	const std::string NAME_BOMB_EXPLODE_MUSIC = "bombExplodeMusic.wav"; // שמע פיצוץ
	const std::string NAME_COUNT_DOWN_MUSIC  = "countDownMusic.wav"; // שמע ספירה לפיצוץ
}
