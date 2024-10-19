#include "Sudoku.h"
#include "Game.h"
#include <vector>
using namespace std;
int main()
{
	Game* newGame = new Game;
	newGame->showWelcomeWindow();
	
	system("pause");
	return 0;
}