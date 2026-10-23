#include "Player.h"
using namespace std;

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