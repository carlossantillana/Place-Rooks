#include<iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

//check for invalid input
void readBoard (string fileName, vector<vector<bool>> &board,
  vector<pair<int,int>> &rooks) {
  string currentLine;
  ifstream boardFile (fileName);
  if (boardFile.is_open()){
    vector<bool> currentRow;
    //add check here for invalid input
    int i = 0;
    while (getline (boardFile, currentLine)){
      int j = 0;
      stringstream line(currentLine);
      string currentSquare;
      while (getline (line, currentSquare, ',')){
        currentRow.push_back(stoi(currentSquare));
        if (1 == stoi(currentSquare)){
            rooks.push_back(make_pair(j, i));
        }
        if (currentRow.size() == 8){
          board.push_back(currentRow);
          currentRow.clear();
          currentSquare.clear();
          i++;
        }
        j++;
      }
    }
    boardFile.close();
  }
}

void newRooks(vector<pair<int,int>> &rooks, vector<pair<int,int>> &newRook){
  vector<int> validX (8, 1);
  vector<int> validY (8, 1);

  for (auto& i : rooks){
    validX.at(i.first) = 0;
    validY.at(i.second) = 0;
  }

  {
    int a = 0;
    int b = 0;
    while (a < 8 || b < 8){
      while (a < 8  && validX.at(a) == 0){
        a++;
      }
      while (b < 8 && validY.at(b) == 0){
        b++;
      }
      if (b < 8 && b < 8){
        newRook.push_back(make_pair(a,b));
    }
      a++;
      b++;
    }
  }
}

void updateBoard(vector<pair<int,int>> &newRook, vector<vector<bool>> &board){
  for (auto& r : newRook){
    board.at(r.second).at(r.first) = 1;
  }
}
void printBoard(vector<vector<bool>> &board){
  for (const auto& y : board){
    int s = 0;
    for (const auto&x : y){
      cout << x;
      s++;
      if (s < 8){
        cout << ",";
      }
    }
    cout << endl;
  }
}
int main (int argc, char* argv[]) {
    vector<vector<bool>> board;
    vector<pair<int,int>> rooks;
    vector<pair<int,int>> newRook;

    readBoard(argv[1], board, rooks);
    cout << "initial board\n";
    printBoard(board);
    newRooks(rooks, newRook);
    updateBoard(newRook, board);
    cout << "\nfinished board\n";
    printBoard(board);
  return 0;
};
