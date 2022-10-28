// Submitted by :
// LAKHVEER SINGH (0380837)  and  KADMIEL KETCHION (0376579)
#include "Board.h"
#include <iostream>
#include<exception>
#include <stdlib.h>


//constructor for board class that initializes the board by calling the reset function
//and then calls set function for placing the ships on the board
Board::Board()
{
	reset();
	set();
}

//reset function erases all ships and shots from the boards
void Board::reset() noexcept
{
	for (int i = 0; i < 100; ++i) {
		Pboard1[i] = PlayerPiece::EMPTY;
		Pboard2[i] = PlayerPiece::EMPTY;
		Eboard1[i] = EnemyPiece::EMPTY;
		Eboard2[i] = EnemyPiece::EMPTY;
	}

}

//display function displays the player's Playerpiece and the enemy's EnemyPiece 
void Board::display(int player) const noexcept
{
	//if player making the move is 1
	if (player == 1) {
		system("Color 64");//console color
		//char for  numbering rows
		char c = 'A';
		//display PlayerPiece for Player 1
		std::cout << "\n          PlayerPiece Player 1              \n\n";
		std::cout << "   1   2   3   4   5   6   7   8   9   10 " << std::endl;
		std::cout << c << ": ";
		for (int i = 1; i <= 100; ++i) {
			std::cout << (char)Pboard1[i - 1] << " | ";
			if (i % 10 == 0) 
			{
				std::cout << std::endl;
				c++;
				if (c == 'K') 
				{
					break;
				}
				std::cout << static_cast<char>(c) << ": ";
			}
		}
		//display EnemyPiece of Player 2 
		std::cout << "\n          EnemyPiece Player 2              \n\n";
		//char for numbering rows
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
	//Player making the move is second player
	else if (player == 2) 
	{
		system("Color 72");//console color
		//char for numbering rows
		char c = 'A';
		//display PlayerPiece for Player 1 
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
		//display EnemyPiece for Player 2
		std::cout << "\n          EnemyPiece Player 1              \n\n";
		char ch = 'A';
		std::cout << "   1   2   3   4   5   6   7   8   9   10 " << std::endl;
		std::cout << ch << ": ";
		for (int i = 1; i <= 100; ++i) {
			std::cout << (char)Eboard1[i - 1] << " | ";
			if (i % 10 == 0) {
				std::cout << std::endl;
				ch++;
				if (ch == 'K') {
					break;
				}
				std::cout << static_cast<char>(ch) << ": ";
			}
		}
	}
}

//make a move as specified and update the board
EnemyPiece Board::makeMove(const Move& move, int player)
{
	//increment the counter variable to keep track of moves 
	moved++;
	//convert the struct  move into integer index
	//e.g. C 4 = 4 + ( 9 * 2 ) + ( 1 )
	int index = move.a + (9 * (move.c - 65)) + (move.c - 66);
	//if player making the move is Player 1
	if (player == 1) {
		//if PlayerPiece has a ship at the index specified mark a hit on EnemyPiece
		if (Pboard2[index] == PlayerPiece::AIRCRAFT || Pboard2[index] == PlayerPiece::BATTLESHIP
			|| Pboard2[index] == PlayerPiece::CRUISER || Pboard2[index] == PlayerPiece::PATROL
			|| Pboard2[index] == PlayerPiece::SUBMARINE) {
			Eboard2[index] = EnemyPiece::HIT;
			hits2++;//increment the count of hits
		}
		else {
			Eboard2[index] = EnemyPiece::MISS;//mark a miss on EnemyPiece 
		}
		return Eboard2[index];
	}
	//if player making the move is Player 2
	else if (player == 2) 
	{
		//if PlayerPiece has a ship at the index specified mark a hit on EnemyPiece
		if (Pboard1[index] == PlayerPiece::AIRCRAFT || Pboard1[index] == PlayerPiece::BATTLESHIP
			|| Pboard1[index] == PlayerPiece::CRUISER || Pboard1[index] == PlayerPiece::PATROL
			|| Pboard1[index] == PlayerPiece::SUBMARINE) {
			Eboard1[index] = EnemyPiece::HIT;
			hits1++;//increment the count of hits 
		}
		else {
			Eboard1[index] = EnemyPiece::MISS;//mark a miss on EnemyPiece
		}
		return Eboard1[index];
	}
}

//check if the specified move is legal
bool Board::isLegal(const Move& move, int player) const noexcept
{
	//convert the struct  move into integer index
	int index = move.a + (9 * (move.c - 65)) + (move.c - 66);
	//check for the legal index
	if (move.c - 65 < 0 || move.c - 65 > 9 || move.a < 1 || move.a >10) {
		exit(1);
	}
	if (player == 1) {
		//if EnemyPiece is already marked as a hit or miss 
		if (Eboard2[index]==EnemyPiece::HIT || Eboard2[index] == EnemyPiece::MISS) {
			return false;
		}
		return true;
	}
	else if (player == 2) {
		//if EnemyPiece is already marked as a hit or miss
		if (Eboard1[index]==EnemyPiece::HIT || Eboard1[index]==EnemyPiece::MISS) {
			return false;
		}
		return true;
	}
}

//place the ships on the board
void Board::set() {

	// setting the ships on the board
	//number of blocks for each ship used
	//aircraft = 5 ,battleship =4,cruiser =3,submarine =2,patrol =2
	for (int i = 43; i < 84; i += 10)
		Pboard2[i] = PlayerPiece::AIRCRAFT;
	for (int i = 16; i < 20; ++i)
		Pboard2[i] = PlayerPiece::BATTLESHIP;
	for (int i = 11; i < 14; ++i)
		Pboard2[i] = PlayerPiece::CRUISER;
	for (int i = 25; i < 28; ++i)
		Pboard2[i] = PlayerPiece::SUBMARINE;
	for (int i = 97; i < 99; ++i)
		Pboard2[i] = PlayerPiece::PATROL;
	for (int i = 40; i < 81; i += 10)
		Pboard1[i] = PlayerPiece::AIRCRAFT;
	for (int i = 21; i < 25; ++i)
		Pboard1[i] = PlayerPiece::BATTLESHIP;
	for (int i = 55; i < 76; i += 10)
		Pboard1[i] = PlayerPiece::CRUISER;
	for (int i = 27; i < 29; ++i)
		Pboard1[i] = PlayerPiece::SUBMARINE;
	for (int i = 38; i < 40; ++i)
		Pboard1[i] = PlayerPiece::PATROL;

}

