/**********************************************************
 * Program Name: Final Project MainHall.cpp
 * Author: Alan Macabuhay
 * Date: 3/14/17
 * Description: Implementation for MainHall class. MainHall 
 *  connects all the different rooms together.
 ***********************************************************/

#include "MainHall.hpp"

/******************************************
 * MainHall(Player *user)
 * Constructor. Sets up main hall of game
 *****************************************/
MainHall::MainHall(Player *user) : Room(user)
{
	//starting place of user
	space[18][10] = user;
	this->user->setCol(10);
	this->user->setRow(18);
	space[19][10] = &door;
	space[19][9] = &door;
	space[18][9] = &door;
	space[18][11] = &door;
	space[19][11] = &door;

	//enemies and their location
	enemy1 = new BlackTrainer;
	space[10][10] = enemy1;

	enemy2 = new YellowTrainer;
	space[9][1] = enemy2;

	enemy3 = new PurpleTrainer;
	space[1][10] = enemy3;
	
	enemy4 = new OrangeTrainer;
	space[9][19] = enemy4;

	createBound();

}

/*******************************************
 * ~MainHall
 * desctructor
 *******************************************/
MainHall::~MainHall()
{
//	if(space[11][10] != NULL)
		delete enemy1;

//	if(space[9][1] != NULL)
		delete enemy2;

//	if(space[1][10] != NULL)
		delete enemy3;

//	if(space[9][19] != NULL)
		delete enemy4;
}

/****************************************
 * setTrainerUp()
 * sets user at top of room
 ***************************************/
void MainHall::setTrainerUp()
{
	user->setRow(10);
	user->setCol(10);
	space[10][10] = user;
}

/************************************
 * setTrainerLeft()
 * sets user at right side of room
 ***********************************/
void MainHall::setTrainerLeft()
{
	user->setRow(9);
	user->setCol(19);
	space[9][19] = user;
}

/************************************
 * setTrainerRight()
 * sets user at left side of room
 ***********************************/
void MainHall::setTrainerRight()
{
	user->setRow(9);
	user->setCol(1);
	space[9][1] = user;
}

/************************************
 * setTrainerDown()
 * sets user to correct spot after
 * exiting purple room
 *************************************/
void MainHall::setTrainerDown()
{
	user->setRow(1);
	user->setCol(10);
	space[1][10] = user;
}
/***********************************************
 * changeRoomLeft()
 * checks to see if yellow user has been beaten
 * in order to go into the yellow room
 ************************************************/
bool MainHall::changeRoomLeft()
{
	bool beaten = false;

	
	if((user->checkBag("White Belt") == true) && this->left != NULL) //&& (enemy2->getStamina() < 0))
	{
		if((space[9][1] != NULL) && (space[9][1]->getTrainer() == 'A'))
		{
			space[9][1] = NULL;
			beaten = true;
		}
	}
	
	return beaten;
}

/****************************************************
 *	changeRoomDown
 *	checks to see if black user has been beaten
 ****************************************************/
bool MainHall::changeRoomDown()
{
	bool beaten = false;

	if((this->user->checkBag("Purple Belt") == true) && (this->down != NULL))
	{
		if((space[10][10] != NULL) && (space[10][10]->getTrainer() == 'A'))
		{
			space[10][10] = NULL;
			beaten = true;
		}
	}

	return beaten;

}

/****************************************************
 *	changeRoomRight
 *	checks to see if orange user has been beaten
 ****************************************************/
bool MainHall::changeRoomRight()
{
	bool beaten = false;

	if(this->user->checkBag("Yellow Belt") && this->right != NULL)
	{
		if((space[9][19] != NULL) && (space[9][19]->getTrainer() == 'A'))
		{
			space[9][19] = NULL;
			beaten = true;
		}
	}

	return beaten;

}

/****************************************************
 *	changeRoomUp
 *	checks to see if purple user has been beaten
 ****************************************************/
bool MainHall::changeRoomUp()
{
	bool beaten = false;

	if((this->user->checkBag("Orange Belt")) && (this->up != NULL))
	{
		if((space[1][10] != NULL) && (space[1][10]->getTrainer() == 'A'))
		{
			space[1][10] = NULL;
			beaten = true;
		}
	}

	return beaten;

}

/************************************************
 * createBound()
 * creates boundaries for doors
 ***********************************************/
void MainHall::createBound()
{

	//creates door to yellow room
	space[8][1] = &door;
	space[8][0] = &door;
	space[10][0] = &door;
	space[9][0] = &door;
	space[10][1] = &door;

	//door to black room
	space[10][9] = &door;
	space[9][9] = &door;
	space[9][10] = &door;
	space[9][11] = &door;
	space[10][11] = &door;

	//door to purple room
	space[1][9] = &door;
	space[0][9] = &door;
	space[0][10] = &door;
	space[0][11] = &door;
	space[1][11] = &door;

	//door to orange room
	space[8][19] = &door;
	space[8][20] = &door;
	space[9][20] = &door;
	space[10][19] = &door;
	space[10][20] = &door;
	
}
