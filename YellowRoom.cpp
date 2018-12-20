/**********************************************************
 * Program Name: Final Project YellowRoom.cpp
 * Author: Alan Macabuhay
 * Date: 3/15/17
 * Description: Implementation for YellowRoom class. User must
 *  defeat all trainers in room before challenging the master
 ***********************************************************/

#include "YellowRoom.hpp"
#include <iostream>

using std::cout;
using std::endl;
/************************************
 * YellowRoom(Player *user)
 * constructor to set up YellowRoom
 ************************************/
YellowRoom::YellowRoom(Player *user) : Room(user)
{
	masterEnemy = new YellowMaster;
	enemy1 = new YellowTrainer;

	space[9][1] = masterEnemy;
	space[8][0] = &door;
	space[9][0] = &door;
	space[10][0] = &door;

	space[9][10] = enemy1;

	space[9][20] = &door;
	space[8][19] = &door;
	space[8][20] = &door;
	space[10][20] = &door;
	space[10][19] = &door;
	
	//create boundary
	createBound();

}

/***********************************
 * ~YellowRoom
 * destructor
 ***********************************/
YellowRoom::~YellowRoom()
{
	//if(space[9][1] != NULL)
		delete masterEnemy;

	//if(space[8][2] != NULL)
		delete enemy1;

}

/*************************************************
 * setTrainerLeft()
 * sets user to its position upon entering the room
 *************************************************/
void YellowRoom::setTrainerLeft()
{	//19 or 1
	user->setRow(9);
	user->setCol(19);
	space[9][19] = user;
	//cout << "Hello" << endl;
}

/****************************************************
 * changeRoomRight()
 * changes room back to main hall
 ***************************************************/
bool YellowRoom::changeRoomRight()
{
	bool main = false;

	if(space[9][19] != NULL && space[9][19]->getTrainer() == 'A')
	{
		space[9][19] = NULL;
		main = true;
	}
	
	return main;

}

/*********************************
 * createBound()
 * creates a boundary
 *********************************/
void YellowRoom::createBound()
{
	for(int i = 1; i < 19; i++)
	{
		space[8][i] = &door;
		space[10][i] = &door;
	} 
}

/*******************************
 * displayMsg()
 * displays prompt for room
 ********************************/
void YellowRoom::displayMsg() const
{
	cout << "\nDefeat the Yellow Trainer and challenge the Yellow Master for the Yellow Belt." << endl;
}
