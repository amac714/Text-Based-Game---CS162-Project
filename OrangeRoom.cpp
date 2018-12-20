/**********************************************************
 * Program Name: Final Project OrangeRoom.cpp
 * Author: Alan Macabuhay
 * Date: 3/15/17
 * Description: Implementation for OrangeRoom class. User must
 *  defeat all trainers in room before challenging the master
 ***********************************************************/

#include "OrangeRoom.hpp"

//constructor
OrangeRoom::OrangeRoom(Player *user) : Room(user)
{
	master = new OrangeMaster;
	enemy1 = new OrangeTrainer;
	enemy2 = new OrangeTrainer;

	space[1][10] = master;
	space[9][15] = enemy1;
	space[2][16] = enemy2;

	//creates boundaries
	createBound();
}

//destructor
OrangeRoom::~OrangeRoom()
{
	//if(space[1][10] != NULL)
		delete master;
	
	//if(space[2][9] != NULL)
		delete enemy1;

	//if(space[2][11] != NULL)
		delete enemy2;
}

/**********************************
 * setTrainerRight()
 * sets user's starting location
 **********************************/
void OrangeRoom::setTrainerRight()
{
	user->setRow(9);
	user->setCol(1);
	space[9][1] = user;
}

/*********************************
 * changeRoomLeft()
 * check for user to change rooms
 ********************************/
bool OrangeRoom::changeRoomLeft()
{
	bool main = false;
	
	if(space[9][1] != NULL && space[9][1]->getTrainer() == 'A')
	{
		main = true;
		space[9][1] = NULL;
	}

	return main;
	
}

/******************************
 * createBound()
 * creates a boundary
 ******************************/
void OrangeRoom::createBound()
{
	for(int i = 2; i < 15; i++)
	{
		space[8][i] = &door;
		space[10][i] = &door;
	}

	for(int u = 10; u > 0; u--)
		space[u][17] = &door;		

	
	for(int k = 8; k > 2; k--)
		space[k][15] = &door;
	

	for(int c = 15; c < 18; c++)
		space[10][c] = &door;

	for(int a = 9; a < 15; a++)
		space[3][a] = &door; 

	for(int b = 12; b < 17; b++)
		space[1][b] = &door;	

	//entrance and exit door
	space[8][1] = &door;
	space[8][0] = &door;
	space[10][0] = &door;
	space[10][1] = &door;
	space[9][0] = &door;

	//location of master
	space[0][9] = &door;
	space[1][9] = &door;
	space[2][9] = &door;
	space[0][10] = &door;
	space[0][11] = &door;
	space[1][11] = &door;


}

/******************************************
 * displayMsg()
 * displays prompt for room
 ******************************************/
void OrangeRoom::displayMsg() const
{
	cout << "Defeat the Orange trainers and challenge the Orange Master!" << endl;
}
