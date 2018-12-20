/*********************************************
 * Program Name: Final Project Player.hpp
 * Author: Alan Macabuhay
 * Date: 3/12/17
 * Description: Header file for Player class
 ********************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Game.hpp"
#include <vector>

class Player : public Game
{
private:
	std::vector<std::string> bag;

public:
	Player();
	~Player();
	void addBelt(std::string);
	void deleteItem(int); 
	void printBag() const;
	//void decreaseStamina(int);
	virtual void setStamina(int s);
	bool checkBag(std::string);
		
};
#endif

