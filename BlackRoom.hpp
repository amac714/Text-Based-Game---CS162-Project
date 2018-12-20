/**************************************************
 * Program name: Final Project BlackRoom.hpp
 * Author: Alan Macabuhay
 * Date: 3/16/17
 * Description: Header file for BlackRoom class
 ***************************************************/

#ifndef BLACKROOM_HPP
#define BLACKROOM_HPP

#include "Room.hpp"
#include "BlackMaster.hpp"
#include "BlackTrainer.hpp"
#include "Game.hpp"
#include "Player.hpp"

class BlackRoom : public Room
{
private:
	Game *master;
	Game *enemy1;
	Game *enemy2;
	Game *enemy3;
	Game *enemy4;

public:
	BlackRoom(Player*);
	~BlackRoom();
	virtual void setTrainerDown();
	virtual bool changeRoomUp();
	virtual void displayMsg() const;
	virtual bool changeRoomDown();
	void createBound();
};
#endif


