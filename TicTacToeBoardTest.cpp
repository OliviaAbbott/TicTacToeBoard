/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, toggleTurnTestO)
{
	TicTacToeBoard game;
	Piece myPiece = game.toggleTurn();
	ASSERT_EQ(myPiece, O);
}

TEST(TicTacToeBoardTest, toggleTurnTestX)
{
	TicTacToeBoard game;
	Piece myPiece = game.toggleTurn();
	myPiece = game.toggleTurn();
	ASSERT_EQ(myPiece, X);
}

TEST(TicTacToeBoardTest, placePieceTestValidX)
{
	TicTacToeBoard game;
	Piece myPiece = game.placePiece(0, 0);
	ASSERT_EQ(myPiece, O);
}

TEST(TicTacToeBoardTest, placePieceTestOutBoundsX)
{
	TicTacToeBoard game;
	Piece myPiece = game.placePiece(10, 10);
	ASSERT_EQ(myPiece, Invalid);
}

TEST(TicTacToeBoardTest, placePieceTestValidO)
{
	TicTacToeBoard game;
	game.toggleTurn();
	Piece myPiece = game.placePiece(0, 0);
	ASSERT_EQ(myPiece, O);
}

TEST(TicTacToeBoardTest, placePieceTestOutBoundsO)
{
	TicTacToeBoard game;
	game.toggleTurn();
	Piece myPiece = game.placePiece(10, 10);
	ASSERT_EQ(myPiece, Invalid);
}