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
*		Hunt The Wumpus Header File
*/
#ifndef HUNTTHEWUMPUS_H
#define HUNTTHEWUMPUS_H
#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include "Player.h"

//New object of locations class as global variable
Locations location1;

//Display options menu
char optionsMenu();

//Prepare the game, initialize all attributes
void prepareGame();

//Initialize plaer location and hazard location attributes 
void createMap();

//Display text from .txt file
void displayText(string myFileName);

//Ask for string input from the player
string askForString(string question);

//Ask for character/letter input from the player
char askForLetter(string question);

//Wait for the player
void waitForPlayer();

#endif // !HUNTTHEWUMPUS_H
