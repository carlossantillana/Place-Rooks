#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include "../rookBoard.h"

void readBoard (string fileName, vector<vector<bool>> &board,
  vector<pair<int,int>> &rooks);
void intersects(vector<vector<bool>> &board);

TEST_CASE("Testing readBoard()") {

  SECTION( "Testing valid input" ) {
    vector<vector<bool>> board;
    vector<pair<int,int>> rooks;

    readBoard("validBoard.txt", board, rooks);
    CHECK_NOTHROW(intersects(board));
    REQUIRE( board.size() == 8 );
    REQUIRE( board.at(0).size() == 8 );
  }

  SECTION( "Testing invalid fileName" ) {
    vector<vector<bool>> board;
    vector<pair<int,int>> rooks;
    REQUIRE_THROWS_WITH(readBoard("kfjskl.txt", board, rooks), Catch::Contains("Error: Invalid fileName. May not exist."));
  }

  SECTION( "Testing too large input board" ) {
    vector<vector<bool>> board;
    vector<pair<int,int>> rooks;
    readBoard("tooLargeBoard.txt", board, rooks);

    CHECK_NOTHROW(intersects(board));
    REQUIRE( board.size() == 8 );
    REQUIRE( board.at(0).size() == 8 );
  }

}

TEST_CASE("Testing newRooks()") {
  vector<vector<bool>> board;
  vector<pair<int,int>> rooks;
  vector<pair<int,int>> newRook;

  readBoard("validBoard.txt", board, rooks);
  CHECK_NOTHROW(intersects(board));
  newRooks(rooks, newRook);

  REQUIRE( newRook.at(0).first == 3);
  REQUIRE( newRook.at(0).second == 3);

  REQUIRE( newRook.at(1).first == 4);
  REQUIRE( newRook.at(1).second == 4);

  REQUIRE( newRook.at(2).first == 5);
  REQUIRE( newRook.at(2).second == 5);

  REQUIRE( newRook.at(3).first == 6);
  REQUIRE( newRook.at(3).second == 6);

}
TEST_CASE("Testing updateBoard()") {
  vector<vector<bool>> board;
  vector<pair<int,int>> rooks;
  vector<pair<int,int>> newRook;
  vector<vector<bool>> expected;
  vector<bool> rowOne = {1,0,0,0,0,0,0,0};
  vector<bool> rowTwo = {0,0,1,0,0,0,0,0};
  vector<bool> rowThree = {0,1,0,0,0,0,0,0};
  vector<bool> rowFour = {0,0,0,1,0,0,0,0};
  vector<bool> rowFive = {0,0,0,0,1,0,0,0};
  vector<bool> rowSix = {0,0,0,0,0,1,0,0};
  vector<bool> rowSeven = {0,0,0,0,0,0,1,0};
  vector<bool> rowEight = {0,0,0,0,0,0,0,1};
  expected.push_back(rowOne);
  expected.push_back(rowTwo);
  expected.push_back(rowThree);
  expected.push_back(rowFour);
  expected.push_back(rowFive);
  expected.push_back(rowSix);
  expected.push_back(rowSeven);
  expected.push_back(rowEight);

  readBoard("validBoard.txt", board, rooks);
  CHECK_NOTHROW(intersects(board));
  newRooks(rooks, newRook);
  updateBoard(newRook, board);
  CHECK_NOTHROW(intersects(board));
  CHECK_THAT(board, Catch::Equals(expected));

}

TEST_CASE("Testing intersects()") {

  SECTION( "Rooks intersect" ) {
    vector<vector<bool>> board;
    vector<pair<int,int>> rooks;
    readBoard("intersectingRooksBoard.txt", board, rooks);
    REQUIRE_THROWS_WITH(intersects(board), Catch::Contains("Error: Board inputted intersects"));
  }

  SECTION( "Testing too Many Rooks on input board" ) {
    vector<vector<bool>> board;
    vector<pair<int,int>> rooks;
    readBoard("tooManyRooksBoard.txt", board, rooks);
    REQUIRE_THROWS_WITH(intersects(board), Catch::Contains("Error: Board inputted intersects"));
  }
  SECTION( "Testing does not intersect" ) {
    vector<vector<bool>> board;
    vector<pair<int,int>> rooks;
    readBoard("validBoard.txt", board, rooks);
    CHECK_NOTHROW(intersects(board));
  }

  SECTION( "Testing chess board too short length wise" ) {
    vector<vector<bool>> board;
    vector<pair<int,int>> rooks;
    readBoard("shortBoardLengthWise.txt", board, rooks);
    REQUIRE_THROWS_WITH(intersects(board), Catch::Contains("Error: Board provided too short"));
  }

  SECTION( "Testing chess board too short column wise" ) {
    vector<vector<bool>> board;
    vector<pair<int,int>> rooks;
    readBoard("shortBoardRowWise.txt", board, rooks);
    REQUIRE_THROWS_WITH(intersects(board), Catch::Contains("Error: Board provided too short"));
  }
}
