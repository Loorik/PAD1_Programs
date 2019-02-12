#include <iostream>
#include "Player.h"
using namespace std;

Player::Player()
{

}

Player::Player(int i, int bud)
	: id(i), budget(bud), playing(true)
{

}

bool Player::takeFromBudget(int b)
{
	if (budget - b >= 0)
	{
		budget -= b;
		return true;
	}
	else
	{
		return false;
	}
}

void Player::setBudget(int b)
{
	budget = b;
}

void Player::setId(int i)
{
	id = i;
}
int Player::getId() const
{
	return id;
}

int Player::getBudget() const
{
	return budget;
}

void Player::setWhichBet(char c)
{
	whichBet = c;
}

void Player::setMoneyBet(int b)
{
	moneyBet = b;
}

char Player::getWhichBet() const
{
	return whichBet;
}

void Player::setNumber(Number n)
{
	number = n;
}
int Player::getMoneyBet() const
{
	return moneyBet;
}

void Player::setPlaying(bool p)
{
	playing = p;
}

bool Player::operator<(const Player& p) const
{
	return budget < p.getBudget();
}