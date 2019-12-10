#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include "../rookBoard.h"

void readBoard (string fileName, vector<vector<bool>> &board,
  vector<pair<int,int>> &rooks);

TEST_CASE("Testing readBoard()") {
  vector<vector<bool>> board;
  vector<pair<int,int>> rooks;

  SECTION( "Testing valid input" ) {
    readBoard("sampleBoard.txt", board, rooks);
    REQUIRE( board.size() == 8 );
    REQUIRE( board.size().at(0) == 8 );
  }

  SECTION( "Testing invalid input" ) {
    readBoard("sampleBoard.txt", board, rooks);
    REQUIRE( board.size() == 8 );
  }

}

TEST_CASE("Testing newRooks()") {

}
TEST_CASE("Testing updateBoard()") {

}

TEST_CASE("Testing printBoard()") {

}

TEST_CASE("Testing conflicts()") {

}
