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
*/
#include "Player.h"

Player::Player(string newName) {
	setPlayerName(newName);
	playerMove = " ";
	playerShoot = " ";
	playerShootRoom = 0;
	playerScore = 0;
}

//Destructor
Player::~Player() {
	
}

//Getters / Accessor
string Player::getPlayerName() {
	
	return playerName;
	
}

int Player::getNoArrows() {

	return noArrows;
}

int Player::getNoOil() {

	return noOil;
}

PlayerType Player::getPlayerType() {

	return playerType;
}

string Player::getPlayerTypeName() {
	
	switch (playerType) {
	case Rookie:
		return "Rookie";
	case Hunter:
		return "Hunter";
		break;
	case MasterHunter:
		return "Master Hunter";
		break;
	default:
		return "\nPlayer Type error!";
		break;
	}
}

string Player::getPlayerShoot() {

	return playerShoot;
}

string Player::getPlayerMove() {

	return playerMove;
}

int Player::getPlayerShootRoom() {

	return playerShootRoom;
}

int Player::getPlayerScore() {

	return playerScore;
}

int Player::getLocPointer(Locations newLocation) {
	//Make a new variable filled with a value
	int playerLocation = newLocation.getPlayerLoc();
	//Make a pointer with the variable referenced
	int* pointer = &playerLocation;
	//Return the dereference of the pointer
	return (*pointer);
}

//Setters
void Player::setPlayerName(string newName) {

	playerName = newName;
}

void Player::setNoArrows(int newNoArrows) {

	noArrows = newNoArrows;
}

void Player::setNoOil(int newNoOil) {

	noOil = newNoOil;
}

void Player::setPlayerMove(string option) {

	playerMove = option;
}

void Player::setPlayerShoot(string option) {

	playerShoot = option;
}

void Player::setPlayerShootRoom(int newRoom) {

	playerShootRoom = newRoom;
}

void Player::setPlayerScore() {
	int total;
	int typeScore;

	//Additional score according to player types
	if (getPlayerTypeName() == "Rookie") {
		typeScore = 0;
	}
	else if (getPlayerTypeName() == "Hunter") {
		typeScore = 200;
	}
	else {
		typeScore = 500;
	}

	//Calculate score
	total = (noOil * 2) + (noArrows * 5) + typeScore;

	playerScore = total;
}

void Player::setPlayerType(PlayerType newPlayerType) {

	playerType = newPlayerType;

	//Assign or set number of oils and arrows according to player type
	switch (newPlayerType) {
	case Rookie:
		setNoOil(100);
		setNoArrows(5);
		break;
	case Hunter:
		setNoOil(70);
		setNoArrows(3);
		break;
	case MasterHunter:
		setNoOil(40);
		setNoArrows(1);
		break;
	default:
		cout << "\nPlayer Type error!";
		break;
	}
}

//Utility Function
string Player::getPlayerDetails() {
	stringstream playerDetails;

	//Display player details
	playerDetails << "=================================" << endl;
	playerDetails << "\nPlayer Name: " << getPlayerName() << endl;
	playerDetails << "Player Type: " << getPlayerTypeName() << endl;
	playerDetails << "No Arrows: " << getNoArrows() << endl;
	playerDetails << "No Oil: " << getNoOil() << " (turns left)" << endl;
	playerDetails << "\n=================================" << endl;

	return playerDetails.str();
}

string Player::getCheatDetails(Locations newLocation) {
	stringstream locationDetails;

	//Display Cheat Details
	locationDetails << "+ - + - + - + - + - + - + - +" << endl;
	locationDetails << " Player Loc : " << getLocPointer(newLocation) << endl;
	locationDetails << " Wumpus Loc : " << newLocation.getWumpusLoc() << endl;
	locationDetails << " Pit Loc 1  : " << newLocation.getPit1Loc() << endl;
	locationDetails << " Bat Loc 1  : " << newLocation.getBat1Loc() << endl;
	locationDetails << " Bat Loc 2  : " << newLocation.getBat2Loc() << endl;
	locationDetails << "+ - + - + - + - + - + - + - +" << endl;
	
	//locationDetails << getHazardDetails();

	return locationDetails.str();
}

string Player::displayPotion(string myFileName) {
	string str;
	string temp[5];
	ifstream fileToOpen;
	fileToOpen.open(myFileName);
	if (fileToOpen.is_open()) {
		while (!fileToOpen.eof()) {
			getline(fileToOpen, str);
			for (int i = 0; i < 5; i++)
			{
				temp[i] = str;
			}
		}
		fileToOpen.close();
	}
	int randomNo = rand() % 5;

	return temp[randomNo];
}

int Player::quitGame() {

	cout << "\t==================================================================";
	cout << "\n\t\t\t\tHunt The Wumpus";
	cout << "\n\t==================================================================" << endl;
	cout << "\n\tThe game has ended." << endl;
	cout << "\n\tSee you next time!" << endl;
	cout << endl;

	system("pause");
	return 0;
}

char Player::askForLetter(string question) {
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

void Player::movePlayer(Locations newLocation) {
	
	int count = 0;
	int a;

	//Check whether the destination cave is valid to move or exists
	if (newLocation.getAdjacentDirections(getLocPointer(newLocation) - 1, 0) == getPlayerMove() ||
		newLocation.getAdjacentDirections(getLocPointer(newLocation) - 1, 1) == getPlayerMove() ||
		newLocation.getAdjacentDirections(getLocPointer(newLocation) - 1, 2) == getPlayerMove()) {

		
		for (int i = 0; i < 3; i++)
		{
			while (newLocation.getAdjacentDirections(getLocPointer(newLocation) - 1, i) == playerMove && count < 1) {
				a = newLocation.getAdjacentRooms(getLocPointer(newLocation) - 1, i) + 1;
				decreaseNoOils();
				count++;
			}
		
		}
	
		//Move the player to a new location and set the new player location
		newLocation.setPlayerLoc(a);

		//Go to Run Game Function
		runGame(newLocation);
	}
	else {
		//The destination entered is not valid or does not exist
		cout << "Please enter a valid option!" << endl;
		//Go to In Game Options function
		gameOptions(newLocation);
	}

}

void Player::shootPlayer(Locations newLocation) {
	string option;
	int currentLocIndex = newLocation.getPlayerLoc() - 1;
	int a;
	int count = 0;

	//Ask the player for the destination cave to shoot
	cout << "Which room to shoot?";
	cin >> option;


	//Check whether the answer from the player is within the compass direction
	if (option == "N" || option == "W" || option == "S" || option == "E") {
		setPlayerShoot(option);

		//Check whether direction entered is valid to shoot or exists
		if (newLocation.getAdjacentDirections(currentLocIndex, 0) == getPlayerShoot() ||
			newLocation.getAdjacentDirections(currentLocIndex, 1) == getPlayerShoot() ||
			newLocation.getAdjacentDirections(currentLocIndex, 2) == getPlayerShoot()) {
			//cout << "\ntest before for loop" << endl;
			//system("pause");
			for (int i = 0; i < 3; i++)
			{
				
				while (newLocation.getAdjacentDirections(getLocPointer(newLocation) - 1, i) == playerShoot && count < 1) {
					a = newLocation.getAdjacentRooms(getLocPointer(newLocation) - 1, i) + 1;
					decreaseNoArrows();
					count++;
					//cout << "\ntest in while loop" << endl;
					//system("pause");
				}
			}
			//cout << "\ntest after all loop" << endl;
			//system("pause");
			//Set the room player wants to shoot
			setPlayerShootRoom(a);

			//Check whether the room has Wumpus in it
			checkWumpus(newLocation);
		}
		else {
			//Direction entered not valid to shoot or does not exist
			cout << "\nPlease enter a valid direction!";

			//Return to ask for input from the player
			shootPlayer(newLocation);
		}
	}
	else {
		//Direction entered is not within N/W/S/E
		cout << "\nPlease enter a valid answer!";

		//Return to ask for input from the player
		shootPlayer(newLocation);
	}
}

void Player::decreaseNoArrows() {

	noArrows = getNoArrows() - 1;
}

void Player::decreaseNoOils() {

	noOil = getNoOil() - 1;
}

void Player::runGame(Locations newLocation) {

	newLocation.displayCurrentData();

	//Check whether current location is safe or not and
	//Display hints whether hazards are close to player location
	//Go to the Check Current Location function
	checkCurrentLoc(newLocation);
}

void Player::checkCurrentLoc(Locations newLocation) {
	//Check whether the player has the same location as the pit
	if (getLocPointer(newLocation) == newLocation.getPit1Loc() || getLocPointer(newLocation) == newLocation.getPit2Loc()) {
		cout << " \nWHOOPS, You fell into a deep pit!" << endl;
		cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
		cout << "                  *** ###  ###  ###***					" << endl;
		cout << "              *##                      ##*				" << endl;
		cout << "            *##                           ##*			" << endl;
		cout << "          *##                               ##*		" << endl;
		cout << "        *##                                  ##*		" << endl;
		cout << "      *##                                      ##*		" << endl;
		cout << "     *##                                        ##*	" << endl;
		cout << "    *##                                          ##*	" << endl;
		cout << "   *##                                            ##*	" << endl;
		cout << "   *##                                            ##*	" << endl;
		cout << "   *##                                            ##*	" << endl;
		cout << "   *##                                            ##*	" << endl;
		cout << "   *##                                            ##*	" << endl;
		cout << "    *##                                          ##*	" << endl;
		cout << "     *##                                        ##*	" << endl;
		cout << "      *##                                      ##*		" << endl;
		cout << "       *##                                    ##*	 	" << endl;
		cout << "         *##                                ##*		" << endl;
		cout << "           *##                            ##*			" << endl;
		cout << "              *##                      ##*				" << endl;
		cout << "                 ***###  ###  ###  ***					" << endl;
		cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
		cout << " \nYou died!" << endl;

		//Hence, the player died from falling!
		//Wait for player
		waitForPlayer();
		//Go to quit game
		quitGame();
	}
	//If player location is the same as bat location
	else if (getLocPointer(newLocation) == newLocation.getBat1Loc() || getLocPointer(newLocation) == newLocation.getBat2Loc()) {
		cout << " \nYou encountered bats in the cave! " << endl;
		cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
		cout << "                 *         *      *         *                  " << endl;
		cout << "             ***          **********          ***              " << endl;
		cout << "          *****           **********           *****           " << endl;
		cout << "        *******           **********           *******         " << endl;
		cout << "      **********         ************         **********       " << endl;
		cout << "     ****************************************************      " << endl;
		cout << "    ******************************************************     " << endl;
		cout << "   ********************************************************    " << endl;
		cout << "   ********************************************************    " << endl;
		cout << "   ********************************************************    " << endl;
		cout << "    ******************************************************     " << endl;
		cout << "     ********      ************************      ********      " << endl;
		cout << "      *******       *      *********     *       *******       " << endl;
		cout << "        ******              *******             ******         " << endl;
		cout << "          *****              *****             *****           " << endl;
		cout << "            ***               ***             ***              " << endl;
		cout << "              **               *             **                " << endl;
		cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
		cout << " \nThe bats have moved you to a new cave " << endl;

		//Move the player location to a random location
		newLocation.setRandomLoc();

		//Go to Run Game function and display new cave information as well as checking
		runGame(newLocation);
	}
	//If player location is the same as Wumpus location
	else if (getLocPointer(newLocation) == newLocation.getWumpusLoc()) {
		cout << " \nOOPS! You stepped into the Wumpus Room" << endl;
		cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  " << endl;
		cout << "                  ,   .-'''=:_ ,						" << endl;
		cout << "                  |\.'-~`-.`-`;/|						" << endl;
		cout << "                 \.` '.'~- .` './						" << endl;
		cout << "                (\`,__ = -'__,' / )					" << endl;
		cout << "             _. - '-.( d\_/b ).-' - ._					" << endl;
		cout << "            /'.-'     ' .---. '    '-.`\ 				" << endl;
		cout << "          /'  .'  (=    (_)    = )  '.  `\ 			" << endl;
		cout << "         /'   .',  `-.__. - .__. - ' ,'.  `\           " << endl;
		cout << "       (    .'.      V       V      .'.    )           " << endl;
		cout << "       (    |::  `-, __. - .__, -'  ::|    )           " << endl;
		cout << "       |   /|`:.                   .:'|\   |           " << endl;
		cout << "       |  / | `:.                   :'|`\  |           " << endl;
		cout << "       | |  (:.                   .: ) | |             " << endl;
		cout << "       | |   (`:.                 :')   | |            " << endl;
		cout << "       | |    \ :                  :/    | |           " << endl;
		cout << "       | |     \`:               :'/     | |           " << endl;
		cout << "       ) (     `\`:.          .:'/'      ) (           " << endl;
		cout << "      (  `)_    )     `:._.:'   (     _(`  )			" << endl;
		cout << "       \  ' _) .'               `.    (_ ` /			" << endl;
		cout << "        \ '_) /     .'''```'''.   \  (_`  /			" << endl;
		cout << "         `''` \   (            )   /  '''`				" << endl;
		cout << "     ___       `. `.         .' .'         ___			" << endl;
		cout << "   .`    `''''''- - `_)      (_'--''''''``     `.		" << endl;
		cout << "   (_(_(___...--''''`           `''''--...___)_)_)     " << endl;
		cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  " << endl;
		cout << " \nThe WUMPUS ate you" << endl;
		cout << " You died" << endl;

		//Hence you die from the Wumpus
		//Wait for player
		waitForPlayer();
		//Go to quit game
		quitGame();
	}
	else {

		//Check whether location have any extra items
		if (getLocPointer(newLocation) == newLocation.getExtraArrow1() || getLocPointer(newLocation) == newLocation.getExtraArrow2()) {
			cout << "\nWOW! You got an extra arrow" << endl;
			noArrows++;
			if (getLocPointer(newLocation) == newLocation.getExtraArrow1()) {
				newLocation.setExtraArrow1(0);
			}
			else {
				newLocation.setExtraArrow2(0);
			}
		}
		if (getLocPointer(newLocation) == newLocation.getExtraOil1() || getLocPointer(newLocation) == newLocation.getExtraOil2()) {
			cout << "\nWOW! You got 5 extra oils" << endl;
			noOil = noOil + 5;
			if (getLocPointer(newLocation) == newLocation.getExtraOil1()) {
				newLocation.setExtraOil1(0);
			}
			else {
				newLocation.setExtraOil2(0);
			}
		}
		//Check adjacent location hazards and display hints 
		//If adjacent location has Wumpus in it
		if (newLocation.isRoomAdjacent(getLocPointer(newLocation) - 1, newLocation.getWumpusLoc() - 1)) {
			//Display hint
			cout << "\nYou see many big footsteps" << endl;
		}
		//If adjacent location has bats in it
		if (newLocation.isRoomAdjacent(getLocPointer(newLocation) - 1, newLocation.getBat1Loc() - 1) || newLocation.isRoomAdjacent(getLocPointer(newLocation) - 1, newLocation.getBat2Loc() - 1)) {
			//Display hint
			cout << "\nYou hear flapping noises" << endl;
		}
		//If adjacent location has pit in it
		if (newLocation.isRoomAdjacent(getLocPointer(newLocation) - 1, newLocation.getPit1Loc() - 1) || newLocation.isRoomAdjacent(getLocPointer(newLocation) - 1, newLocation.getPit2Loc() - 1)) {
			//Display hint
			cout << "\nYou feel a breeze" << endl;
		}
		//Go to In Game Options function
		gameOptions(newLocation);
	}
}

void Player::gameOptions(Locations newLocation) {
	string option;

	//Check number of arrow and mumber of oils
	if (noOil == 0) {
		cout << "\nYou ran out of oils!";
		cout << "\nYou die!" << endl;
		//Hence, you die!
		//Wait for player
		waitForPlayer();
		//Go to quit game
		quitGame();
	}
	if (noArrows == 0) {
		cout << "\nYou ran out of arrows!";
		cout << "\nYou die!" << endl;
		//Hence, you die!
		//Wait for player
		waitForPlayer();
		//Go to quit game
		quitGame();
	}

	//Display information of current number of arrow
	cout << "\nNo. of Arrows: " << getNoArrows() << endl;
	cout << "No. of Turns left (lantern): " << getNoOil() << endl;

	//Display options for the player to choose from
	cout << "\nPlease choose the following: " << endl;
	cout << "\n[N] for North";
	cout << "\n[S] for South";
	cout << "\n[W] for West";
	cout << "\n[E] for East";
	cout << "\n[shoot] for Shoot";
	cout << "\n[cheat] for Cheat";
	cout << "\n[help] for Help";
	cout << "\n[quit] for Quit (without save)" << endl;

	//Ask for player action
	cout << "\nWhat now: " << getPlayerName() << "?";
	cin >> option;

	cout << endl;

	//Since, there are options using few letters, I use if..else function rather than switch (can only do char)
	//Check whether option entered is valid
	if (option == "N" || option == "W" || option == "S" || option == "E") {
		//Set the 
		setPlayerMove(option);
		//Go to Move Loc function for moving to another cave
		movePlayer(newLocation);
	}
	else if (option == "shoot") {
		//Go to Shoot Loc function for shooting to another cave using available arrow
		shootPlayer(newLocation);
	}
	else if (option == "cheat") {
		//Get Hazard Location Details
		cout << getCheatDetails(newLocation) << endl;
		//Return to the In Game Options function
		return gameOptions(newLocation);
	}
	else if (option == "quit") {
		//Clear screen
		system("cls");
		//Quit without saving the game
		quitGame();
	}
	else if (option == "help") {
		//Display the rules of the game
		displayText("Rules.txt");
		//Return to the In Game Options function
		return runGame(newLocation);
	}
	else {
		//Option entered invalid
		cout << "Plese enter a valid option!" << endl;
		//Return to the In Game Options function
		return gameOptions(newLocation);
	}
}

void Player::checkWumpus(Locations newLocation) {
	//Check whether the location which the player shoot is the Wumpus location
	if (getPlayerShootRoom() == newLocation.getWumpusLoc()) {
		cout << "You killed the Wumpus!" << endl;
		cout << "\nCongrats!! You won the game!" << endl;
		string potion = displayPotion("Potion.txt");

		cout << "\nYou got " << potion;

		//Calculate, set, and display the player's final score
		setPlayerScore();
		cout << "\nYour score is : " << getPlayerScore();

		//Wait for Player
		waitForPlayer();
		//Go to quit game
		quitGame();
	}
	else {

		//Since the player shoot to the wrong location
		//75% chance the Wumpus will be awake and move its location
		//25% chance the Wumpus will stay in its place
		int b = rand() % 4 + 1;

		cout << "\nYou didn't shoot the Wumpus successfully" << endl;

		//Check whether random number will change the Wumpus location
		if (b == 4) {

			//The Wumpus did not change its location
			cout << "You are lucky! The Wumpus did not wake from its sleep!" << endl;
			cout << "The Wumpus did not hear your missed shot!" << endl;
		}
		else {
			//Move the location of the Wumpus to adjacent rooms
			newLocation.moveWumpusLoc();

			//Check wheter the new location is the same as the player's current location
			if (newLocation.getWumpusLoc() == getLocPointer(newLocation)) {

				//If yes, the player dies 
				cout << "\nThe Wumpus have moved to your cave!" << endl;
				cout << "YOU DIE!" << endl;

				//Wait for Player
				waitForPlayer();
				//Go to quit game
				quitGame();
			}

		}
		//Go to In Game Options Function
		gameOptions(newLocation);
	}
}

void Player::displayText(string myFileName) {
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
	cout << endl;
	system("pause");
	system("cls");
}

void Player::waitForPlayer() {
	cout << endl;
	system("pause");

	//Clear the screen
	system("cls");
}