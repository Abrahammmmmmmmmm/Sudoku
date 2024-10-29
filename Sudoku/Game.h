#pragma once
#include "Sudoku.h"
class Game
{
public:
	void showWelcomeWindow();
	void showHelpWindow();
	void showSelectDifficultyWindow();
	void showMainGameWindow();
	void showPushButtonWindow();		//����˵��
	void showBoard(bool isAnswer,Sudoku *newSudoku);			//չʾ����
private:
	int difficulty;
	int eraseNumber;
	Sudoku* newSudoku;
};

