// Submitted by :
// LAKHVEER SINGH (0380837)  and  KADMIEL KETCHION (0376579)
#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H
#include "ComputerPlayer.h"

//This class inherits from ComputerPlayer class
class RandomPlayer :public ComputerPlayer {
public:
	//constructor that simply give the player a name
	RandomPlayer();
	//makeMove uses a mersenne twister to generate a random location to make a move 
	Move makeMove(const Board&, int player);
};

#endif
