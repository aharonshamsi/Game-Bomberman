﻿#include "GeneralManager.h"

int main()
{
	FontHolder::loadFont();
	Images::loadAllTextures();

	GeneralManager progManager;
	progManager.runProgram();

	return EXIT_SUCCESS;
}
