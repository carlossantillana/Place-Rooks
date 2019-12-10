#ifndef __ROOKBOARD_H__
#define __ROOKBOARD_H__

#include<iostream>
#include <vector>
using namespace std;

void readBoard (string fileName, vector<vector<bool>> &board,
  vector<pair<int,int>> &rooks);

void newRooks(vector<pair<int,int>> &rooks, vector<pair<int,int>> &newRook);

void updateBoard(vector<pair<int,int>> &newRook, vector<vector<bool>> &board);

void printBoard(vector<vector<bool>> &board);

bool conflict(vector<vector<bool>> &board);
#endif
