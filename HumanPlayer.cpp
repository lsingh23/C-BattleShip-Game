// Submitted by :
// LAKHVEER SINGH (0380837)  and  KADMIEL KETCHION (0376579)
#include "HumanPlayer.h"
#include <iostream>


//makeMove function prompts the user for a location to attack and return that move as a struct type
Move HumanPlayer::makeMove(const Board& board, int player)
{
	std::cout << "Enter a positon where you want to attack : " << std::endl;
	//row location as char
	char c;
	//column location as an int
	int a;
	// read the input
	std::cin >> c >> a;
	//create a move with specified location
	Move move = { c,a };
	// if move is not legal
	if (!board.isLegal(move, player)) {
		//loop until the user enters a valid move
		while (!board.isLegal(move, player)) {
			std::cout << "Enter a positon where you want to attack : " << std::endl;
			std::cin >> c >> a;
			move = { c,a };
		}
	}
	//return the move
	return move;
}
