#include <sstream>
#include <fstream>
#include <stdexcept>

#include "rookBoard.h"

void readBoard (string fileName, vector<vector<bool>> &board,
  vector<pair<int,int>> &rooks) {
    bool invalidChars = false;
  while (fileName == ""){
    cout << "Please type fileName containing rookBoard then press enter\n";
    cin >> fileName;
  }
  string currentLine;
  ifstream boardFile (fileName);
  if (boardFile.is_open()){
    vector<bool> currentRow;
    int i = 0;
    while (getline (boardFile, currentLine)){
      int j = 0;
      stringstream line(currentLine);
      string currentSquare;
      while (getline (line, currentSquare, ',')){
        try{
        if (stoi(currentSquare) != 1 &&  stoi(currentSquare) != 0){
          invalidChars = true;
          break;
        }
      } catch (...) {
        throw invalid_argument( "Error: Invalid character on board" );
      }
        currentRow.push_back(stoi(currentSquare));
        if (1 == stoi(currentSquare)){
            rooks.push_back(make_pair(j, i));
        }
        if (currentRow.size() == 8){
          board.push_back(currentRow);
          currentRow.clear();
          currentSquare.clear();
          line.clear();
          i++;
        }
        j++;
        if (j == 8){
          break;
        }
      }
    }
    boardFile.close();
  } else {
    throw invalid_argument( "Error: Invalid fileName. May not exist." );
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
    while (a < 8 || b < 8 ){
      while (a < validX.size() && validX.at(a) == 0){
        a++;
      }
      while (b < validY.size() && validY.at(b) == 0){
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

void intersects(vector<vector<bool>> &board){
  bool intersecting = false;
  if (board.size() < 8){
    throw invalid_argument( "Error: Board provided too short" );
  }
  for (int i = 0; i < board.size(); i++){
    int numRooks = 0;
    for (int j = 0; j < board.at(i).size() && !intersecting; j++){
      if (board.at(i).size() < 8){
        throw invalid_argument( "Error: Board provided too short" );
      }
        if (board.at(i).at(j) == 1){
          numRooks++;
        }
        if (numRooks > 1){
          intersecting = true;
        }
    }
    numRooks = 0;
    for (int j = 0; j < board.at(i).size() && !intersecting; j++){
        if (board.at(j).at(i) == 1){
          numRooks++;
        }
        if (numRooks > 1){
          intersecting = true;
        }
    }
  }
  if (intersecting){
    throw invalid_argument( "Error: Board inputted intersects" );
  }
}
