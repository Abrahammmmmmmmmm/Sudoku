#include "Sudoku.h"
#include <iostream>
#include <random> 
#include <set>


//拷贝构造函数
Sudoku::Sudoku(const vector<vector<int>>& _board) : board(9, vector<int>(9))        
{
    // Initialize Sudoku game board
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            board[i][j] = _board[i][j];

}

// 生成一个随机的数独游戏盘面
void Sudoku::generateGameBoard()
{
    char map_pattern[10][10] = {
        "ighcabfde",
        "cabfdeigh",
        "fdeighcab",
        "ghiabcdef",
        "abcdefghi",
        "defghiabc",
        "higbcaefd",
        "bcaefdhig",
        "efdhigbca" };
    vector<char> v = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' };

    // 产生字母到数字的随机映射
    unordered_map<char, int> hash_map;
    random_device rd;
    mt19937 gen(rd());
    for (int i = 1; i <= 9; ++i)
    {
        uniform_int_distribution<> dis(0, v.size() - 1);
        int r = dis(gen);
        hash_map[v[r]] = i;
        v.erase(v.begin() + r);
    }

    // 生成数独盘面
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            board[i][j] = hash_map[map_pattern[i][j]];
        }
    }
    ansBoard = board;
}

// 显示数独游戏盘面
void Sudoku::showGameBoard()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


void Sudoku::eraseRandomGrids(int eraseNumber)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 8);
    set<pair<int, int>> erasedPositions; // 用于跟踪已擦除的位置

    while (erasedPositions.size() < eraseNumber)
    {
        int x = dis(gen);
        int y = dis(gen);
        if (erasedPositions.find({ x, y }) == erasedPositions.end())
        {
            board[x][y] = 0;
            erasedPositions.insert({ x, y });
        }
    }
}