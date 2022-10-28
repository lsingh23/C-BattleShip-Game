// Submitted by :
// LAKHVEER SINGH (0380837)  and  KADMIEL KETCHION (0376579)
#ifndef BOARD_H
#define BOARD_H

//enum class EnemyPiece that represents the possible contents of a EnemyPiece board 
enum class EnemyPiece { HIT = 'x', MISS = 'o', EMPTY = ' ' };
//enum class PlayerPiece that represents the possible contents of a PlayerPiece board 
enum class PlayerPiece { AIRCRAFT = 'a', BATTLESHIP = 'b', CRUISER = 'c', SUBMARINE = 's', PATROL = 'p', EMPTY = ' ' };

//A struct type Move that represents a move by a character ('c') and an integer (a)
typedef struct Move {
	char c;
	int a;
};

//Board class represents the state of the board and has the appropriate boards for the EnemyPieces and PlayerPieces
class Board {
public:
	//couter variables to keep track of the hits a player has got (hits1 for player 1 And hits2 for player 2)
	int hits1 = 0;
	int hits2 = 0;
	//couter variable to keep track of the player's moves so that we can use it for determining the next player
	int moved = 0;
	//constructor for board class that initializes the board by calling the reset function
	//and then calls set function for placing the ships on the board
	Board();
	//reset function erases all ships and shots from the boards
	void reset() noexcept;
	//display function displays the player's Playerpiece and the enemy's EnemyPiece 
	void display(int player)const noexcept;
	//make a move as specified and update the board
	EnemyPiece makeMove(const Move& move, int player);
	//check if the specified move is legal
	bool isLegal(const Move& move, int player) const noexcept;
	//place the ships on the board
	void set();

	//Player 1 and Player 2 's PlayerPieces each of size 100
	PlayerPiece Pboard1[100];
	PlayerPiece Pboard2[100];
	//Player 1 and Player 2 's EnemyPieces each of size 100
	mutable EnemyPiece Eboard1[100];
	mutable EnemyPiece Eboard2[100];
};

#endif