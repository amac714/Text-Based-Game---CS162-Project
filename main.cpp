/***********************************************************
 * Program Name: Final Project main.cpp
 * Author: Alan Macabuhay
 * Date: 3/14/17
 * Description: This program is a text based rpg fighting game.
 *	To become a Karate Master, user must fight all masters to earn
 *	belts. Collect all 5 belts and defeate the Black Master to
 *	become Karate Master.
 * How to run: run make and run executable called final
 ************************************************************/

#include "Game.hpp"
#include "Room.hpp"
#include "MainHall.hpp"
#include "Player.hpp"
#include "YellowRoom.hpp"
#include "OrangeRoom.hpp"
#include "PurpleRoom.hpp"
#include "BlackRoom.hpp"
#include "ChampRoom.hpp"

//function declaration
void buildGame();

int main()
{
	int choice;

	do {
		cout << endl;
		cout << " ##    ##    ###    ########     ###    ######## ########    ##     ##    ###     ######  ######## ######## ######## \n"; 
		cout << " ##   ##    ## ##   ##     ##   ## ##      ##    ##          ###   ###   ## ##   ##    ##    ##    ##       ##     ## \n";
		cout << " ##  ##    ##   ##  ##     ##  ##   ##     ##    ##          #### ####  ##   ##  ##          ##    ##       ##     ## \n";
		cout << " #####    ##     ## ########  ##     ##    ##    ######      ## ### ## ##     ##  ######     ##    ######   ########  \n";
		cout << " ##  ##   ######### ##   ##   #########    ##    ##          ##     ## #########       ##    ##    ##       ##   ##   \n";
		cout << " ##   ##  ##     ## ##    ##  ##     ##    ##    ##          ##     ## ##     ## ##    ##    ##    ##       ##    ##  \n";
		cout << " ##    ## ##     ## ##     ## ##     ##    ##    ########    ##     ## ##     ##  ######     ##    ######## ##     ##  \n";                                                                      		
		cout << "\nBecome a Master by becoming a Black Belt and challenging the Champion!" << endl;

		cout << "\n1. Start Game." << endl;
		cout << "2. Quit. " << endl;

		while(!(cin >> choice) || choice < 1 || choice > 2)
		{
			cout << "Enter a valid choice." << endl;
			cin.clear();
			cin.ignore();
		}

		if(choice == 1)
		{
			buildGame();
		}


}while(choice != 2);

	return 0;
}

/*********************************************
 * buildGame()
 * builds and starts a game of Karate Master
 ********************************************/
void buildGame()
{
	Player *user = new Player;

	Room *currRoom;
	Room *main = new MainHall(user);
	Room *yellow = new YellowRoom(user);
	Room *orange = new OrangeRoom(user);
	Room *purple = new PurpleRoom(user);
	Room *black = new BlackRoom(user);
	Room *champ = new ChampRoom(user);

	main->setUp(purple);
	main->setLeft(yellow);
	main->setRight(orange);
	main->setDown(black);
	black->setUp(main);
	black->setDown(champ);
	orange->setLeft(main);
	yellow->setRight(main);
	purple->setDown(main);

	currRoom = main;
	//user->addBelt("Purple Belt");
	
	while(user->getStamina() > 0)
	{
		currRoom->printRoom();
		currRoom->moveUser();

		if(currRoom->changeRoomLeft())
		{  
			currRoom = currRoom->getLeft();
			currRoom->setTrainerLeft();
		}
		else if(currRoom->changeRoomRight())
		{
			currRoom = currRoom->getRight();
			currRoom->setTrainerRight();
		}
		else if(currRoom->changeRoomDown())
		{
			currRoom = currRoom->getDown();
			currRoom->setTrainerDown();
		}
		else if(currRoom->changeRoomUp())
		{
			currRoom = currRoom->getUp();
			currRoom->setTrainerUp();
		}
		user->decreaseStamina(1);	
	}	

	if(user->getStamina() <= 0)
	{
		cout << "\nGame Over!" << endl;
		cout << "\n\n" << endl;
	}

	delete user;
	delete main;
	delete yellow;
	delete orange;
	delete purple;
	delete black;
	delete champ;



}
