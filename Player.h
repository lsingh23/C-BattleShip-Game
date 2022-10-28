// Submitted by :
// LAKHVEER SINGH (0380837)  and  KADMIEL KETCHION (0376579)
#ifndef PLAYER_H
#define PLAYER_H
#include "Board.h"
#include <string>

//abstract class that has common functionality of human and computer players
class Player {
public:
	//constructor that sets the name of the player
	Player(const std::string& str) {
		name = str;
	}
	//pure virtual function makeMove that is  implemented for human and computer players 
	virtual Move makeMove(const Board&, int player)=0;
	//name accessor
	std::string getName();
protected:
	//name of the player
	std::string name;
};

#endif