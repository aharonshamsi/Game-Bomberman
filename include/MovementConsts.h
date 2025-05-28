#pragma once

namespace MovementConsts
{
	const float MOVE_PIXEL_PLAYER = 125.f; // מהירות התזוזה
	const float MOVE_PIXEL_SMART_GUARD = 70.f; // מהירות התזוזה
	const float MOVE_PIXEL_STUPID_GUARD = 70.f; // מהירות התזוזה

	const sf::Vector2f DIRECTION_RIGHT = sf::Vector2f(1.f, 0.f);
	const sf::Vector2f DIRECTION_LEFT = sf::Vector2f(-1.f, 0.f);
	const sf::Vector2f DIRECTION_UP = sf::Vector2f(0.f, -1.f);
	const sf::Vector2f DIRECTION_DOWN = sf::Vector2f(0.f, 1.f);
	const sf::Vector2f NO_DIRECTION = sf::Vector2f(0.f, 0.f);

}