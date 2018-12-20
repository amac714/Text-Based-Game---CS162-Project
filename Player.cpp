/*****************************************************
 * Program Name: Final Project Player.cpp
 * Author: Alan Macabuhay
 * Date: 3/12/17
 * Description: Implementation of Player class
 ****************************************************/

#include "Player.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/**********************************
 * constructor
 *********************************/
Player::Player() 
{
	this->trainer = 'A';
	this->stamina = 400;
}

/*********************************
 * destructor
 ********************************/
Player::~Player()
{
	//empty destructor
}

/********************************
 * addBelt(string b);
 * add a belt into the bag
 * Paramater: string b
 ******************************/
void Player::addBelt(std::string b)
{
	if(bag.size() > 6)
	{
		cout << "Your bag is full." << endl;
	}
	else
	{
		bag.push_back(b);
	}	
}

/*************************************
 * deleteItem(int n)
 * makes space in Player's bag
 * Paramater: int n
 ************************************/
void Player::deleteItem(int n)
{
	if(bag[n+1] == "Potion")
	{
		//if player has potion, increase stamina by 5
		//and delete potion
		setStamina((getStamina() + 5));
		bag.erase(bag.begin() + n);
	}
	else
	{
		cout << bag[n+1] << " has no effect." << endl;
	}
}

/*****************************************
 * printBag()
 * prints content of bag
 ****************************************/
void Player::printBag() const
{
	for(unsigned int i = 0; i < bag.size(); i++)
	{
		cout << bag[i] << " ";
	}
}

/******************************************
 * decreaseStamina(int a)
 * decreases Player's stamina
 * Paramater: int a
 *****************************************
void Player::decreaseStamina(int a)
{
	stamina -= a;
}*/

/****************************************
 * setStamina(int s)
 * sets stamina for player
 ***************************************/
void Player::setStamina(int s)
{
	if(stamina == 100)
	{
		cout << "Stamina is full" << endl;
	}
	else
	{
		stamina += s;
	}
}

/*************************************
 * checkBag(string item)
 * checks contents of player's bag
 * Parameter: string item
 ************************************/
bool Player::checkBag(std::string item)
{
	bool flag = false;

	for(unsigned int i = 0; i < bag.size(); i++)
	{
		if(bag[i] == item)
			flag = true;
	}

	return flag;
}
