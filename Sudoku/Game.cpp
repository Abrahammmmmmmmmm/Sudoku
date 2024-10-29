#include "Game.h"
#include <iomanip> // for std::setw
#include <iostream>
using namespace std;
void Game::showWelcomeWindow()
{
	while (true)
	{
		cout << "*****************欢迎进入数独游戏*****************" << endl;
		cout << "<<                                              >>" << endl;
		cout << "<<                                              >>" << endl;
		cout << "<<               A -- 进入数独游戏              >>" << endl;
		cout << "<<               B -- 游戏规则说明              >>" << endl;
		cout << "<<               C -- 按键说明                  >>" << endl;
		cout << "<<               D -- 退出游戏                  >>" << endl;
		cout << "<<                                              >>" << endl;
		cout << "<<                                              >>" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "请选择：";
		char choice;
		cin >> choice;
		switch (choice)
		{
		case 'A':
			showSelectDifficultyWindow();
			showMainGameWindow();
			break;
		case 'B':
			system("cls");
			showHelpWindow();
			break;
		case 'C':
			system("cls");
			showPushButtonWindow();
			break;
		case 'D':
			exit(0);
			break;
		}

	}
}
void Game::showPushButtonWindow()
{
	cout << "**********************数独按键说明**********************" << endl;
	cout << "<<                                                    >>" << endl;
	cout << "<<                                                    >>" << endl;
	cout << "<<      进入游戏后要输入3个数：所在行、所在列、其值。 >>" << endl;
	cout << "<<       三个数分别用空格隔开                           " << endl;
	cout << "<<       进入游戏后要输入3个数：所在行、所在列、其值。>>" << endl;
	cout << "<<       输完后用回车键进行确认                       >>" << endl;
	cout << "<<                                                    >>" << endl;
	cout << "<<                                                    >>" << endl;
	cout << "********************************************************" << endl;
	system("pause");
	system("cls");
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
	system("pause");
	system("cls");
}

void Game::showSelectDifficultyWindow()
{
	system("cls");
	cout << "*******选择游戏难度*******" << endl;
	cout << "<<                      >>" << endl;
	cout << "<<      1. 简单         >>" << endl;
	cout << "<<      2. 中等         >>" << endl;
	cout << "<<      3. 困难         >>" << endl;
	cout << "<<      0. 返回         >>" << endl;
	cout << "<<                      >>" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "请选择难度：";
	cin >> difficulty;
	if (difficulty == 0)
	{
		system("cls");
		showWelcomeWindow();
	}
	eraseNumber = difficulty*20;
	cout << "------------------------" << endl;
}

void Game::showBoard(bool isAnswer, Sudoku* newSudoku)
{
	vector<vector<int>> brd(9, vector<int>(9)); // 确定要输出的是哪一个棋盘
	if (isAnswer) brd = newSudoku->ansBoard;
	else brd = newSudoku->board;

	// 定义颜色代码
	const char* colors[] = {
		"\033[0m",  // 重置
		"\033[31m", // 红色
		"\033[32m", // 绿色
		"\033[33m", // 黄色
		"\033[34m", // 蓝色
		"\033[35m", // 紫色
		"\033[36m", // 青色
		"\033[37m", // 白色
		"\033[91m", // 亮红色
		"\033[92m"  // 亮绿色
	};

	printf_s("    1   2   3   4   5   6   7   8   9  \n");
	printf_s("  ╔═══════════╦═══════════╦═══════════╗\n");

	for (int i = 0; i < 9; i++)
	{
		printf_s(" %d║", i + 1);
		for (int j = 0; j < 9; j++)
		{
			if (brd[i][j] == 0)
				printf_s("   ");
			else
				printf_s(" %s%d\033[0m ", colors[brd[i][j]], brd[i][j]);

			if ((j + 1) % 3 == 0)
				printf_s("║");

			else
				printf_s("|");
		}
		printf_s("\n");

		if ((i + 1) % 3 == 0 && i != 8)
			printf_s("  ╠═══════════╬═══════════╬═══════════╣");
		else if (i != 8)
			printf_s("  ║---┼---┼---║---┼---┼---║---┼---┼---║");

		switch (i)
		{
		case 0:cout << "         A -- 输入指定位置" << endl; break;
		case 1:cout << "         B -- 检查结果" << endl; break;
		case 2:cout << "         C -- 查看答案" << endl; break;
		case 3:cout << "         D -- 再来一局" << endl; break;
		case 4:cout << "         E -- 返回" << endl; break;
		case 5:cout << "         F -- 修改已经填入的数字" << endl; break;
		case 6:cout << "         G -- 提示一个数字" << endl; break;
		case 7:cout << endl;
		default:
			break;
		}
	}

	printf_s("  ╚═══════════╩═══════════╩═══════════╝\n");
}


void Game::showMainGameWindow()
{
	cout << "数独游戏" << endl;
	system("cls");

	//初始化棋盘
	vector<vector<int>> board(9, vector<int>(9));
	newSudoku = new Sudoku(board);
	newSudoku->generateGameBoard();
	newSudoku->eraseRandomGrids(eraseNumber);

	showBoard(false, newSudoku);

	//开始玩数独
	while (true)
	{
		char choice;
		cout << "请选择：";
		cin >> choice;
		bool flag = true;		//判定横纵坐标是否合法
		bool flag2 = true;		//判定是否可以修改值
		vector<int>temp(2);		//用于存储所填数字
		int i, j, num;
		switch (choice)
		{
		case 'A':
			while (flag)
			{
				cout << "请输入要填数字的横纵坐标及其值：";
				cin >> i >> j >> num;
				if (i > 9 || i < 1 || j>9 || j < 1)
				{
					cout << "输入错误，请重新输入!" << endl;
					flag = true;
				}
				else if (newSudoku->board[i - 1][j - 1] != 0)
				{
					cout << "对不起，原棋盘已经指定了该位置为" << newSudoku->board[i - 1][j - 1] << ",你不能修改这个值！";
					flag = false;
					flag2 = false;
					system("pause");
				}
				else
				{
					flag = false;
				}
			}
			if (flag2)
			{
				newSudoku->board[i - 1][j - 1] = num;
				temp.push_back(i - 1);
				temp.push_back(j - 1);
				newSudoku->operations[temp] = num;
				
			}
			system("cls");
			showBoard(false, newSudoku);
			break;
		case 'B':
			if (newSudoku->board == newSudoku->ansBoard)			//回答正确
			{
				system("cls");
				cout << "**********************祝贺**********************" << endl;
				cout << "<<                                            >>" << endl;
				cout << "<<                                            >>" << endl;
				cout << "<<                恭喜，你答对了！            >>" << endl;
				cout << "<<                你真是个天才！              >>" << endl;
				cout << "<<                                            >>" << endl;
				cout << "<<                                            >>" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				system("pause");
				system("cls");
				showBoard(false, newSudoku);
			}
			else
			{
				cout << "对不起，你的答案不正确，请再检查一下！" << endl;
				system("pause");
				system("cls");
				showBoard(false, newSudoku);
			}
			break;
		case 'C':
			system("cls");
			showBoard(true, newSudoku);
			system("pause");
			system("cls");
			showBoard(false, newSudoku);
			break;
		case 'D':
			newSudoku->generateGameBoard();
			newSudoku->eraseRandomGrids(eraseNumber);
			system("cls");
			showBoard(false, newSudoku);
			break;
		case 'E':
			system("cls");
			showWelcomeWindow();
			break;
		case 'F':
			vector<int>temp2(2);
			cout << "请输入你想修改的数字的位置以及值：";
			cin >> i >> j >> num;
			temp2.push_back(i - 1);
			temp2.push_back(j - 1);
			cout << (newSudoku->operations.find(temp2) == newSudoku->operations.end()) << endl;
			if (newSudoku->operations.find(temp2) != newSudoku->operations.end())	//如果想修改的数字确实是在之前棋盘上的空格上填入过的
			{
				newSudoku->board[i - 1][j - 1] = num;
				system("cls");
				showBoard(false, newSudoku);
			}
			else if (newSudoku->board[i - 1][j - 1] == 0)			//如果想修改的位置还没有填入数字
			{
				cout << "修改位置错误，该位置还没有填入数字呢！" << endl;
				system("pause");
				system("cls");
				showBoard(false,newSudoku);
			}
			else                    //如果要修改的位置是属于一开始就固定的棋盘布局中的位置
			{
				cout << "修改位置错误，该位置的数字是系统起初设置的固定的数字，不能修改的！" << endl;
				system("pause");
				system("cls");
				showBoard(false, newSudoku);
			}
		}
	}
}