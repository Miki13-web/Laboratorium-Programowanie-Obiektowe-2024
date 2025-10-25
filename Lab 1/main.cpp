/*
	autor Miko³aj Bednarczyk
*/ 


#include <iostream>
#include <string>

using namespace std;

#define N 100

// Zadanie 2 funkcja
void funkcja(int T[])
{
	for (int i = 0; i < 4; i++)
	{
		T[i] *= 2;
	}
}

// Zadanie 3 struktura
typedef struct Batonik
{
	string marka;
	float waga;
	int l_kalorii;
};


int main()
{
	// Zadanie 1
	//==================================================================
	cout << "Zadanie 1 \n";

	int T[N];
	int* wsk;

	for (int i = 0; i < N; i++)
	{
		T[i] = i;
	}

	if (T[9] % 2 == 0)
	{
		cout << "Dziesiaty element jest podzielny przez 2\n";
	}
	else
	{
		cout << "Dziesiaty element NIE jest podzielny przez 2 \n";
	}

	wsk = &T[10];

	cout << "Jedenasty element tablicy to: " << *wsk << endl;

	//	Wypisanie tablicy dla sprawdzenia

	//	for (int i = 0; i < N; i++)
	//	{
	//		cout << T[i] << endl;
	//	}

		// Zadanie 2
		//==================================================================
	cout << "\nZadanie 2 \n";

	int T2[4];

	for (int i = 0; i < 4; i++)
	{
		cin >> T[i];
	}

	funkcja(T);

	for (int i = 0; i < 4; i++)
	{
		cout << T[i] << " ";
	}
	cout << endl;

	// Zadanie 3
	//==================================================================
	cout << "\nZadanie 3 \n";

	Batonik snack;

	snack.marka = "Bounty";
	snack.waga = 57;
	snack.l_kalorii = 278;

	cout << "Marka: " << snack.marka << "\nwaga: " << snack.waga << "\nliczba kalorii: " << snack.l_kalorii << endl;

	return 0;
}
