#include <iostream>
#include<math.h>  
using namespace std;

bool isPrime(int entier)
{
	for (int divider = 2; divider <= sqrt(entier); divider++)
	{
		if ((entier % divider) == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	while (true)
	{
		int number;
		int nextPrime;
		cout << "Entrez un nombre entier : ";
		cin >> number;
		if (number == -1)
		{
			break;
		}
		nextPrime = (number + 1);
		while (!(isPrime(nextPrime)))
		{
			nextPrime++;
		}
		cout << "Le prochain nombre premier est : " << nextPrime << "\n\r";
	}
}