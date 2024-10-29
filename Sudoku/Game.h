#pragma once
#include "Sudoku.h"
class Game
{
public:
	void showWelcomeWindow();
	void showHelpWindow();
	void showSelectDifficultyWindow();
	void showMainGameWindow();
	void showPushButtonWindow();		//按键说明
	void showBoard(bool isAnswer,Sudoku *newSudoku);			//展示棋盘
private:
	int difficulty;
	int eraseNumber;
	Sudoku* newSudoku;
};

