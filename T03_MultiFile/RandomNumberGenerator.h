#pragma once
#include <ctime>
#include <iostream>


class RandomNumberGenerator {
public:
	RandomNumberGenerator();
	int getRandomValue(int) const;
private:
	void seed() const;
};


