/**********************************************************
 * Program Name: Final Project Room.cpp
 * Author: Alan Macabuhay
 * Date: 3/9/17
 * Description: Implementation of Room class
 *********************************************************/

#include "Room.hpp"

//using std::cout;
//using std::cin;
//using std::endl;

/*******************************
 * constructor
 *******************************/
Room::Room(Player *user1)
{
	user = user1;
	rows = 20;
	cols = 21;
	
	right = NULL;
	left = NULL;
	up = NULL;
	down = NULL;

	//create space 
	space = new Game**[rows];
	for(int i = 0; i < rows; i++) {
		space[i] = new Game* [cols];
	}

	//fill space 
	for(int r = 0; r < rows; r++) {
		for(int c = 0; c < cols; c++) {
			space[r][c] = NULL;
		}
	}

}

//destructor
Room::~Room()
{
	//clear memory
	for(int r = 0; r < rows; r++)
	{
		for(int c = 0; c < cols; c++)
		{
			space[r][c] = NULL;
			delete space[r][c];
		}

		delete [] space[r];
	}
	delete [] space;
	space = NULL;
}

/**************************************************
 * printRoom()
 * prints out status of current room player is in
 *************************************************/
void Room::printRoom() const
{

	cout << "\nStamina: " << this->user->getStamina() << "\n" << endl;

	for(int r = 0; r < rows; r++)
	{
		for(int c = 0; c < cols; c++)
		{
			if(space[r][c] == NULL)
				cout << "-";
			else
				cout << space[r][c]->getTrainer();
		}
		
		cout << endl;
	}

	displayMsg();

	cout << "\nBag: ";
	this->user->printBag();
	
	cout << "\nControls: a = left   d = right   s = down   w = up   e = interact" << endl;
	
}

/***************************************************
 * moveUser()
 * updates user's coordinates 
 **************************************************/
void Room::moveUser()
{
	char move;

	while(!(cin >> move))
	{
		cout << "Enter valid choice." << endl;
		cin.clear();
		cin.ignore();
	}

	switch(move)
	{
		//left
		case 'a': 
				if(user->getCol() > 0)
				{
					if(space[user->getRow()][user->getCol() - 1] == NULL)
					{
						space[user->getRow()][user->getCol() - 1] = user;
						space[user->getRow()][user->getCol()] = NULL;
						user->setCol(user->getCol() - 1);
					}
				}
				break;
		//right
		case 'd':
				if(user->getCol() < cols - 1)
				{
					if(space[user->getRow()][user->getCol() + 1] == NULL)
					{
						space[user->getRow()][user->getCol() + 1] = user;
						space[user->getRow()][user->getCol()] = NULL;
						user->setCol(user->getCol() + 1);
					}
				}
				break;

		//up
		case 'w':
				if(user->getRow() > 0) {
					if(user->getRow() < rows + 1)
					{
						if(space[user->getRow() - 1][user->getCol()] == NULL)
						{
							space[user->getRow() - 1][user->getCol()]= user;
							space[user->getRow()][user->getCol()] = NULL;
							user->setRow(user->getRow() - 1);
						}
					}
				}
				break;

		//down
		case 's':
				if(user->getRow() < rows - 1)
				{
					if(space[user->getRow() + 1][user->getCol()] == NULL)
					{
						space[user->getRow() + 1][user->getCol()] = user;
						space[user->getRow()][user->getCol()] = NULL;
						user->setRow(user->getRow() + 1);
					}
				}
				break;

		//interactions
		case 'e':

				//Yellow trainer
				if(space[user->getRow()][user->getCol() - 1] != NULL &&
					space[user->getRow()][user->getCol() - 1]->getTrainer() == 'y' &&
					user->checkBag("White Belt"))
				{
					Game *enemy = space[user->getRow()][user->getCol() - 1];

					if(user->diceRoll(4) > enemy->diceRoll(4))
					{
						cout << "\nYou have defeated the Yellow Trainer!" << endl;
						enemy->setStamina(0);
						space[user->getRow()][user->getCol() - 1] = NULL;
						enemy = NULL;;
					}
					else
					{
						user->decreaseStamina(2);
						cout << "\n\nYou take 2 damage." << endl;
					}
				
				}
				else if(space[user->getRow()][user->getCol() - 1] != NULL &&
					space[user->getRow()][user->getCol() - 1]->getTrainer() == 'y' &&
					!user->checkBag("White Belt"))
						cout << "\n\nYou are not ready. You need a White Belt before you can challenge me." << endl;
				
				//Yellow Master
				if(space[user->getRow()][user->getCol() - 1] != NULL &&
					space[user->getRow()][user->getCol() - 1]->getTrainer() == 'Y')
				{
					Game *enemy = space[user->getRow()][user->getCol() - 1];
					
					while(user->getStamina() > 0 && enemy->getStamina() > 0)
					{
						int usrDmg = user->attack(1, 4);
						int enDmg = enemy->attack(1, 4);

						if(user->diceRoll(3) > enemy->diceRoll(3))
						{
							cout << "\nYou deal " << usrDmg << " damage." << endl;
							enemy->decreaseStamina(usrDmg);
						}
						else
						{
							cout << "\nYou take " << enDmg << " damage." << endl;
							user->decreaseStamina(enDmg);	
						}
					}

					if(enemy->getStamina() <= 0 && !user->checkBag("Yellow Belt"))
					{
						cout << "\n\nYou have proven your skills and defeated the Yellow Master." << endl;
						cout << "You have earned the Yellow Belt. Your strength increases." << endl;
						user->addBelt("Yellow Belt");
		
						enemy = NULL;
						
					}
					else if(user->getStamina() <= 0)
					{
						cout << "\nYou were not prepared. You fainted." << endl;
					}

				}





				//Orange trainer
				if(space[user->getRow()][user->getCol() + 1] != NULL &&
					space[user->getRow()][user->getCol() + 1]->getTrainer() == 'o' &&
					user->checkBag("Yellow Belt"))
				{
					Game *enemy = space[user->getRow()][user->getCol() + 1];

					if(user->diceRoll(4) > enemy->diceRoll(6))
					{
						cout << "\n\nYou have defeated an Orange trainer. Continue and challenge the Master.'" << endl;

						enemy->setStamina(0);
						
						space[user->getRow()][user->getCol() + 1] = NULL;
						enemy = NULL;
					}
					else
					{
						user->decreaseStamina(4);
						cout << "\n\nYou take 4 damage." << endl;
					}
				
				}
				//facing up
				else if(space[user->getRow() - 1][user->getCol()] != NULL &&
					space[user->getRow() - 1][user->getCol()]->getTrainer() == 'o' &&
					user->checkBag("Yellow Belt"))
				{
					Game *enemy = space[user->getRow() - 1][user->getCol()];

					if(user->diceRoll(4) > enemy->diceRoll(6))
					{
						cout << "\n\nYou have defeated an Orange trainer. Continue and challenge the Master.'" << endl;
						enemy->setStamina(0);
						space[user->getRow() - 1][user->getCol()] = NULL;
						enemy = NULL;
					}
					else
					{
						user->decreaseStamina(4);
						cout << "\n\nYou take 4 damage." << endl;
					}
				
				}
				else if(space[user->getRow()][user->getCol() + 1] != NULL &&
					space[user->getRow()][user->getCol() + 1]->getTrainer() == 'o' &&
					!user->checkBag("Yellow Belt"))
						cout << "\n\nYou are not ready. You need a Yellow Belt before you can challenge." << endl;





				//orange master
				 if(space[user->getRow() - 1][user->getCol()] != NULL &&
					space[user->getRow() - 1][user->getCol()]->getTrainer() == 'O')
				{
					Game *enemy = space[user->getRow() - 1][user->getCol()];
					
					//cout << "\nGood job making it this far. Let's see how prepared you are." << endl;
					while(user->getStamina() > 0 && enemy->getStamina() > 0)
					{
						int usrDmg = user->attack(2, 4);
						int enDmg = enemy->attack(1, 6);

						if(user->diceRoll(3) > enemy->diceRoll(3))
						{
							cout << "\nYou deal " << usrDmg << " damage." << endl;
							enemy->decreaseStamina(usrDmg);
						}
						else
						{
							cout << "\nYou take " << enDmg << " damage." << endl;
							user->decreaseStamina(enDmg);	
						}
					}

					if(enemy->getStamina() <= 0 && !user->checkBag("Orange Belt"))
					{
						cout << "\n\nYou have proven your skills and defeated the Orange Master." << endl;
						cout << "You have earned the Orange Belt. Your strength increases!" << endl;
						user->addBelt("Orange Belt");
		
						cout << "\nYou restore some stamina." << endl;
						user->setStamina((user->getStamina() + 5));

						enemy = NULL;
					}
					else if(user->getStamina() <= 0)
					{
						cout << "\nYou were not prepared. You fainted." << endl;
					}					
				}






				//purple trainer
				if(space[user->getRow() - 1][user->getCol()] != NULL &&
					space[user->getRow() - 1][user->getCol()]->getTrainer() == 'p' &&
					user->checkBag("Yellow Belt"))
				{
					Game *enemy = space[user->getRow() - 1][user->getCol()];
					if(user->diceRoll(4) > enemy->diceRoll(7))
					{
						cout << "\nYou have defeated a Purple trainer. Continue and challenge the Master." << endl;
						
						enemy->setStamina(0);
						
						space[user->getRow() - 1][user->getCol()] = NULL;
						enemy = NULL;
					}
					else
					{
						user->decreaseStamina(4);
						cout << "\nYou take 4 damage." << endl;
					}
				
				}
				else if(space[user->getRow() - 1][user->getCol()] != NULL &&
					space[user->getRow() - 1][user->getCol()]->getTrainer() == 'p' &&
					!user->checkBag("Orange Belt"))
						cout << "\nYou are not ready. You need an Orange Belt before you can challenge." << endl;


				//purple master
				 if(space[user->getRow() - 1][user->getCol()] != NULL &&
					space[user->getRow() - 1][user->getCol()]->getTrainer() == 'P')
				{
					Game *enemy = space[user->getRow() - 1][user->getCol()];
					
					cout << "\nGood job making it this far. Let's see how prepared you are." << endl;
					
					while(user->getStamina() > 0 && enemy->getStamina() > 0)
					{
						int usrDmg = user->attack(2, 5);
						int enDmg = enemy->attack(1, 8);

						if(user->diceRoll(3) > enemy->diceRoll(3))
						{
							cout << "\nYou deal " << usrDmg << " damage." << endl;
							enemy->decreaseStamina(usrDmg);
						}
						else
						{
							cout << "\nYou take " << enDmg << " damage." << endl;
							user->decreaseStamina(enDmg);	
						}
					}

					if(enemy->getStamina() <= 0 && !user->checkBag("Purple Belt"))
					{
						cout << "\n\nYou have proven your skills and defeated the Purple Master." << endl;
						cout << "You have earned the Purple Belt. Your strength increases." << endl;
						user->addBelt("Purple Belt");
		
						cout << "\nYou restore some stamina." << endl;
						user->setStamina((user->getStamina() + 6));

						enemy = NULL;
					}
					else if(user->getStamina() <= 0)
					{
						cout << "\nYou were not prepared. You fainted." << endl;
					}					
				}







				//black trainer
				if(space[user->getRow() - 1][user->getCol()] != NULL && 
					space[user->getRow() - 1][user->getCol()]->getTrainer() == 'b' &&
					user->checkBag("Purple Belt"))
				{
					Game *enemy = space[user->getRow() - 1][user->getCol()];
					if(user->diceRoll(4) > enemy->diceRoll(7))
					{
						cout << "\nYou are worthy. Continue and challenge the Black Master." << endl;
						enemy->setStamina(0);
						space[user->getRow() - 1][user->getCol()] = NULL;
						enemy = NULL;
					}
					else
					{
						user->decreaseStamina(5);
						cout << "\nYou take 5 damage" << endl;
					}

				}
				else if(space[user->getRow() - 1][user->getCol()] != NULL && 
					space[user->getRow() - 1][user->getCol()]->getTrainer() == 'b' &&
					!(user->checkBag("White Belt")))
				{
					cout << "\n\nWELCOME to the Dojo! Do you have what it takes to become a Karate Master?" << endl;
					cout << "Take this White Belt and challenge the other Masters. Return here when ready." << endl;

					user->addBelt("White Belt");
		
				}

				//black master
				 if(space[user->getRow() - 1][user->getCol()] != NULL &&
					space[user->getRow() - 1][user->getCol()]->getTrainer() == 'B')
				{
					Game *enemy = space[user->getRow() - 1][user->getCol()];
					
					cout << "\nGood job making it this far. Prepare for battle!" << endl;
				
					while(user->getStamina() > 0 && enemy->getStamina() > 0)
					{
						int usrDmg = user->attack(2, 6);
						int enDmg = enemy->attack(1, 10);

						if(user->diceRoll(3) > enemy->diceRoll(3))
						{
							cout << "\nYou deal " << usrDmg << " damage." << endl;
							enemy->decreaseStamina(usrDmg);
						}
						else
						{
							cout << "\nYou take " << enDmg << " damage." << endl;
							user->decreaseStamina(enDmg);	
						}
					}

					if(enemy->getStamina() <= 0 && !user->checkBag("Black Belt"))
					{
						cout << "\n\nYou have proven your skills and defeated the Black Master." << endl;
						cout << "You have earned the Black Belt. Now it is time for you to test your abilites." << endl;
						cout << "\nContinue and challenge the Champion!!" << endl;
						user->addBelt("Black Belt");
		
						cout << "\nYou restore some stamina." << endl;
						user->setStamina((user->getStamina() + 6));
						
						//clear space black master is on to open up next room
						space[user->getRow() - 1][user->getCol()] = NULL;
						enemy = NULL;
					}
					else if(user->getStamina() <= 0)
					{
						cout << "\nYou were not prepared. You fainted." << endl;
					}					
				}



					//champion
					if(space[user->getRow() - 1][user->getCol()] != NULL &&
					space[user->getRow() - 1][user->getCol()]->getTrainer() == 'C')
				{
					Game *enemy = space[user->getRow() - 1][user->getCol()];
					
					//cout << "\nDo you have what it takes to become a champion?" << endl;
				
					while(user->getStamina() > 0 && enemy->getStamina() > 0)
					{
						int usrDmg = user->attack(3, 6);
						int enDmg = enemy->attack(1, 12);

						if(user->diceRoll(3) > enemy->diceRoll(3))
						{
							cout << "\nYou deal " << usrDmg << " damage." << endl;
							enemy->decreaseStamina(usrDmg);
						}
						else
						{
							cout << "\nYou take " << enDmg << " damage." << endl;
							user->decreaseStamina(enDmg);	
						}
					}

					if(enemy->getStamina() <= 0)
					{
						cout << "\n\nYou have proven your valor."
							<< " You are now the new Champion and a Karate Master!" << endl;
						cout << "\nCongratulations!!" << endl;
						user->decreaseStamina(user->getStamina());
					}
					else if(user->getStamina() <= 0)
					{
						cout << "\nYou were not strong enough! You have fainted." << endl;
							
					}
				}
					


	

					//shortcut. can only do when user is to the left of the short cut
					if(space[user->getRow()][user->getCol() + 1] != NULL &&
					space[user->getRow()][user->getCol() + 1]->getTrainer() == 'x'
					 && user->checkBag("Purple Belt"))
					{
						space[user->getRow()][user->getCol() + 1] = NULL;
					}


				break;

		default:
				cout << "Enter a valid move." << endl;
				break;
	}
}

/***************************************
 * set methods
 ***************************************/
void Room::setRight(Room *r)
{
	this->right = r;
}

void Room::setLeft(Room *l)
{
	this->left = l;
}

void Room::setUp(Room *u)
{
	this->up = u;
}

void Room::setDown(Room *d)
{
	this->down = d;
}
/********************************************
 * get methods
 ********************************************/
Room* Room::getRight() const
{
	return this->right;
}

Room* Room::getLeft() const
{
	return this->left;
}

Room* Room::getUp() const
{
	return this->up;
}

Room* Room::getDown() const
{
	return this->down;
}

/*************************************
 * setTrainerRight()
 * sets user's location 
 ************************************/
void Room::setTrainerRight()
{
	//nothing here
}

/***********************************
 * setTrainerLeft()
 * sets user's location
 **********************************/
void Room::setTrainerLeft()
{
	//nothing
}

/***********************************
 * setTrainerUp()
 * sets user's location
 **********************************/
void Room::setTrainerUp()
{
	//does nothing
}

/***********************************
 * setTrainerDown()
 * sets user's location
 **********************************/
void Room::setTrainerDown()
{
	//does nothing
}


/*********************************************
 * changeRoomLeft()
 * checks if user can change rooms
 ********************************************/
bool Room::changeRoomLeft()
{
	return false;
}

/*********************************************
 * changeRoomRight()
 * checks if user can change rooms
 ********************************************/
bool Room::changeRoomRight()
{
	return false;
}

/*******************************************
 * changeRoomUp()
 * checks if user can change rooms
 *******************************************/
bool Room::changeRoomUp()
{
	return false;
}

/*****************************************
 * changeRoomDown()
 * checks if user is changing rooms
 ****************************************/
bool Room::changeRoomDown()
{
	return false;
}


//displayMsg()
void Room::displayMsg() const
{
	cout << "\nHint: You must get the belts in a certain order." << endl;
}
