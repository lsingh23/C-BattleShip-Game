// Submitted by :
// LAKHVEER SINGH (0380837)  and  KADMIEL KETCHION (0376579)
#include "Game.h"

//main() function creates a game object and calls its member functions 
//selectPlayers() , play() and announceWinner() 
int main() {
	Game game;
	game.selectPlayers();
	game.play();
	game.announceWinner();
}