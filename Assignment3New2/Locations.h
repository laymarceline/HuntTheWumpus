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
*		Locations Header File
*/
#ifndef LOCATIONS_H
#define LOCATIONS_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

class Locations {
protected:
	//Functions available to this class and inherited class
	int playerLoc;
	int pitLoc1;
	int pitLoc2;
	int wumpusLoc;
	int wumpusStart;
	int batLoc1;
	int batLoc2;
	int extraArrow1;
	int extraArrow2;
	int extraOil1;
	int extraOil2;

	int adjacentRooms[20][3];
	string adjacentDirections[20][3];
	string caveDesc[140];

public:
	//Constructors
	Locations();

	//Destructor
	~Locations();

	//Getters
	string getCavesInfo(int);
	int getAdjacentRooms(int, int);
	string getAdjacentDirections(int, int);
	int getPlayerLoc();
	int getWumpusLoc();
	int getPit1Loc();
	int getPit2Loc();
	int getBat1Loc();
	int getBat2Loc();
	int getExtraArrow1();
	int getExtraArrow2();
	int getExtraOil1();
	int getExtraOil2();

	//Setters
	void setCavesInfo(int, string);
	void setAdjacentRooms();
	void setAdjacentDirections();
	void setWumpusLoc(int);
	void setPitLoc(int, int);
	void setBatLoc(int, int);
	void setPlayerLoc(int);
	void setRandomLoc();
	void setExtraArrow1(int);
	void setExtraArrow2(int);
	void setExtraOil1(int);
	void setExtraOil2(int);

	//Utility Functions
	bool isRoomAdjacent(int, int);
	void moveWumpusLoc();
	void takeCavesInfo(string);
	void displayCurrentData();
};
#endif // !LOCATIONS_H
