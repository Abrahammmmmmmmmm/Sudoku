#include "Game.h"
#include <iomanip> // for std::setw
#include <iostream>
using namespace std;
void Game::showWelcomeWindow()
{
	while (true)
	{
		cout << "*****************��ӭ����������Ϸ*****************" << endl;
		cout << "<<                                              >>" << endl;
		cout << "<<                                              >>" << endl;
		cout << "<<               A -- ����������Ϸ              >>" << endl;
		cout << "<<               B -- ��Ϸ����˵��              >>" << endl;
		cout << "<<               C -- ����˵��                  >>" << endl;
		cout << "<<               D -- �˳���Ϸ                  >>" << endl;
		cout << "<<                                              >>" << endl;
		cout << "<<                                              >>" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "��ѡ��";
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
	cout << "**********************��������˵��**********************" << endl;
	cout << "<<                                                    >>" << endl;
	cout << "<<                                                    >>" << endl;
	cout << "<<      ������Ϸ��Ҫ����3�����������С������С���ֵ�� >>" << endl;
	cout << "<<       �������ֱ��ÿո����                           " << endl;
	cout << "<<       ������Ϸ��Ҫ����3�����������С������С���ֵ��>>" << endl;
	cout << "<<       ������ûس�������ȷ��                       >>" << endl;
	cout << "<<                                                    >>" << endl;
	cout << "<<                                                    >>" << endl;
	cout << "********************************************************" << endl;
	system("pause");
	system("cls");
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
	system("pause");
	system("cls");
}

void Game::showSelectDifficultyWindow()
{
	system("cls");
	cout << "*******ѡ����Ϸ�Ѷ�*******" << endl;
	cout << "<<                      >>" << endl;
	cout << "<<      1. ��         >>" << endl;
	cout << "<<      2. �е�         >>" << endl;
	cout << "<<      3. ����         >>" << endl;
	cout << "<<      0. ����         >>" << endl;
	cout << "<<                      >>" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "��ѡ���Ѷȣ�";
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
	vector<vector<int>> brd(9, vector<int>(9)); // ȷ��Ҫ���������һ������
	if (isAnswer) brd = newSudoku->ansBoard;
	else brd = newSudoku->board;

	// ������ɫ����
	const char* colors[] = {
		"\033[0m",  // ����
		"\033[31m", // ��ɫ
		"\033[32m", // ��ɫ
		"\033[33m", // ��ɫ
		"\033[34m", // ��ɫ
		"\033[35m", // ��ɫ
		"\033[36m", // ��ɫ
		"\033[37m", // ��ɫ
		"\033[91m", // ����ɫ
		"\033[92m"  // ����ɫ
	};

	printf_s("    1   2   3   4   5   6   7   8   9  \n");
	printf_s("  �X�T�T�T�T�T�T�T�T�T�T�T�j�T�T�T�T�T�T�T�T�T�T�T�j�T�T�T�T�T�T�T�T�T�T�T�[\n");

	for (int i = 0; i < 9; i++)
	{
		printf_s(" %d�U", i + 1);
		for (int j = 0; j < 9; j++)
		{
			if (brd[i][j] == 0)
				printf_s("   ");
			else
				printf_s(" %s%d\033[0m ", colors[brd[i][j]], brd[i][j]);

			if ((j + 1) % 3 == 0)
				printf_s("�U");

			else
				printf_s("|");
		}
		printf_s("\n");

		if ((i + 1) % 3 == 0 && i != 8)
			printf_s("  �d�T�T�T�T�T�T�T�T�T�T�T�p�T�T�T�T�T�T�T�T�T�T�T�p�T�T�T�T�T�T�T�T�T�T�T�g");
		else if (i != 8)
			printf_s("  �U---��---��---�U---��---��---�U---��---��---�U");

		switch (i)
		{
		case 0:cout << "         A -- ����ָ��λ��" << endl; break;
		case 1:cout << "         B -- �����" << endl; break;
		case 2:cout << "         C -- �鿴��" << endl; break;
		case 3:cout << "         D -- ����һ��" << endl; break;
		case 4:cout << "         E -- ����" << endl; break;
		case 5:cout << "         F -- �޸��Ѿ����������" << endl; break;
		case 6:cout << "         G -- ��ʾһ������" << endl; break;
		case 7:cout << endl;
		default:
			break;
		}
	}

	printf_s("  �^�T�T�T�T�T�T�T�T�T�T�T�m�T�T�T�T�T�T�T�T�T�T�T�m�T�T�T�T�T�T�T�T�T�T�T�a\n");
}


void Game::showMainGameWindow()
{
	cout << "������Ϸ" << endl;
	system("cls");

	//��ʼ������
	vector<vector<int>> board(9, vector<int>(9));
	newSudoku = new Sudoku(board);
	newSudoku->generateGameBoard();
	newSudoku->eraseRandomGrids(eraseNumber);

	showBoard(false, newSudoku);

	//��ʼ������
	while (true)
	{
		char choice;
		cout << "��ѡ��";
		cin >> choice;
		bool flag = true;		//�ж����������Ƿ�Ϸ�
		bool flag2 = true;		//�ж��Ƿ�����޸�ֵ
		vector<int>temp(2);		//���ڴ洢��������
		int i, j, num;
		switch (choice)
		{
		case 'A':
			while (flag)
			{
				cout << "������Ҫ�����ֵĺ������꼰��ֵ��";
				cin >> i >> j >> num;
				if (i > 9 || i < 1 || j>9 || j < 1)
				{
					cout << "�����������������!" << endl;
					flag = true;
				}
				else if (newSudoku->board[i - 1][j - 1] != 0)
				{
					cout << "�Բ���ԭ�����Ѿ�ָ���˸�λ��Ϊ" << newSudoku->board[i - 1][j - 1] << ",�㲻���޸����ֵ��";
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
			if (newSudoku->board == newSudoku->ansBoard)			//�ش���ȷ
			{
				system("cls");
				cout << "**********************ף��**********************" << endl;
				cout << "<<                                            >>" << endl;
				cout << "<<                                            >>" << endl;
				cout << "<<                ��ϲ�������ˣ�            >>" << endl;
				cout << "<<                �����Ǹ���ţ�              >>" << endl;
				cout << "<<                                            >>" << endl;
				cout << "<<                                            >>" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				system("pause");
				system("cls");
				showBoard(false, newSudoku);
			}
			else
			{
				cout << "�Բ�����Ĵ𰸲���ȷ�����ټ��һ�£�" << endl;
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
			cout << "�����������޸ĵ����ֵ�λ���Լ�ֵ��";
			cin >> i >> j >> num;
			temp2.push_back(i - 1);
			temp2.push_back(j - 1);
			cout << (newSudoku->operations.find(temp2) == newSudoku->operations.end()) << endl;
			if (newSudoku->operations.find(temp2) != newSudoku->operations.end())	//������޸ĵ�����ȷʵ����֮ǰ�����ϵĿո����������
			{
				newSudoku->board[i - 1][j - 1] = num;
				system("cls");
				showBoard(false, newSudoku);
			}
			else if (newSudoku->board[i - 1][j - 1] == 0)			//������޸ĵ�λ�û�û����������
			{
				cout << "�޸�λ�ô��󣬸�λ�û�û�����������أ�" << endl;
				system("pause");
				system("cls");
				showBoard(false,newSudoku);
			}
			else                    //���Ҫ�޸ĵ�λ��������һ��ʼ�͹̶������̲����е�λ��
			{
				cout << "�޸�λ�ô��󣬸�λ�õ�������ϵͳ������õĹ̶������֣������޸ĵģ�" << endl;
				system("pause");
				system("cls");
				showBoard(false, newSudoku);
			}
		}
	}
}