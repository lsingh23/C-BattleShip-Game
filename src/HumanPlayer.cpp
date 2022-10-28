#include "HumanPlayer.h"
#include <iostream>


HumanPlayer::HumanPlayer(const std::string& str) : Player(str)
{
}

Move HumanPlayer::makeMove(const Board& board, int player)
{
	std::cout << "Enter a positon where you want to attack : " << std::endl;
	char c; int a;
	std::cin >> c >> a;
	Move move = { c,a };
	int index = (move.c - 65) * move.a + 9;
	if (!board.isLegal(move, player)) {
		while (!board.isLegal(move, player)) {
			std::cout << "Enter a positon where you want to attack : " << std::endl;
			std::cin >> c >> a;
			move = { c,a };
			index = (move.c - 65) * move.a + 9;
		}
	}
	if (board.isLegal(move, player)) {
		if (player == 1) {
			if (board.Pboard2[index] == PlayerPiece::AIRCRAFT || board.Pboard2[index] == PlayerPiece::BATTLESHIP
				|| board.Pboard2[index] == PlayerPiece::CRUISER || board.Pboard2[index] == PlayerPiece::PATROL
				|| board.Pboard2[index] == PlayerPiece::SUBMARINE) {
				board.Eboard2[index] = EnemyPiece::HIT;
			}
			else {
				board.Eboard2[index] = EnemyPiece::MISS;
			}
		}
	}
	return move;
}
