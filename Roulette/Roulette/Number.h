#pragma once
#include <iostream>

class Number
{
public:
	Number();
	Number(int);
	bool isEven();
	bool isLow();
	std::string toString();
	int getValue() const;

private:
	int value;
};