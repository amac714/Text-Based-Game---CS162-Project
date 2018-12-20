/**********************************************************
 * Program Name: Final Project ChampRoom.cpp
 * Author: Alan Macabuhay
 * Date: 3/16/17
 * Description: Implementation for ChampRoom class. 
 ***********************************************************/

#include "ChampRoom.hpp"

//constructor
ChampRoom::ChampRoom(Player *user) : Room(user)
{
	master = new Champion;

	space[1][10] = master;

	createBound();
}

//destructor
ChampRoom::~ChampRoom()
{
	delete master;
}

/************************************
 * setTrainerDown()
 * sets trainer at starting location
 ***********************************/
void ChampRoom::setTrainerDown()
{
	user->setRow(18);
	user->setCol(10);
	space[18][10] = user;
}

/**************************************
 * createBound()
 * creates a boundary
 *************************************/
void ChampRoom::createBound()
{
	//starting entrance
	space[19][10] = &door;
	space[19][9] = &door;
	space[18][9] = &door;
	space[18][11] = &door;
	space[19][11] = &door;

	//champions place
	space[0][7] = &door;
	space[0][13] = &door;
	space[0][6] = &door;
	space[0][14] = &door;
	space[0][9] = &door;
	space[0][10] = &door;
	space[0][11] = &door;
	space[0][8] = &door;
	space[0][12] = &door;
	space[1][14] = &door;
	space[1][6] = &door;
	space[2][6] = &door;
	space[2][14] = &door;
	space[2][7] = &door;
	space[2][8] = &door;
	space[2][9] = &door;
	space[2][13] = &door;
	space[2][12] = &door;
	space[2][11] = &door;

	for(int i = 17; i > 2; i--)
	{
		space[i][9] = &door;
		space[i][11] = &door;
	}

}

/***********************************
 * displayMsg()
 * displays prompt for the room
 ***********************************/
void ChampRoom::displayMsg()
{
	//50 is starting stamina of the Champion
	cout << "You have come far as a Karate trainer. Now come and test your skill against the Champion!!" << endl;
}
