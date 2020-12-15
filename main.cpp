/* Skyy Civil
C++ Legend Game
*/
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
/* No files, struct instead.

structing monsters and hero and damage
*/
struct Monster{
	int monsterCount;
	string monsterType;
	int monsterHealth;
	
};
// Hero
struct Hero{
	
	int XP;
	int coins;
	int level;
	int health;
	void gainXP(int);
};


struct Attacks{
	string attack1;
	string attack2;
	string attack3;
	string attack4;
	int damageAttack1;
	int damageAttack2;
	int damageAttack3;
	int damageAttack4;
};

/*
		The actual level starts here
*/


void LevelStart(){
	int playerAttack;
		struct Hero player;
	struct Attacks playerAttacks;
	struct Attacks monsterAttacks;
	struct Monster easyLevelMonster;
	// Player attacks and stats
	
	player.health = 150;
	playerAttacks.attack1 = "FireBall";
	playerAttacks.attack2 = "Fire Slash";
	playerAttacks.attack3 = "Fire Barrage";
	playerAttacks.attack4 = "Blue Flame Bomb";
	playerAttacks.damageAttack1 = 4;
	playerAttacks.damageAttack2 = 9;
	playerAttacks.damageAttack3 = 14;
	playerAttacks.damageAttack4 = 19;
	// Monster attacks and stats
	easyLevelMonster.monsterCount = 1;
	easyLevelMonster.monsterType = "monster";
	easyLevelMonster.monsterHealth = 100;
	monsterAttacks.attack1 = "bash";
	monsterAttacks.damageAttack1 = 10;
// -----------------MAKING ATTACKS---------------------\\

	cout << "Monsters: " << easyLevelMonster.monsterCount;
	cout << "\n\n Monster type: " << easyLevelMonster.monsterType;
	cout << "\n\n (1) " << playerAttacks.attack1;
	cout << "\n\n (2) " << playerAttacks.attack2;
	cout << "\n\n (3) " << playerAttacks.attack3;
	cout << "\n\n (4) " << playerAttacks.attack4;
	cout << "\n > ";
	cin >> playerAttack;
	
}





void Hero::gainXP(int xp)
{
    this->XP += xp;
    if(this->XP > 100) //Change 100 to the amount of XP it needs to level up.
    {
        this->XP -= 100;
        this->level++;
    }
}

/*
Game menu includes options for the player to choose to play the game
*/

void GameMenu(string username, string password){
	struct Attacks sword;
	struct Hero player;
	string gameMenuChoice;

	
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "~~~~~~~+~~~~~~~LEGEND!~~~~~~~+~~~~~~~\n\n\n\n";
	cout << username << "\n\n";
	cout << "XP: " << player.XP;
	
	cout << "Level: " << player.level << "\n\n\n\n\n\n";
	cout << "XP: " << player.XP << "\n\n\n\n";
	cout << "(a) Play Level\n";
	cout << "(b) Exit\n";
	cin >> gameMenuChoice;
	if(gameMenuChoice == "a"){
		LevelStart();
	}
	if(gameMenuChoice == "b"){
		cout << "Game EXITED\n";
	
	}
}


void Login(){
	int loginChoice;
	string username;
	string password;
	fstream login;
	login.open("login.dat", ios::in | ios::out);
	cout << "Username\n";
	cout << "\n > ";
	cin >> username;
	login << "Username: " << username << endl;
	cout << "\n\n\n Password\n";
	cout << "\n > ";
	cin >> password;
	login << "Pass: " << password << endl;
	login.close();
	cout << "loading...\n\n\n";
	cout << "(1) Start\n";
	cin >> loginChoice;
	if(loginChoice == 1){
		GameMenu(username, password);
	}
}

// StoryMode

void StoryMode(void){
	int storyModeChoice;
	cout << "Welcome to story mode!\n\n";
	cout << "(1) Login\n";
	cin >> storyModeChoice;
	if(storyModeChoice == 1){
		Login();
	}
}

// Credits
void Credits(){
	
	int creditsChoice;
	cout << "Creator: Skyy Civil\n\n\n\n";
	cout << "(1) Back to menu\n";
	cout << "(2)Continue to story mode\n";
	cin >> creditsChoice;
	if(creditsChoice == 1){
		void Menu();
	}
	if (creditsChoice == 2){
		StoryMode();
	}
}

// Main Menu

void Menu(){
	int menuChoice;
	cout << "\nLegend\n";
	cout << "(1)Story Mode\n";
	cout << "(2) Credits\n";
	cin >> menuChoice;
	if(menuChoice == 1){
		StoryMode();
	}
	if(menuChoice == 2){
		Credits();
	}
};

// ------------MAIN--------------- \\

int main(void){
	Menu();
}
