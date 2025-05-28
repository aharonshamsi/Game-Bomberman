#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace GameWindowConst {

	const sf::Vector2f SIZE_GAME_WINDOW(1000.f, 1500.f); // גודל החלון משחק

	const std::string NAME_GAME = "Bomberman";
	const std::string NAME_PLAYLIST_LEVELS = "playlistLevels.txt";

	const std::string GAME_BACKGROUND_MUSIC = "GameBackgroundMusic.mp3";
	const std::string PLAYER_FAILED_MUSIC = "PlayerFailedMusic.mp3"; // צליל פסול משחק
	const std::string FINISH_GAME_MUSIC = "finishGameMusic.ogg"; // צליל פסול משחק
	const std::string NAME_MOVE_LEVEL = "moveLevel.wav"; // שמע עובר שלב

}