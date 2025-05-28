#pragma once
#include "FontHolder.h"
#include "Images.h"
#include "WelcomeWindow.h"
#include "GameWindow.h"
#include "GameManager.h"


class GeneralManager {

public:

	GeneralManager();

	void runProgram();

private:
	WelcomeWindow m_welcomeWindow;
};

