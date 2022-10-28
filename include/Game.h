#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"

class Game {
public:
	Game();
	~Game();
	void selectPlayers();
	Player* nextPlayer() const;
	void play();
	void announceWinner();
	bool isRunning();
private:
	Player* p1;
	Player* p2;
	Board  board;
};

#endif
