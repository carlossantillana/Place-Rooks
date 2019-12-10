#include "rookBoard.h"

void readBoard (string fileName, vector<vector<bool>> &board,
  vector<pair<int,int>> &rooks);
void newRooks(vector<pair<int,int>> &rooks, vector<pair<int,int>> &newRook);
void updateBoard(vector<pair<int,int>> &newRook, vector<vector<bool>> &board);
void printBoard(vector<vector<bool>> &board);

int main (int argc, char* argv[]) {
    vector<vector<bool>> board;
    vector<pair<int,int>> rooks;
    vector<pair<int,int>> newRook;

    readBoard(argv[1], board, rooks);
    cout << "initial board\n";
    printBoard(board);
    newRooks(rooks, newRook);
    updateBoard(newRook, board);
    cout << "\nfull board\n";
    printBoard(board);
  return 0;
};
