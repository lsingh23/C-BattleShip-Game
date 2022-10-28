// Submitted by :
// LAKHVEER SINGH (0380837)  and  KADMIEL KETCHION (0376579)
#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "Player.h"
#include "Board.h"

//HumanPlayer is derived class from Player class ,which makes the attack on specified position  by the human user
class HumanPlayer :public Player {
public:
	//constructor that simply use an intializer list to give the player a name
	HumanPlayer(const std::string& str) :Player(str) {

	}
	//make move function prompts the user for a location to attack and make the move 
	Move makeMove(const Board& board, int player) override;
};

#endif 
