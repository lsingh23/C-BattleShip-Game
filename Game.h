// Submitted by :
// LAKHVEER SINGH (0380837)  and  KADMIEL KETCHION (0376579)
#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "Player.h"
#include "ComputerPlayer.h"
#include "RandomPlayer.h"
#include "HumanPlayer.h"

// Game class contains two Pointers to Player objects as member variables, and a Board object 
// and it creates a flow of the game
class Game {
public:
	// default constructor initializes an empty board and sets the player pointers to nullptr
	Game();
	// destructor deallocates any dynamically allocated objects
	~Game();
	//selectPlayers prompts the user for each of the two players for the type  of the player
    //and then creates the objects for the players dynamically
	void selectPlayers();
	// nextPlayer  returns the pointer to the player whose move it is. 
	Player* nextPlayer() const;
	//While isRunning returns true, the function displays the current player’s boards 
	// and invokes the makeMove member function of the player whose move it is.
	// The function then passes the result of the player’s makeMove function to the Board’s makeMove
	void play();
	// Announces the end of the game and the name of the winner
	void announceWinner();
	// returns true if neither player has yet won
	bool isRunning();
	//display player 1's EnemyPiece 
	void displayE1();
	//display player 2's EnemyPiece
	void displayE2();
private:
	//two Pointers to Player objects as member variables, and a Board object 
	Player* p1;
	Player* p2;
	Board board;
};

#endif