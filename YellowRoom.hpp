/**************************************************
 * Program name: Final Project YellowRoom.hpp
 * Author: Alan Macabuhay
 * Date: 3/15/17
 * Description: Header file for YellowRoom class
 ***************************************************/

#ifndef YELLOWROOM_HPP
#define YELLOWROOM_HPP

#include "Room.hpp"
#include "YellowMaster.hpp"
#include "YellowTrainer.hpp"
#include "Game.hpp"
#include "Player.hpp"

class YellowRoom : public Room
{
private:
	Game *masterEnemy;
	Game *enemy1;

public:
	YellowRoom(Player*);
	~YellowRoom();
	virtual void setTrainerLeft();
	virtual bool changeRoomRight();
	void createBound();
	virtual void displayMsg() const;
};
#endif
