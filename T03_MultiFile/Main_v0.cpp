////////////////////////////////////////////////////////////////////////
// OOP Tutorial: Simple C++ OO program to simulate a simple Dice Game (single file)
// Needs splitting into different modules
////////////////////////////////////////////////////////////////////////

//--------include libraries

#include "Game.h"

using namespace std;


//---------------------------------------------------------------------------
//with two dices
int main()
{
	Player player;
	Game twoDiceGame(&player);
	cout << "\n________________________";
	cout << "\nGame starting...";
	twoDiceGame.displayData();
	cout << "\n________________________";
	twoDiceGame.run();
	cout << "\n________________________";
	cout << "\nGame ended...";
	twoDiceGame.displayData();
	cout << "\n________________________\n";

	system("pause");
	return 0;
}
