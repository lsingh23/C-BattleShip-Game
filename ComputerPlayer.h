// Submitted by :
// LAKHVEER SINGH (0380837)  and  KADMIEL KETCHION (0376579)
#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"
//ComputerPlayer class is an abstract base class derived from the player class 
//this class basically ensures that different computer Player gets a different name assigned
class ComputerPlayer : public Player {
public:
	//constructor that simply use an intializer list to give the player a name
	ComputerPlayer();
	//name generator for computer player
	std::string generator();
protected:
	//name of computer player
	static char cName ;
};


#endif 

