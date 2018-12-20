/**************************************************
 * Program name: Final Project OrangeRoom.hpp
 * Author: Alan Macabuhay
 * Date: 3/15/17
 * Description: Header file for OrangeRoom class
 ***************************************************/

#ifndef ORANGEROOM_HPP
#define ORANGEROOM_HPP

#include "Room.hpp"
#include "OrangeMaster.hpp"
#include "OrangeTrainer.hpp"
#include "Game.hpp"
#include "Player.hpp"

class OrangeRoom : public Room
{
private:
	Game *master;
	Game *enemy1;
	Game *enemy2;

public:
	OrangeRoom(Player*);
	~OrangeRoom();
	virtual void setTrainerRight();
	virtual bool changeRoomLeft();
	void createBound();
	virtual void displayMsg() const;
};
#endif


