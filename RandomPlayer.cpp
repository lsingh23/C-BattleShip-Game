// Submitted by :
// LAKHVEER SINGH (0380837)  and  KADMIEL KETCHION (0376579)

#include "RandomPlayer.h"
#include <iostream>
#include <chrono>
#include <random>

//constructor that simply give the player a name
RandomPlayer::RandomPlayer() : ComputerPlayer() {}

//makeMove uses a mersenne twister to generate a random location to make a move 
Move RandomPlayer::makeMove(const Board& board, int player)
{
	Move move;
	do {
		//current time seed
		unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		//mersenne twister 
		std::mt19937 generator(seed);
		// row number
		int row = generator() % 10;
		//column number
		int col = (generator() % 10) + 1;
		//convert row number into char
		char c = 'A' + row;
		// make the move
		move = { c,col };
	}//while is not legal
	while (!board.isLegal(move, player));
	
	return move;
}
