#ifndef BOARD_H
#define BOARD_H

enum class EnemyPiece { HIT = 'x', MISS = 'o', EMPTY = ' ' };
enum class PlayerPiece { AIRCRAFT = 'a', BATTLESHIP = 'b', CRUISER = 'c', SUBMARINE = 's', PATROL = 'p', EMPTY = ' ' };

typedef struct Move {
	char c;
	int a;
};

class Board {
public:
	Board();
	void reset() noexcept;
	void display(int player)const noexcept;
	EnemyPiece makeMove(const Move& move, int player);
	bool isLegal(const Move& move, int player) const noexcept;

public:
	PlayerPiece Pboard1[100];
	PlayerPiece Pboard2[100];
	mutable EnemyPiece Eboard1[100];
	mutable EnemyPiece Eboard2[100];

};

#endif
