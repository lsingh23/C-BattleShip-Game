#include "Board.h"
#include <iostream>

Board::Board()
{
	reset();
}

void Board::reset() noexcept
{
	for (int i = 0; i < 100; ++i) {
		Pboard1[i] = PlayerPiece::EMPTY;
		Pboard2[i] = PlayerPiece::EMPTY;
		Eboard1[i] = EnemyPiece::EMPTY;
		Eboard2[i] = EnemyPiece::EMPTY;
	}

}

void Board::display(int player) const noexcept
{
	if (player == 1) {
		char c = 'A';
		std::cout << "\n          PlayerPiece Player 1              \n\n";
		std::cout << "   1   2   3   4   5   6   7   8   9   10 " << std::endl;
		std::cout << c << ": ";
		for (int i = 1; i <= 100; ++i) {
			std::cout << (char)Pboard1[i - 1] << " | ";
			if (i % 10 == 0) {
				std::cout << std::endl;
				c++;
				if (c == 'K') {
					break;
				}
				std::cout << static_cast<char>(c) << ": ";
			}
		}

		std::cout << "\n          EnemyPiece Player 2              \n\n";
		char C = 'A';
		std::cout << "   1   2   3   4   5   6   7   8   9   10 " << std::endl;
		std::cout << C << ": ";
		for (int i = 1; i <= 100; ++i) {
			std::cout << (char)Eboard2[i - 1] << " | ";
			if (i % 10 == 0) {
				std::cout << std::endl;
				C++;
				if (C == 'K') {
					break;
				}
				std::cout << static_cast<char>(C) << ": ";
			}
		}
	}
	else if (player == 2) {
		char c = 'A';
		std::cout << "\n          PlayerPiece Player 2              \n\n";
		std::cout << "   1   2   3   4   5   6   7   8   9   10 " << std::endl;
		std::cout << c << ": ";
		for (int i = 1; i <= 100; ++i) {
			std::cout << (char)Pboard2[i - 1] << " | ";
			if (i % 10 == 0) {
				std::cout << std::endl;
				c++;
				if (c == 'K') {
					break;
				}
				std::cout << static_cast<char>(c) << ": ";
			}
		}

		std::cout << "\n          EnemyPiece Player 1              \n\n";
		char C = 'A';
		std::cout << "   1   2   3   4   5   6   7   8   9   10 " << std::endl;
		std::cout << c << ": ";
		for (int i = 1; i <= 100; ++i) {
			std::cout << (char)Eboard1[i - 1] << " | ";
			if (i % 10 == 0) {
				std::cout << std::endl;
				C++;
				if (C == 'K') {
					break;
				}
				std::cout << static_cast<char>(C) << ": ";
			}
		}
	}
}

EnemyPiece Board::makeMove(const Move& move, int player)
{
	int index = (move.c - 65) * move.a + 9;
	std::cout << index << std::endl;
	if (player == 1) {
		if (Pboard2[index] == PlayerPiece::AIRCRAFT || Pboard2[index] == PlayerPiece::BATTLESHIP
			|| Pboard2[index] == PlayerPiece::CRUISER || Pboard2[index] == PlayerPiece::PATROL
			|| Pboard2[index] == PlayerPiece::SUBMARINE) {
			Eboard2[index] = EnemyPiece::HIT;
		}
		else {
			Eboard2[index] = EnemyPiece::MISS;
		}
		return Eboard2[index];
	}
	else if (player == 2) {
		if (Pboard1[index] == PlayerPiece::AIRCRAFT || Pboard1[index] == PlayerPiece::BATTLESHIP
			|| Pboard1[index] == PlayerPiece::CRUISER || Pboard1[index] == PlayerPiece::PATROL
			|| Pboard1[index] == PlayerPiece::SUBMARINE) {
			Eboard1[index] = EnemyPiece::HIT;
		}
		else {
			Eboard1[index] = EnemyPiece::MISS;
		}
		return Eboard1[index];
	}
}

bool Board::isLegal(const Move& move, int player) const noexcept
{
	int index = (move.c - 65) * move.a + 9;
	if (player == 1) {
		if (Pboard2[index] == PlayerPiece::EMPTY) {
			return true;
		}
		return false;
	}
	else if (player == 2) {
		if (Pboard1[index] == PlayerPiece::EMPTY) {
			return true;
		}
		return false;
	}
}


