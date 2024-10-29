#include "Sudoku.h"
#include "Game.h"
#include <vector>
#include<random>
using namespace std;
int main()
{
	Game* newGame = new Game;
	newGame->showWelcomeWindow();
	system("pause");
	return 0;
}