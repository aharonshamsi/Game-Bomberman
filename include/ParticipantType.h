#pragma once

enum class ParticipantType {

	Player,
	SmartGuard,
	StupidGuard,
	Door,
	Rock,
	Wall,
	Bomb,
	BombExplosion,
	GiftKillGuard,
	GiftAddTime,
	GiftFreezeGuards,
	GiftAddLife,

	welcomGame, // Background image for the opening window
	FinishGame, // Background image for the game window
	StopGame // image for the Stop game
};