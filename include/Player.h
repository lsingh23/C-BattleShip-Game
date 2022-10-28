#ifndef PLAYER_H
#define PLAYER_H
#include "Board.h"
#include <string>

class Player {
public:
	Player(const std::string& str) {
		name = str;
	};
	virtual Move makeMove(const Board&, int player);
protected:
	std::string name;
};

#endif
