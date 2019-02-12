#include <iostream>
#include<string>
#include "Number.h"
using namespace std;

Number::Number()
{

}


Number::Number(int n)
{
	if (n >= 0 && n <= 36)
	{
		value = n;
	}
}

bool Number::isEven()
{
	if (value % 2 == 0)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool Number::isLow()
{
	if (value < 19)
	{
		return true;
	}
	else if(value >18)
	{
		return false;
	}
}

string Number::toString()
{
	string s = "Value: ";
	string gou = "";
	string toh = "";

	if (value != 0) 
	{
		if (isEven())
		{
			gou += "Gerade";
		}
		else
		{
			gou += "Ungerade";
		}
		if (isLow())
		{
			toh += "tief";
		}
		else
		{
			toh += "hoch";
		}
		return s += to_string(value) + " " + gou + " " + toh;
	}
	else 
	{
		return s += to_string(value) + " ";
	}
	
	 
}

int Number::getValue() const
{
	return value;
}