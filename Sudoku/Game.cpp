#include "Game.h"
void Game::showWelcomeWindow()
{
	cout << "        " << "A. 查看游戏规则" << endl;
	cout << "        " << "B. 开始游戏" << endl;
	cout << "------------------------" << endl;
	cout << "请选择操作：";
	char choice;
	cin >> choice;
	switch (choice)
	{
	case 'A':
		showHelpWindow();
		break;
	case 'B':
		showSelectDifficultyWindow();
		showMainGameWindow();
		break;
	}

}

void Game::showHelpWindow()
{
	cout << "数独游戏规则" << endl;
	cout << "1. 数独是一种逻辑游戏，目的是填满一个9x9的格子，使得每一行、每一列和每一个3x3的小格子中数字1-9都只出现一次。" << endl;
	cout << "2. 游戏开始时，部分格子已经填有数字，玩家需要根据这些已知的数字推断出其他格子的数字。" << endl;
	cout << "3. 游戏难度分为简单、中等和困难三种，难度越高，需要推断的数字越多。" << endl;
	cout << "4. 玩家可以通过键盘输入数字来填写格子，输入0表示清空格子。" << endl;
	cout << "5. 游戏结束时，如果玩家填写的数字符合数独规则，则游戏胜利。" << endl;
	cout << "------------------------" << endl;

	showWelcomeWindow();
}

void Game::showSelectDifficultyWindow()
{
	cout << "选择游戏难度" << endl;
	cout << "        " << "1. 简单" << endl;
	cout << "        " << "2. 中等" << endl;
	cout << "        " << "3. 困难" << endl;
	cout << "------------------------" << endl;
	cout << "请选择难度：";
	cin >> difficulty;
	eraseNumber = difficulty*20;
	cout << "------------------------" << endl;
}

void Game::showMainGameWindow()
{
	cout << "数独游戏" << endl;
	vector<vector<int>> board(9, vector<int>(9));
	newSudoku = new Sudoku(board);
	newSudoku->generateGameBoard(difficulty);
	newSudoku->showGameBoard();
	cout << endl;
	cout << "------------------------" << endl;
	cout << endl;
	newSudoku->eraseRandomGrids(eraseNumber);
	newSudoku->showGameBoard();
}