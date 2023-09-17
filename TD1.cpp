#include <iostream>
#include <cmath>
#include <random>
#include <array>
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

void exercice1()
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
		cout << "Le prochain nombre premier est : " << nextPrime << "\n";
	}
}

int validateNumber(string questionText, float min, float max)
{
	while (true)
	{
		int userInput;
		cout << questionText;
		cin >> userInput;
		if (userInput >= min && userInput <= max)
		{
			return userInput;
		}
	}
}

void exercice2()
{
	const int NOMBRE_MAX = 1000;
	default_randome_engine randNum(random_device{}());
	int number = randNum() % (NOMBRE_MAX + 1);
	int guess;
	int count = 0;
	while (true)
	{
		guess = validateNumber("Entrez un nombre entier : ", 0, NOMBRE_MAX);
		count++;
		if (guess == number)
		{
			cout << "Bravo! Vous avez réussi en " << count << " tentatives \n";
			break;
		}
		else
		{
			if (guess > number)
			{
				cout << "Trop haut. \n";
			}
			else
			{
				cout << "Trop bas. \n";
			}
		}
	}
}


void exercice3()
{
	const int VITESSE_MAX = 100;
	const int VITESSE_MIN = -100;
	int time = validateNumber("Entrez le temps total : ", 0, INFINITY);
	int posTrain1 = validateNumber("Entrez la position initiale du premier train : ", -INFINITY, INFINITY);
	int velTrain1 = validateNumber("Entrez la vitesse initiale du premier train : ", VITESSE_MIN, VITESSE_MAX);
	int posTrain2 = validateNumber("Entrez la position initiale du second train : ", -INFINITY, INFINITY);
	int velTrain2 = validateNumber("Entrez la vitesse initiale du second train : ", VITESSE_MIN, VITESSE_MAX);
	bool isTrain1FartherThanTrain2;
	bool isThereCollision = false;
	for (int seconds = 1; seconds <= time; seconds++)
	{
		cout << "Après " << seconds << " seconde(s) : \n";
		isTrain1FartherThanTrain2 = posTrain1 >= posTrain2;
		posTrain1 += velTrain1;
		posTrain2 += velTrain2;
		cout << "Train 1 : " << posTrain1 << "\n";
		cout << "Train 2 : " << posTrain2 << "\n";
		if ((posTrain1 >= posTrain2) != isTrain1FartherThanTrain2)
		{
			cout << "Il y a eu une collision à la " << seconds << "e seconde! \n";
			isThereCollision = true;
			break;
		}
	}
	if (!(isThereCollision))
	{
		cout << "Il n'y a pas eu de collision après" << time << "seconde(s) \n";
	}
}

void exercice4()
{
	const int TAILLE(10);

	array<int, TAILLE> tableau;

	//Lecture des éléments du tableau

	cout << "Entrez " << TAILLE << " nombres entiers : ";

	for (int i(0); i < tableau.size(); ++i) {
		cin >> tableau[i];
	}

	// Tri du tableau
	int positionMinimum;
	int temp;

	for (int i(0); i < tableau.size(); ++i) {
		positionMinimum = i;
		for (int j(i + 1); j < tableau.size(); ++j) {
			if (tableau[j] < tableau[positionMinimum]) {
				positionMinimum = j;
			}

		}
		if (positionMinimum != i) {
			temp = tableau[i];
			tableau[i] = tableau[positionMinimum];
			tableau[positionMinimum] = temp;
		}

	}

	// Affichage du tableau
	cout << "Voici le tableau trié : ";
	for (int i(0); i < tableau.size(); ++i) {
		cout << tableau[i] << " ";
	}
	cout << endl;

	return 0;
}

void exercice5();
{

}

int main()
{
	exercice1();
	exercice2();
	exercice3();
	exercice4();
	exercice5();
	return 0;
}