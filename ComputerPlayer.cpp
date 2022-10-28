// Submitted by :
// LAKHVEER SINGH (0380837)  and  KADMIEL KETCHION (0376579)
#include "ComputerPlayer.h"

//intialize the name 
char ComputerPlayer::cName = 'A';

//constructor that simply use an intializer list to give the player a name
ComputerPlayer::ComputerPlayer() :Player("Computer "+generator()){ 
	cName = cName++;         //increment the name each time the constructor is called
	if (cName == 'Z') {      // if name is 'Z' return back to 'A'
		cName = 'A';
	}
}
//generate the name for computer player as a string
std::string ComputerPlayer::generator()
{
	std::string str(1, cName);
	return str;
}

