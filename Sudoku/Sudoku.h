#pragma once
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <vector>
using namespace std;
class Sudoku {
private:
	vector<vector<int>> board;
public:
	Sudoku(const vector<vector<int>>& _board);
	void generateGameBoard(int difficulty);
	void showGameBoard();
	void eraseRandomGrids(int eraseNumber);
	inline unsigned int random(int begin, int end)
	{
		assert(end >= begin && begin >= 0);
		srand(time(NULL));
		return (unsigned int)rand() % (end - begin + 1) + begin;
	}
};

