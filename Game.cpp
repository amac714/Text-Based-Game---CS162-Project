/***********************************************************
 * Program Name: Final Project Game.cpp
 * Author: Alan Macabuhay
 * Date: 3/12/17
 * Description: Implementation of Game class.
 **********************************************************/

#include "Game.hpp"

/**********************************
 * constructor
 *********************************/
Game::Game()
{
	this->trainer = 'M';
	this->stamina = 1;
	this->belt = "generic";

	//seeding rand
	srand(static_cast<unsigned int>(time(0)));
	rand();
}

Game::~Game() {}

/************************************
 * setCol(int x)
 * sets an object's x-coordinate
 * Paramaters: int x
 ************************************/
void Game::setCol(int x)
{
	colPos = x;
}

/***********************************
 * setRow(int y)
 * sets an object's y-coordinate
 * Paramaters: int y
 **********************************/
void Game::setRow(int y)
{
	rowPos = y;
}

/***************************************
 * getCol() const
 * returns an object's x-coordinate
 **************************************/
int Game::getCol() const
{
	return colPos;
}

/**************************************
 * getRow() const
 * returns an object's y-coordinate
 **************************************/
int Game::getRow() const
{
	return rowPos;
}

/***************************************
 * getStamina() const
 * returns player's stamina
 **************************************/
int Game::getStamina() const
{	
	return this->stamina;
}

/*************************************
 * getTrainer() const
 * returns trainer
 ************************************/
char Game::getTrainer() const
{
	return this->trainer;
}

/**********************************
 * getBelt() const
 * returns belt
 *********************************/
std::string Game::getBelt() const
{
	return this->belt;
}

/**********************************
 * diceRoll(int s)
 * generates a random number
 * Paramaters: int s
 *********************************/
int Game::diceRoll(int s)
{
	return rand() % s + 1;
}

/**********************************
 * setStamina(int s)
 * sets stamina
 *********************************/
void Game::setStamina(int s)
{
	this->stamina = s;
}

/**********************************
 * attack(int d, int s)
 * returns attack damage
 * Paramaters: int d, int s
 ***********************************/
int Game::attack(int d, int s)
{
	int dmg = 0;

	for(int i = 0; i < d; i++)
	{
		dmg += diceRoll(s);
	}

	return dmg;
}

/******************************************
 * decreaseStamina(int d)
 * decreases stamina
 * Paramater: int d
 *****************************************/
void Game::decreaseStamina(int d)
{
	stamina -= d;
}


