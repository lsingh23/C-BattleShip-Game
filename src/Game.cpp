#include "Game.h"
#include <iostream>

Game::Game()
{
	board=Board();
	p1 = nullptr;
	p2 = nullptr;
}

Game::~Game()
{
	delete p1;
	delete p2;
}

void Game::selectPlayers()
{
	std::cout << "Selecting Players:" << std::endl;
	std::cout << "Enter the type of player1:([h/n].i.e.human or computer)";
	std::string p1type;
	std::cin >> p1type;
	if (p1type == "h") {
		std::cout << "Enter a name for player 1:";
		std::string p1name;
		std::cin >> p1name;
		p1 = new HumanPlayer(p1name);
	}

	std::cout << "Enter the type of player2:([h/n].i.e.human or computer)";
	std::string p2type;
	std::cin >> p2type;
	if (p2type == "h") {
		std::cout << "Enter a name for player 2:";
		std::string p2name;
		std::cin >> p2name;
		p2 = new HumanPlayer(p2name);
	}
}

Player* Game::nextPlayer() const
{
	return nullptr;
}

void Game::play()
{
}

void Game::announceWinner()
{
}

bool Game::isRunning()
{
	return false;
}
