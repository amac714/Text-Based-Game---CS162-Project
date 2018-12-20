/**********************************************************
 * Program Name: Final Project MainHall.hpp
 * Author: Alan Macabuhay
 * Date: 3/14/17
 * Description: Header file for MainHall class. MainHall 
 *  connects all the different rooms together.
 ***********************************************************/

#ifndef MAINHALL_HPP
#define MAINHALL_HPP

#include "Room.hpp"
#include "YellowTrainer.hpp"
#include "OrangeTrainer.hpp"
#include "PurpleTrainer.hpp"
#include "BlackMaster.hpp"
#include "BlackTrainer.hpp"
#include "Game.hpp"
#include "Player.hpp"

class MainHall : public Room
{
private:
	Game *enemy1;
	Game *enemy2;
	Game *enemy3;
	Game *enemy4;

public:
	MainHall(Player *);
	~MainHall();
	virtual void setTrainerDown();
	virtual void setTrainerUp();
	virtual void setTrainerLeft();
	virtual void setTrainerRight();
	virtual bool changeRoomLeft();
	virtual bool changeRoomRight();
	virtual bool changeRoomUp();
	virtual bool changeRoomDown();
	virtual void createBound();
};
#endif
