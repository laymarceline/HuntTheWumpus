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
*		Locations CPP File
*/
#include "Locations.h"

//Constructors
Locations::Locations() {
	wumpusLoc = 0;
	pitLoc1 = 0;
	pitLoc2 = 0;
	batLoc1 = 0;
	batLoc2 = 0;
	playerLoc = 0;
	extraArrow1 = 0;
	extraArrow2 = 0;
	extraOil1 = 0;
	extraOil2 = 0;

	for (int i = 0; i < 140; i++)
	{
		caveDesc[i] = " ";
	}

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			adjacentRooms[i][j] = 0;
			adjacentDirections[i][j] = " ";
		}
	}
}

//Destructor
Locations::~Locations() {

}

//Getters / Accessors
string Locations::getCavesInfo(int a) {

	return caveDesc[a];
}

int Locations::getAdjacentRooms(int a, int b) {

	return adjacentRooms[a][b];
}

string Locations::getAdjacentDirections(int a, int b) {

	return adjacentDirections[a][b];
}

int Locations::getWumpusLoc() {

	return wumpusLoc;
}

int Locations::getPit1Loc() {

	return pitLoc1;
}

int Locations::getPit2Loc() {

	return pitLoc2;
}

int Locations::getBat1Loc() {

	return batLoc1;
}

int Locations::getBat2Loc() {

	return batLoc2;
}

int Locations::getPlayerLoc() {
	//cout << playerLoc;
	return playerLoc;
}

int Locations::getExtraArrow1() {
	
	return extraArrow1;
}

int Locations::getExtraArrow2() {

	return extraArrow2;
}

int Locations::getExtraOil1() {

	return extraOil1;
}

int Locations::getExtraOil2() {

	return extraOil2;
}


//Setters
void Locations::setCavesInfo(int index, string a) {
	//Set informations into caveDesc array
	caveDesc[index] = a;
}

void Locations::setAdjacentRooms() {
	//Set a 2D Array filled with adjacent rooms of caves only
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//Take appropriate information from existing array
			int a = stoi(caveDesc[(7 * i) + j + 1]);

			//Store in new 2D array
			adjacentRooms[i][j] = a;
		}
	}
}

void Locations::setAdjacentDirections() {
	//Set a 2D Array filled with adjacent directions of caves only
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//Take appropriate information from existing array
			string a = caveDesc[(7 * i) + j + 4];

			//Store in new 2D array
			adjacentDirections[i][j] = a;

		}
	}
}

void Locations::setWumpusLoc(int newWumpus) {

	wumpusLoc = newWumpus;
}

void Locations::setPitLoc(int newPit1, int newPit2) {

	pitLoc1 = newPit1;
	pitLoc2 = newPit2;
}

void Locations::setBatLoc(int newBat1, int newBat2) {

	batLoc1 = newBat1;
	batLoc2 = newBat2;
}

void Locations::setPlayerLoc(int newPlayerLoc) {

	playerLoc = newPlayerLoc;
}

void Locations::setRandomLoc() {

	playerLoc = rand() % 20;
}

void Locations::setExtraArrow1(int newArrow) {
	extraArrow1 = newArrow;
}

void Locations::setExtraArrow2(int newArrow) {
	
	extraArrow2 = newArrow;
}

void Locations::setExtraOil1(int newOil) {

	extraOil1 = newOil;
}

void Locations::setExtraOil2(int newOil) {

	extraOil2 = newOil;
}

//Utility Function
bool Locations::isRoomAdjacent(int room1, int room2) {
	//Check whether room is adjacent or not
	for (int i = 0; i < 3; i++)
	{
		if (adjacentRooms[room1][i] == room2) {
			return true;
		}
	}
	return false;
}

void Locations::moveWumpusLoc() {

	//Move wumpus location to its adjacent location
	int loc1;
	int loc2;
	int loc3;

	//Take value from adjacentRooms array and store in variables
	loc1 = adjacentRooms[getWumpusLoc() - 1][0] + 1;
	loc2 = adjacentRooms[getWumpusLoc() - 1][1] + 1;
	loc3 = adjacentRooms[getWumpusLoc() - 1][2] + 1;

	int randLoc = rand() % 3;

	//Set the location to a new adjacent location
	setWumpusLoc(adjacentRooms[getWumpusLoc() - 1][randLoc] + 1);
	cout << "\nWARNING! The Wumpus has moved its location!" << endl;
}

void Locations::takeCavesInfo(string myFileName) {
	//Load informations from a file
	fstream fileToRead(myFileName);
	//Check if the file is open
	if (fileToRead.is_open()) {
		string line = "";
		//While the file have not reached the end
		while (!fileToRead.eof()) {
			for (int i = 0; i < 140; i++)
			{
				//Get each line from the .txt file
				getline(fileToRead, line);

				//Set and store it in 2D Class Array
				setCavesInfo(i, line);
			}
		}
	}
	//Close the file
	fileToRead.close();
}

void Locations::displayCurrentData() {
	int currentLocIndex = playerLoc - 1;

	//Display current location and description of the location
	cout << "==================================================================";
	cout << "\n\t\tSomewhere in the Wumpus Caverns";
	cout << "\n==================================================================" << endl;
	cout << "You are currently in " << playerLoc << endl;
	cout << getCavesInfo(7 * currentLocIndex);
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	//Display visible exits the player can move or shoot
	cout << " Visiible Exits: ";
	for (int i = 0; i < 3; i++)
	{
		cout << getAdjacentDirections(currentLocIndex, i);
		cout << " ";
	}
	cout << endl;
	
}