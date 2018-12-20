/*******************************************************
 * Program Name: Final Project Game.hpp
 * Author: Alan Macabuhay
 * Date: 3/12/17
 * Description: Header for Game class. Game class handles
 *  all data involving the player and non-player characters
 *  in the rooms. 
 ******************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <cstdlib>
#include <ctime>
#include <string>

class Game
{
protected:
	char trainer;
	int colPos;
	int rowPos;
	int stamina;
	std::string belt;

public:
	Game();
	virtual ~Game() = 0;
	virtual void setCol(int);
	virtual void setRow(int);
	virtual void setStamina(int s);
	virtual void decreaseStamina(int d);
	virtual int getCol() const;
	virtual int getRow() const;
	virtual int getStamina() const;
	virtual char getTrainer() const;
	virtual std::string getBelt() const;
	int diceRoll(int);
	int attack(int d, int s);
	
};
#endif
