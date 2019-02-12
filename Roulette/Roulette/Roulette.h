#pragma once
#include "Player.h"
#include "Number.h"
#include <iostream>
#include<array>

static const int nrP = 4;
static const int nrN = 37;

class Roulette
{
	friend std::ostream & operator <<(std::ostream &, const Roulette &);

public:
	Roulette(int);
	void makeBets();
	void play();
	void sort();
	std::string showPlayers() const;
	std::string showNumbers() const;

private:
	std::array<Player, nrP> players;
	std::array<Number, nrN> roulette;
};