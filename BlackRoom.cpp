/**********************************************************
 * Program Name: Final Project BlackRoom.cpp
 * Author: Alan Macabuhay
 * Date: 3/16/17
 * Description: Implementation for BlackRoom class. User must
 *  defeat all trainers in room before challenging the master
 ***********************************************************/

#include "BlackRoom.hpp"


//constructor
BlackRoom::BlackRoom(Player *user) : Room(user)
{
	master = new BlackMaster;
	enemy1 = new BlackTrainer;
	enemy2 = new BlackTrainer;
	enemy3 = new BlackTrainer;
	enemy4 = new BlackTrainer;

	//opponent locations
	space[1][10] = master;
	space[16][10] = enemy1;
	space[14][16] = enemy2;
	space[8][4] = enemy3;
	space[4][10] = enemy4;

	//creates boundaries
	createBound();
}

//destructor
BlackRoom::~BlackRoom()
{
		delete enemy1;
		delete enemy2;
		delete enemy3;
		delete enemy4;
		delete master;
}

/********************************************
 * createBound()
 * creates a boundary for the user to navigate
 ********************************************/
void BlackRoom::createBound()
{
	for(int i = 0; i < 10; i++)
	{
		space[16][i] = &door;
		space[4][i] = &door;
	}

	for(int j = 11; j < 21; j++)
	{
		space[16][j] = &door;
		space[4][j] = &door;
	}

	for(int t = 2; t < 16; t++)
		space[14][t] = &door;

	for(int r = 17; r < 21; r++)
		space[14][r] = &door;

	for(int p = 0; p < 4; p++)
		space[8][p] = &door;

	for(int c = 5; c < 19; c++)
		space[8][c] = &door;

	for(int a = 0; a < 19; a++)
		space[12][a] = &door;

	for(int b = 2; b < 14; b++)
		space[10][b] = &door;

	for(int e = 15; e < 21; e++)
		space[10][e] = &door;
	
	for(int w = 0; w < 19; w++)
		space[6][w] = &door;

	//door to champions room
	space[1][9] = &door;
	space[0][9] = &door;
	space[0][10] = &door;
	space[0][11] = &door;
	space[1][11] = &door;
	space[2][9] = &door;
	space[3][9] = &door;
	space[2][11] = &door;
	space[3][11] = &door;

	//door back to main
	space[18][9] = &door;
	space[19][9] = &door;
	space[19][10] = &door;
	space[18][11] = &door;
	space[19][11] = &door;

	//misc boundaries
	space[14][0] = &door;
	space[13][10] = &cut;
	space[11][6] = &cut;
	space[9][15] = &cut;
	space[6][20] = &door;
	space[8][20] = &door;
	space[9][20] = &door;
	space[7][20] = &door;
	space[5][20] = &door;
	space[11][20] = &door;
	space[12][20] = &door;
	space[13][20] = &door;
	space[15][20] = &door;
	space[15][0] = &door;
	space[13][0] = &door;
	space[11][0] = &door;
	space[10][0] = &door;
	space[5][0] = &door;
	space[7][0] = &door;
	space[9][0] = &door;

}

/*****************************************
 * setTrainerDown()
 * sets user at starting spot in room
 ****************************************/
void BlackRoom::setTrainerDown()
{
	user->setRow(18);
	user->setCol(10);
	space[18][10] = user;
}

/***************************************
 * changeRoomUp()
 * check for user to change rooms
 **************************************/
bool BlackRoom::changeRoomUp()
{
	bool main = false;

	if(space[18][10] != NULL && this->up != NULL && space[18][10]->getTrainer() == 'A')
	{
		space[18][10] = NULL;
		main = true;
	}

	return main;
}

/*****************************************
 * changeRoomDown()
 * changes to champ room
 ****************************************/
bool BlackRoom::changeRoomDown()
{
	bool champ = false;

	if(space[1][10] != NULL && space[1][10]->getTrainer() == 'A')
	{
		space[1][10] = NULL;
		champ = true;
	}

	return champ;
}

/****************************************
 * displayMsg()
 * displays prompt for room
 ***************************************/
void BlackRoom::displayMsg() const
{
	cout << "\nGet through the maze and challenge the Black Master for the Black belt!" << endl;
	cout << "\n\nHint: Interact to look for a shortcut." << endl;

}
