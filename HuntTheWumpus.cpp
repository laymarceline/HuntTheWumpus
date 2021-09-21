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
*		Hunt The Wumpus CPP File
*/

#include "HuntTheWumpus.h"

using namespace std;

int main() {
	srand(time(NULL));

	//Display Game Introduction
	displayText("Introduction.txt");

	//Display Options Menu
	optionsMenu();

}

char optionsMenu() {

	//Display main menu options
	cout << "\n\t====================================================================================================";
	cout << "\n\t\t\t\t\t\tHunt the Wumpus";
	cout << "\n\t====================================================================================================" << endl;
	cout << endl;
	cout << "\tChoose an option: " << endl;
	cout << "\n\t[P] Play the game " << endl;
	cout << "\n\t[I] Display introduction" << endl;
	cout << "\n\t[R] Display rules" << endl;

	//Ask the player for option choice
	char choice = askForLetter("\n\tWhat is your choice? ");

	//Switch case of choices
	switch (choice)
	{
	case'P':
		//Clear the scren
		system("cls");

		//Display text from file
		displayText("Rules.txt");

		//Go to Prepare Game functions to do initialization
		prepareGame();
		break;
	case 'I':
		//Clear the screen
		system("cls");

		//Dsiplay the introduction from file
		displayText("Introduction.txt");

		//Return to Options Menu function
		return optionsMenu();
		break;
	case 'R':
		//Clear the screen
		system("cls");

		//Dsiplay the rules from file
		displayText("Rules.txt");

		//Return to Options Menu function
		return optionsMenu();
		break;
	default:
		//If option chose is invalid
		cout << "\nPlease enter a valid option!" << endl;

		//Wait for the player
		waitForPlayer();

		//Return to Options Menu function
		return optionsMenu();
		break;
	}
}

void prepareGame() {

	int playerType;

	//Ask for player name
	string playerName = askForString("Please enter your name: ");

	//Declare the player class object as local variable
	Player thePlayer(playerName);

	//Ask for player type
	cout << "\nTypes of player: ";
	cout << "\n[1] Rookie";
	cout << "\n[2] Hunter";
	cout << "\n[3] Master Hunter";
	cout << "\n\nWhat do you want to choose?(Enter a number only) ";
	cin >> playerType;


	switch (playerType)
	{
	case 1:
		//Set the Player type to Rookie
		thePlayer.setPlayerType(Rookie);
		break;
	case 2:
		//Set the Player type to Hunter
		thePlayer.setPlayerType(Hunter);
		break;
	case 3:
		//Set the Player type to Master Hunter
		thePlayer.setPlayerType(MasterHunter); 
		break;
	default:
		//Invalid option
		cout << "\nPlease enter a valid option" << endl;

		//Wait for the player and clear the screen
		waitForPlayer();
		prepareGame();
		break;
	}

	cout << thePlayer.getPlayerDetails() << endl;

	//Creating a map as well as initializing the attributes of hazards and player location
	createMap();

	//Take cave information from .txt file and store in class array
	location1.takeCavesInfo("CavesOriginal.txt");

	//Take cave adjacent rooms from existing array and store in new 2D Array
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//Set the Adjacent Rooms in class variable
			location1.setAdjacentRooms();
		}
	}

	//Take cave visible exits from existing array and store in new 2D Array
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//Set the Adjacent Directions in class variable
			location1.setAdjacentDirections();
		}
	}

	//Run the main game
	thePlayer.runGame(location1);
}

void createMap() {

	const int MAX = 20;

	const string EMPTY = " ";

	vector<string> map(MAX, EMPTY);

	int a = rand() % 20;

	map[a] = "Wumpus";
	location1.setWumpusLoc(a + 1);


	//Making an array of 2 pits
	int pit[2] = { 0,0 };
	int count = 0;
	//As long as the pit array is less than 2, the while loop will do looping
	while (count < 2) {

		//Setting a random number from 0-19
		int b = rand() % 20;

		//Check if the index of the array is empty
		if (map[b] == EMPTY) {

			//Store the random number in pit array 
			pit[count] = b + 1;
			count++;

			//Fill the array with the word Pit
			map[b] = "Pit";
		}
	}

	//Using the set function from class to set the location of pits
	location1.setPitLoc(pit[0], pit[1]); 

	int bat[2] = { 0,0 }; 
	int count2 = 0;
	//As long as the bat array is less than 2, the while loop will do looping
	while (count2 < 2) {

		//Setting a random number from 0-19
		int c = rand() % 20;

		//Check if the index of the array is empty
		if (map[c] == EMPTY) {

			//Store the random number in bat array 
			bat[count2] = c + 1;
			count2++;

			//Fill the array with the word Bat
			map[c] = "Bat";
		}
	}
	//Using the set function from class to set the location of bats
	location1.setBatLoc(bat[0], bat[1]);

	//Setting a random number from 0-19
	int count3 = 0;
	int e;

	while (count3 < 1) {
		int d = rand() % 20;
		if (map[d] == EMPTY) {
			e = d + 1;
			count3++;
		}
	}

	//Using the set function from class to set the location of player
	location1.setPlayerLoc(e);

	int arrow[2] = { 0,0 };
	int count4 = 0;
	//As long as the bat array is less than 2, the while loop will do looping
	while (count4 < 2) {

		//Setting a random number from 0-19
		int f = rand() % 20;

		//Check if the index of the array is empty
		if (map[f] == EMPTY) {

			//Store the random number in bat array 
			arrow[count4] = f + 1;
			count4++;

			//Fill the array with the word Bat
			map[f] = "Arrow";
		}
	}
	//Using the set function from class to set the location of bats
	location1.setExtraArrow1(arrow[0]);
	location1.setExtraArrow2(arrow[1]);

	int oil[2] = { 0,0 };
	int count5 = 0;
	//As long as the bat array is less than 2, the while loop will do looping
	while (count5 < 2) {

		//Setting a random number from 0-19
		int g = rand() % 20;

		//Check if the index of the array is empty
		if (map[g] == EMPTY) {

			//Store the random number in bat array 
			arrow[count5] = g + 1;
			count5++;

			//Fill the array with the word Bat
			map[g] = "Oil";
		}
	}
	//Using the set function from class to set the location of bats
	location1.setExtraOil1(oil[0]);
	location1.setExtraOil2(oil[1]);

	//Wait for the player
	waitForPlayer();
}

void displayText(string myFileName) {
	string str;
	//Take informations from the file
	ifstream fileToOpen;
	//Open the file
	fileToOpen.open(myFileName);
	//Check whether file is open
	if (fileToOpen.is_open()) {
		//While file has not reached the end
		while (!fileToOpen.eof()) {

			//Get a line from the file
			getline(fileToOpen, str);

			//Display each line
			cout << str << endl;
		}
		//Close the file
		fileToOpen.close();
	}
	//Wait for the Player 
	waitForPlayer();
}

string askForString(string question) {
	//Create a guard
	string answer = " ";
	while (answer == " ") {
		//Display the quesion
		cout << "\n" << question;
		cin >> answer;
	}
	return answer;
}

char askForLetter(string question) {
	//Create a guard
	char choice = ' ';
	while (choice == ' ') {
		cout << "\n" << question;
		cin >> choice;
	}
	//whatever the input,
	//it'll be return to uppercase
	return toupper(choice);
}

void waitForPlayer() {
	cout << endl;
	system("pause");

	//Clear the screen
	system("cls");
}