#include <iostream>
#include <string>
#include <random>
#include "Roulette.h"
using namespace std;

Roulette::Roulette(int boa)
{
	for (int i = 0; i < nrP; i++)
	{
		players[i].setBudget(boa);
		players[i].setId(i);
	}

	for (int i = 0; i < nrN; i++)
	{
		roulette[i] = Number(i);
	}
}

void Roulette::makeBets()
{
	for (int i = 0; i < nrP; i++)
	{
		switch (i)
		{
		case 0:
			players[i].setWhichBet('g');
			break;
		case 1:
			players[i].setWhichBet('t');
			break;
		case 2:
			players[i].setWhichBet('z');
			players[i].setNumber(23);
			break;
		case 3:
			players[i].setWhichBet('z');
			players[i].setNumber( 1+ rand() % 36);
			break;
		default:
			break;
		}
		players[i].setMoneyBet(100);
		players[i].takeFromBudget(100);
	}
}

void Roulette::play()
{
	Number ri = rand() % 36;
	for (Player p : players)
	{
		switch (p.getWhichBet())
		{
		case 'g':
			if ('g' == ri.isEven())
			{
				p.setBudget(2 * p.getMoneyBet());
			}
			else
			{
				p.takeFromBudget(p.getMoneyBet());
			}
			break;
		case 'u':
			if ('u' == ri.isLow())
			{
				p.setBudget(2 * p.getMoneyBet());
			}
			else
			{
				p.takeFromBudget(p.getMoneyBet());
			}
			break;
		case 'z':
			if ('z' == ri.getValue())
			{
				p.setBudget(36 * p.getMoneyBet());
			}
			else
			{
				p.takeFromBudget(p.getMoneyBet());
			}
			break;
		default:
			break;
		}
		if (p.getBudget() == 0)
		{
			p.setPlaying(false);
		}

	}
}

void Roulette::sort()
{
	for (int i = 0; i < nrP; i++)
	{
		for (int j = 0; j < nrP; j++)
		{
			if (players[j].getBudget() < players[(j + 1)%4].getBudget()) {
				Player p = players[j];
				players[j] = players[j + 1];
				players[j + 1] = p;
			}
		}
	}
}

string Roulette::showPlayers() const
{
	string s = "";
	for (int i = 0; i < nrP; i++)
	{
		s += "ID of Player " + to_string(i) + ": " + to_string(players[i].getId()) + "\n";
		s += "Budget of Player " + to_string(i) + ": " + to_string(players[i].getBudget())+ " ";
	}
	return s;
}

string Roulette::showNumbers() const
{
	string s = "Numbers: ";
	for (Number x : roulette)
	{
		s += x.toString() + "\t";
	}
	return s;
}

ostream& operator <<(ostream& out, const Roulette & R)
{
	out << R.showPlayers() << "\n" << R.showNumbers() << endl;
	return out;
}