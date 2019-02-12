#pragma once
#include <iostream>
#include "Number.h"

class Player
{
public: 
	Player();
	Player(int, int);
	bool takeFromBudget(int);
	void setBudget(int);
	void setId(int);
	int getId() const;
	int getBudget() const;
	char getWhichBet() const;
	void setWhichBet(char);
	int getMoneyBet() const;
	void setMoneyBet(int);
	void setNumber(Number);
	void setPlaying(bool);
	bool operator<(const Player &) const;

private:
	int id;
	char whichBet;
	Number number;
	int budget;
	int moneyBet;
	bool playing;
};