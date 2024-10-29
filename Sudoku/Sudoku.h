#pragma once

#include <vector>
#include<unordered_map>

struct VectorHash {
    std::size_t operator()(const std::vector<int>& v) const {
        std::hash<int> int_hash;
        std::size_t seed = 0;
        for (auto& item : v) {
            seed ^= int_hash(item) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

using namespace std;
class Sudoku {
private:
	vector<vector<int>> board;
	vector<vector<int>>ansBoard;		//�洢���̴�
public:
    unordered_map<vector<int>, int, VectorHash>operations;		//��¼����ɵĲ���
	Sudoku(const vector<vector<int>>& _board);
	void generateGameBoard();
	void showGameBoard();
	void eraseRandomGrids(int eraseNumber);
	
    friend class Game;
};