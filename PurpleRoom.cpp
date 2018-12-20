/**********************************************************
 * Program Name: Final Project PurpleRoom.cpp
 * Author: Alan Macabuhay
 * Date: 3/16/17
 * Description: Implementation for PurpleRoom class. User must
 *  defeat all trainers in room before challenging the master
 ***********************************************************/

#include "PurpleRoom.hpp"


/*********************************
 * PurpleRoom()
 * constructor
 *********************************/
PurpleRoom::PurpleRoom(Player *user) : Room(user)
{
	master = new PurpleMaster;
	enemy1 = new PurpleTrainer;
	enemy2 = new PurpleTrainer;
	enemy3 = new PurpleTrainer;

	space[1][10] = master;
	space[11][1] = enemy1;
	space[9][19] = enemy2;
	space[5][10] = enemy3;

	//create boundaries
	createBound();

	space[0][9] = &door;
	space[0][10] = &door;
	space[0][11] = &door;
	space[0][8] = &door;
	space[0][12] = &door;
	space[1][12] = &door;
	space[1][8] = &door;

	//entrance
	space[19][10] = &door;
	space[19][9] = &door;
	space[18][9] = &door;
	space[18][11] = &door;
	space[19][11] = &door;

}

/*****************************************
 * ~PurpleRoom()
 * destructor
 *****************************************/
PurpleRoom::~PurpleRoom()
{
		delete master;
		delete enemy1;
		delete enemy2;
		delete enemy3;
}

/***************************************
 * setTrainerUp()
 * sets user's starting location in the room
 **************************************/
void PurpleRoom::setTrainerUp()
{
	user->setRow(18);
	user->setCol(10);
	space[18][10] = user;
}

/************************************
 * changeRoomDown()
 * change room back to Main Hall
 ************************************/
bool PurpleRoom::changeRoomDown()
{
	bool main = false;

	if(space[18][10] != NULL && space[18][10]->getTrainer() == 'A')
	{
		main = true;
		space[18][10] = NULL;
	}

	return main;
}

/************************************
 * createBound()
 * creates boundaries around room
 ***********************************/
void PurpleRoom::createBound()
{
	for(int i = 2; i < 21; i++)
		space[16][i] = &door;

	for(int a = 15; a > 10; a--)
	{
		space[a][2] = &door;
		space[a][0] = &door;
	}
	for(int b = 3; b < 21; b++)
		space[11][b] = &door;

	for(int c = 0; c < 19; c++)
		space[9][c] = &door;

	for(int d = 0; d < 10; d++)
		space[5][d] = &door;

	for(int e = 11; e < 21; e++)
		space[5][e] = &door;

	for(int f = 8; f > 5; f--)
	{
		space[f][20] = &door;
		space[f][0] = &door;
	}

	//misc	
	space[10][20] = &door;
	space[9][20] = &door;
	space[16][0] = &door;
	space[10][0] = &door;
 
}

/****************************************
 * displayMsg()
 * dsplays prompt for room
 ***************************************/
void PurpleRoom::displayMsg() const
{
	cout << "\nTraverse the room and defeat the Purple trainers." << endl;
	cout << "Challenge the Purple master for the Purple belt." << endl;
}
