////////////////////////////////////////////////////////////////////////
// OOP Tutorial: Simple C++ OO program to simulate a simple Dice Game (single file)
// Needs splitting into different modules
////////////////////////////////////////////////////////////////////////

//--------include libraries
#include <ctime>
#include <iostream>
#include <string>	
using namespace std;

//--------RandomNumberGenerator class
class RandomNumberGenerator {
public:
	RandomNumberGenerator();
	int getRandomValue(int) const;
private:
	void seed() const;
};
RandomNumberGenerator::RandomNumberGenerator() {
	seed();	//reset the random number generator from current system time
}
void RandomNumberGenerator::seed() const {
	srand(static_cast<unsigned int>(time(0)));
}
int RandomNumberGenerator::getRandomValue(int max) const {
	return (rand() % max) + 1; //produce a random number in range [1..max]
}
//--------end of RandomNumberGenerator class

//--------Dice class
class Dice {
public:
	Dice();
	int getFace() const;
	void roll();
private:
	int face_;		//number on dice
};
Dice::Dice() : face_(0)
{}
int Dice::getFace() const {
	return face_;	//get value of dice face
}
void Dice::roll() {
	static RandomNumberGenerator srng; 	//static local RandomNumberGenerator
	face_ = srng.getRandomValue(6); 	//roll dice
}
//--------end of Dice class

//--------Score class
class Score {
public:
	Score();
	int getAmount() const;
	void updateAmount(int);
private:
	int amount_;
};
Score::Score()
	: amount_(0)
{}
int Score::getAmount() const {
	return amount_;
}
void Score::updateAmount(int value) {
	//increment when value>0, decrement otherwise
	amount_ += value;
}
//--------end of Score class

//--------Player class
class Player {
public:
	string getName() const;
	int getScoreAmount() const;
	void readInName();
	int readInNumberOfGoes() const;
	void updateScore(int);
private:
	string name_;
	Score score_;
};
int Player::getScoreAmount() const {
	return score_.getAmount();
}
string Player::getName() const {
	return name_;
}
void Player::updateScore(int value) {
	score_.updateAmount(value);
}
int Player::readInNumberOfGoes() const {
	//ask the user for the number of dice throws
	int num;
	cout << "\nHow many goes do you want? ";
	cin >> num;
	return(num);
}
void Player::readInName() {
	//ask the user for his/her name
	cout << "\nEnter your name? ";
	cin >> name_;
}
//--------end of Player class

//--------Game class
class Game {
public:
	explicit Game(Player* pplayer);
	void displayData() const;
	void run();
private:
	Player* p_player_;
	Dice firstDice_, secondDice_;
	int numberOfGoes_;
	void rollDices();
};
Game::Game(Player* pplayer)
	: p_player_(pplayer), firstDice_(), secondDice_(), numberOfGoes_(0)
{
	p_player_->readInName();
	numberOfGoes_ = p_player_->readInNumberOfGoes();
}
void Game::displayData() const {
	cout << "\nPlayer is: " << p_player_->getName();
	cout << "\nScore is: " << p_player_->getScoreAmount() << endl;
}
void Game::run() {
	for (int i(1); i <= numberOfGoes_; ++i)
	{
		rollDices();
		const int face1(firstDice_.getFace());
		const int face2(secondDice_.getFace());
		cout << "\nIn try no: " << i << " \tdice values are: "
			<< face1 << " and " << face2;
		if ((face1 == face2) && (face1 == 6))
			p_player_->updateScore(p_player_->getScoreAmount());
		else
			if (face1 == face2)
				p_player_->updateScore(face1);
		//check current score
		cout << "\tThe current score is: " << p_player_->getScoreAmount();
	}
}
void Game::rollDices() {
	firstDice_.roll();
	secondDice_.roll();
}
//--------end of Game class

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
