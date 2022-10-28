// Submitted by :
// LAKHVEER SINGH (0380837)  and  KADMIEL KETCHION (0376579)
#include "Game.h"
#include <iostream>

// default constructor initializes an empty board and sets the player pointers to nullptr
Game::Game()
{
	board = Board();
	p1 = nullptr;
	p2 = nullptr;
}

// destructor deallocates any dynamically allocated objects
Game::~Game()
{
	delete p1;
	delete p2;
}

//selectPlayers prompts the user for each of the two players for the type  of the player
//and then creates the objects for the players dynamically
void Game::selectPlayers()
{
	std::cout << "Selecting Players: \n" << std::endl;
	std::cout << "Enter the type of player1:([h/n].i.e.human or computer)";
	//player 1's type
	std::string p1type;
	std::cin >> p1type;
	//if player 1 is HumanPlayer
	if (p1type == "h" || p1type == "human") {
		std::cout << "Enter a name for player 1:";
		//prompt for the name
		std::string p1name;
		std::cin >> p1name;
		//create a new HumanPlayer with the name specified
		p1 = new HumanPlayer(p1name);
	}
	else {
		//create a new RandomPlayer
		p1 = new RandomPlayer();
		//print the name of the RandomPlayer
		std::cout << p1->getName() << std::endl;
	}
	
	std::cout << "Enter the type of player2:([h/n].i.e.human or computer)";
	//player 2's type
	std::string p2type;
	std::cin >> p2type;
	//if player 2 is HumanPlayer
	if (p2type == "h" || p2type=="human") {
		//prompt for the name
		std::cout << "Enter a name for player 1:";
		std::string p2name;
		std::cin >> p2name;
		//create  a new HumanPlayer with tha name specified
		p2 = new HumanPlayer(p2name);
	}
	else {
		//create a RandomPlayer
		p2 = new RandomPlayer();
		std::cout << p2->getName() << std::endl;
	}
	 
}

// nextPlayer  returns the pointer to the player whose move it is. 
Player* Game::nextPlayer() const
{
	//if moved (counter variable in board's class ) is divisible by 2 , then the next player will be player 1
	//else the nextPlayer will be player 2
	if (board.moved % 2 == 0) {
		return p1;
	}
	return p2;
}

//While isRunning returns true, the function displays the current player’s boards 
// and invokes the makeMove member function of the player whose move it is.
// The function then passes the result of the player’s makeMove function to the Board’s makeMove
void Game::play()
{
	//while isRunning is true
	while (this->isRunning()) {

		//make a pointer to the next player 
		Player *current =this->nextPlayer();
		
		//if moved (counter variable in board's class ) is divisible by 2 , then the next player will be player 1
	    if (board.moved % 2 == 0) {
			//clear the console output so that one player can't see the other player's board
			system("CLS");
			std::cout << "\n\n\n         "<< p1->getName() <<" attacking " << p2->getName()<< "\n\n"<< std::endl;
			//display EnemyPiece of player 2
			displayE2();
			//invoke the current player's makeMove and store it in move variable
			Move move = current->makeMove(board, 1);
			//pass the move to board's makeMove
			board.makeMove(move,1);
			//display the boards
			board.display(1);
			//convert the move to integer index
			int index = move.a + (9 * (move.c - 65)) + (move.c - 66);
			//if the player 2 has got a hit display a message with the number of hits
			if (board.Eboard2[index] == EnemyPiece::HIT) {
				std::cout << "\n\n"<< p2->getName() <<" has got " << board.hits2 << " hits. \n\n" << std::endl;
			}
			else {
				std::cout << "\n\nSo close! better luck next time. \n\n" << std::endl;
			}
			system("pause");//display the output to the player before prompting the next player for the move
		}
		//nextPlayer is player 2
		else {
			//clear the console output so that one player can't see the other player's board
			system("CLS");
			std::cout << "\n\n\n          " << p2->getName() << " attacking " << p1->getName() << "\n\n" << std::endl;
			//display EnemyPiece of player 1
			displayE1();
			//invoke the current player's makeMove and store it in move variable
			Move move = current->makeMove(board, 2);
			//pass the move to the board's makeMove
			board.makeMove(move,2);
			//display the boards
			board.display(2);
			//convert the move to integer index
			int index = move.a + (9 * (move.c - 65)) + (move.c - 66);
			//if the player 1 has got a hit display a message with the number of hits
			if (board.Eboard1[index] == EnemyPiece::HIT) {
				std::cout << "\n\n"<< p1->getName()<<" has got " << board.hits1 << " hits \n\n" << std::endl;
			}
			else {
				std::cout << "\n\nOh! that was a miss\n\n" << std::endl;
			}
			system("pause");//display the output to the player before prompting the next player for the move
		}
	}
}

// Announces the end of the game and the name of the winner
void Game::announceWinner()
{
	std::cout << "\n                   Game Over  " << std::endl;
	if (board.moved % 2 == 0) {
		std::cout << p2->getName() << " has won the game .  Congratulations !!!" << std::endl;
	}
	else {
		std::cout << p1->getName() << " has won the game .  Congratulations !!!" << std::endl;
	}
}

// returns true if neither player has yet 
bool Game::isRunning()
{
	//if all the ships the sunk either for player 1 or for player 2
	if (board.hits1 == 16 || board.hits2 == 16) {
		return false;
	}
	return true;
}


//display player 1's EnemyPiece
void Game::displayE1()
{
	std::cout << "\n          EnemyPiece Player 1              \n";
	char C = 'A';
	std::cout << "   1   2   3   4   5   6   7   8   9   10 " << std::endl;
	std::cout << C << ": ";
	for (int i = 1; i <= 100; ++i) {
		std::cout << (char)board.Eboard1[i - 1] << " | ";
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

//display Player 2's EnemyPiece
void Game::displayE2()
{
	std::cout << "\n          EnemyPiece Player 2              \n";
	char C = 'A';
	std::cout << "   1   2   3   4   5   6   7   8   9   10 " << std::endl;
	std::cout << C << ": ";
	for (int i = 1; i <= 100; ++i) {
		std::cout << (char)board.Eboard2[i - 1] << " | ";
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

