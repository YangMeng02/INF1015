#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	while (true)
	{
		int number = rand() % 1001;
		int guess;
		int count = 0;
		while (true)
		{
			cout << "Devine le nombre de 0 à 1000 : ";
			cin >> guess;
			count++;
			if (guess == -1)
			{
				break;
			}
			if (guess == number)
			{
				cout << "Bravo! Tu as trouvé le chiffre après " << count << " essais \n";
				break;
			}
			else
			{
				if (guess > number)
				{
					cout << "Essaie plus bas! \n";
				}
				else
				{
					cout << "Essaie plus haut! \n";
				}
			}
		}
	}
}