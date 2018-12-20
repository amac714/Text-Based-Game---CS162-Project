/**************************************************
 * Program name: Final Project ChampRoom.hpp
 * Author: Alan Macabuhay
 * Date: 3/16/17
 * Description: Header file for ChampRoom class
 ***************************************************/

#ifndef CHAMPROOM_HPP
#define CHAMPROOM_HPP

#include "Room.hpp"
#include "Champion.hpp"
#include "Game.hpp"
#include "Player.hpp"

class ChampRoom : public Room
{
private:
	Game *master;

public:
	ChampRoom(Player*);
	~ChampRoom();
	virtual void setTrainerDown();
	//virtual bool changeRoomUp();
	void createBound();
	virtual void displayMsg();
};
#endif


