/*
* Author Name: Marceline Nathalie Layandri
* Student ID: 31205585
* Unit Code: MCD4720
* Unit Name: Fundamentals of C++
* Tutor Name: Safi Uddin
* Class: Lab 91
*
* Date Created: 19/12/2020
* Version: 1.0
*
* Description:
*		Assignment 3
*		Player Header File
*		This class inherits from Locations class
*		Player depends on Location
*/
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <sstream>
#include <vector>
#include "Locations.h"
#include "Enums.h"
using namespace std;

class Player : public Locations {
private:
	string playerName;
	int noArrows;
	int noOil;
	string playerMove;
	string playerShoot;
	int playerShootRoom;
	int playerScore;
	PlayerType playerType;

public:
	//Constructors
	Player(string);

	//Destructor
	~Player();

	//Getters / Accessor
	string getPlayerName();
	int getNoArrows();
	int getNoOil();
	PlayerType getPlayerType();
	string getPlayerTypeName();
	string getPlayerShoot();
	string getPlayerMove();
	int getPlayerShootRoom();
	int getPlayerScore();
	//Use pointer to get player location
	int getLocPointer(Locations);

	//Setters
	void setPlayerName(string);
	void setNoArrows(int);
	void setNoOil(int);
	void setPlayerMove(string);
	void setPlayerShoot(string);
	void setPlayerShootRoom(int);
	void setPlayerScore();
	void setPlayerType(PlayerType);

	//Utility Function
	//Get player information
	string getPlayerDetails();
	//Get cheat
	string getCheatDetails(Locations);
	//Display potion
	string displayPotion(string);
	//Quit Game
	int quitGame();
	//Ask for character/letter input from the player
	char askForLetter(string);
	//Move player location
	void movePlayer(Locations);
	//Shoot player
	void shootPlayer(Locations);
	//Decrease Number of Arrows
	void decreaseNoArrows();
	//Decrease Number of Oils
	void decreaseNoOils();
	//Run the game
	void runGame(Locations);
	//Check current location information
	void checkCurrentLoc(Locations);
	//Display options in game
	void gameOptions(Locations);
	//Check wumpus location
	void checkWumpus(Locations);
	//Display text from .txt file
	void displayText(string);
	//Wait for player
	void waitForPlayer();
};

#endif // !PLAYER_H
