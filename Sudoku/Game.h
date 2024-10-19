#pragma once
#include "Sudoku.h"
#include <iostream>
using namespace std;
class Game
{
public:
	Game() {}
	void showWelcomeWindow();
	void showHelpWindow();
	void showSelectDifficultyWindow();
	void showMainGameWindow();

private:
	int difficulty;
	int eraseNumber;
	Sudoku* newSudoku;
};

