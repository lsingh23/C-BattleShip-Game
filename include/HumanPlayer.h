#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "Player.h"
#include "Board.h"

class HumanPlayer :public Player {
public:
	HumanPlayer(const std::string& str);
	Move makeMove(const Board& board, int player) override;
};

#endif
