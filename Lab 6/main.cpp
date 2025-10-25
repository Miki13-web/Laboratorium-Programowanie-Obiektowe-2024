/*
	autor Miko³aj Bednarczyk
*/
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Punkt
{
private:
	int x;
	int y;

public:
	Punkt() {
		x = 0, y = 0;
		//cout << "Punkt utworzony" << endl; 
	}
	Punkt(int X, int Y) : x(X), y(Y) {
		//cout << "Punkt utworzony" << endl; 
	}

	int getX() { return x; }
	void setX(int X) { x = X; }
	int getY() { return y; }
	void setY(int Y) { y = Y; }

	friend class Kwadrat;
	friend void Wypisz(Punkt);
};

class Kwadrat
{
private:
	Punkt P_przek;
	Punkt K_przek;

public:
	Kwadrat(Punkt PP, Punkt KP) : P_przek(PP), K_przek(KP) {
		cout << "Kwadrat utworzony" << endl;
	}
	double poleKwadratu()
	{
		double przekatna = sqrt(pow(P_przek.x - K_przek.x, 2) + pow(P_przek.y - K_przek.y, 2));
		double pole = pow(przekatna, 2) / 2;
		return pole;
	}
	friend void Wypisz(Kwadrat);
};

class Okrag
{
private:
	Punkt srodek;
	int promien;

public:
	Okrag() { srodek; promien = 0; }
	Okrag(Punkt S, int R)
	{
		srodek = S;
		promien = R;
	}

	void stworzOkrag(Punkt S, int R)
	{
		srodek = S;
		promien = R;
	}

	void rozlacznosi(Okrag tab[])
	{
		int licznik_zew = 0, licznik_wew = 0;
		for (int i = 0; i < 500; i++)
		{
			int odleglosc_srodkow = sqrt(pow(srodek.getX() - tab[i].srodek.getX(), 2) + pow(srodek.getY() - tab[i].srodek.getY(), 2));
			if (odleglosc_srodkow < abs(tab[i].promien - promien))
			{
				licznik_wew++;
			}
			if (odleglosc_srodkow > tab[i].promien + promien)
			{
				licznik_zew++;
			}
		}
		cout << "Okrag jest rozlaczny wewnetrznie z: " << licznik_wew << endl;
		cout << "Okrag jest rozlaczny zewnetrznie z: " << licznik_zew << endl;
	}

	friend void Wypisz(Okrag);
};

void Wypisz(Punkt punkt)
{
	cout << "\nPunkt: " << endl;
	cout << "Wpolrzedne x = " << punkt.x << " y = " << punkt.y << endl;
}

void Wypisz(Okrag okrag)
{
	cout << "\nOkrag: " << endl;
	cout << "Wpolrzedne srodka okregu ";
	Wypisz(okrag.srodek);
	cout << "Promien okregu r = " << okrag.promien << endl;
}

void Wypisz(Kwadrat kwadrat)
{
	cout << "\nKwadrat: " << endl;
	cout << "Poczatek przekatnej: ";
	Wypisz(kwadrat.P_przek);
	cout << "Koniec przekatnej: ";
	Wypisz(kwadrat.K_przek);
}

int main()
{
	int i;
	srand(time(NULL));
	// Zadanie A)
	//==================================================================
	cout << "Podpunkt A) \n" << endl;

	cout << "Inicjalizowanie tablicy kwadratow\n" << endl;
	Kwadrat tab[2] = { {{0,0}, {3,3}}, {{-8,8}, {-1,1}} };

	// Zadanie B)
	//==================================================================
	cout << "\nPodpunkt B) \n" << endl;

	cout << "Pole kwadratu nr 1 wynosi P = " << tab[0].poleKwadratu() << endl;
	cout << "Pole kwadratu nr 2 wynosi P = " << tab[1].poleKwadratu() << endl;

	// Zadanie C)
	//==================================================================
	cout << "\nPodpunkt C) \n" << endl;

	cout << "Tworzenie pierwszego okregu" << endl;
	Okrag okr1({ 10,10 }, 5);

	cout << "Tworzenie tablicy okregow" << endl;
	Okrag Tab[500];
	for (i = 0; i < 500; i++)
	{
		int x = rand() % 30 - 10;
		int y = rand() % 20;
		int r = rand() % 5 + 1;
		Tab[i].stworzOkrag({ x,y }, r);
	}

	// Zadanie D)
	//==================================================================
	cout << "\nPodpunkt D) \n" << endl;

	okr1.rozlacznosi(Tab);

	// Zadanie E)
	//==================================================================
	cout << "\nPodpunkt E) \n" << endl;

	Wypisz(tab[1]);
	Wypisz(Tab[9]);

	return 0;
}


