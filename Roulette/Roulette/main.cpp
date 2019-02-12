#include <iostream>
#include <time.h>
#include "Roulette.h"

using namespace std;

int main()
{
	srand(time(NULL));
	Roulette g1(1000);

	 g1.showNumbers();


	for (int i = 0; i < 2; i++)
	{
		g1.play();
		g1.sort();			//tst
		
	}
	cout << g1;
/*	Roulette g2(10000);

	for (int i = 0; i < 100; i++)
	{
		g2.play();

		if(i == 99)
		{
			cout <<g2;
		}
	}
	Roulette g3(10000);
	
	for (int i = 0; i < 1000; i++)
	{
		g3;

		if (i == 999)
		{
			g3.sort();
			 cout << g3;
		}
	}*/

	
}