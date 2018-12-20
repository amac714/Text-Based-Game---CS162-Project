/***********************************************************
 * Program Name: Final Project Room.hpp
 * Author: Alan Macabuhay
 * Date: 3/9/17
 * Description: Header file for abstract class Room
 **********************************************************/

#include <string>
#include <iostream>
#include <fstream>
#include "Game.hpp"
#include "Player.hpp"
#include "Door.hpp"
#include "Short.hpp"

#ifndef ROOM_HPP
#define ROOM_HPP


using std::cout;
using std::endl;
using std::cin;

class Room
{
protected:
	Room *right;
	Room *left;
	Room *up;
	Room *down;

	Game ***space;
	Player *user;
	
	int rows;
	int cols;
	Door door;
	Short cut;

public:
	Room(Player *);
	virtual ~Room() = 0;
	virtual void printRoom() const;
	void moveUser();
	
	virtual Room *getRight() const;
	virtual Room *getLeft() const;
	virtual Room *getUp() const;
	virtual Room *getDown() const;
	
	virtual void setRight(Room*);
	virtual void setLeft(Room*);
	virtual	void setUp(Room*);
	virtual void setDown(Room*);
	
	virtual void setTrainerRight();
	virtual void setTrainerLeft();
	virtual void setTrainerUp();
	virtual void setTrainerDown();
	
	virtual bool changeRoomLeft();
	virtual bool changeRoomRight();
	virtual bool changeRoomUp();
	virtual bool changeRoomDown();
	
	virtual void displayMsg() const;
	virtual void createBound() = 0;	
};
#endif
