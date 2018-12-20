/**************************************************
 * Program name: Final Project PurpleRoom.hpp
 * Author: Alan Macabuhay
 * Date: 3/16/17
 * Description: Header file for PurpleRoom class
 ***************************************************/

#ifndef PURPLEROOM_HPP
#define PURPLEROOM_HPP

#include "Room.hpp"
#include "PurpleMaster.hpp"
#include "PurpleTrainer.hpp"
#include "Game.hpp"
#include "Player.hpp"

class PurpleRoom : public Room
{
private:
	Game *master;
	Game *enemy1;
	Game *enemy2;
	Game *enemy3;

public:
	PurpleRoom(Player*);
	~PurpleRoom();
	virtual void setTrainerUp();
	virtual bool changeRoomDown();
	virtual void displayMsg() const;
	void createBound();
};
#endif


