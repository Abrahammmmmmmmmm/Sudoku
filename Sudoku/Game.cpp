#include "Game.h"
void Game::showWelcomeWindow()
{
	cout << "        " << "A. �鿴��Ϸ����" << endl;
	cout << "        " << "B. ��ʼ��Ϸ" << endl;
	cout << "------------------------" << endl;
	cout << "��ѡ�������";
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
	cout << "������Ϸ����" << endl;
	cout << "1. ������һ���߼���Ϸ��Ŀ��������һ��9x9�ĸ��ӣ�ʹ��ÿһ�С�ÿһ�к�ÿһ��3x3��С����������1-9��ֻ����һ�Ρ�" << endl;
	cout << "2. ��Ϸ��ʼʱ�����ָ����Ѿ��������֣������Ҫ������Щ��֪�������ƶϳ��������ӵ����֡�" << endl;
	cout << "3. ��Ϸ�Ѷȷ�Ϊ�򵥡��еȺ��������֣��Ѷ�Խ�ߣ���Ҫ�ƶϵ�����Խ�ࡣ" << endl;
	cout << "4. ��ҿ���ͨ������������������д���ӣ�����0��ʾ��ո��ӡ�" << endl;
	cout << "5. ��Ϸ����ʱ����������д�����ַ���������������Ϸʤ����" << endl;
	cout << "------------------------" << endl;

	showWelcomeWindow();
}

void Game::showSelectDifficultyWindow()
{
	cout << "ѡ����Ϸ�Ѷ�" << endl;
	cout << "        " << "1. ��" << endl;
	cout << "        " << "2. �е�" << endl;
	cout << "        " << "3. ����" << endl;
	cout << "------------------------" << endl;
	cout << "��ѡ���Ѷȣ�";
	cin >> difficulty;
	eraseNumber = difficulty*20;
	cout << "------------------------" << endl;
}

void Game::showMainGameWindow()
{
	cout << "������Ϸ" << endl;
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