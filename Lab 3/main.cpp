/*
	autor Miko³aj Bednarczyk
*/
#include <iostream>
#include <string>

using namespace std;

class Zwierze
{
private:
	string nazwa;
	int masa;
	static int licznik;

public:

	Zwierze(string name1 = "Brak", int masa1 = 0)
	{
		licznik++;
		cout << "Obiekt zostal stworzony\n";
		nazwa = name1;
		masa = masa1;
	}

	~Zwierze()
	{
		cout << "Obiekt zostal usuniety \n";
		licznik--;
	}

	void setNazwa(string name)
	{
		nazwa = name;
	}
	void setMasa(int mass)
	{
		masa = mass;
	}

	string getNazwa()
	{
		return nazwa;
	}
	int getMasa()
	{
		return masa;
	}
	int getLicznik()
	{
		return licznik;
	}

	bool czyCiezsze(int x)
	{
		if (masa > x)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
};
int Zwierze::licznik = 0;

string zwierze_wiecej_liter(Zwierze* tab)
{
	int l_elementow = 2;
	string s1, s2;

	for (int i = 0; i < l_elementow - 1; i++)
	{
		s1 = tab[i].getNazwa();
		s2 = tab[i + 1].getNazwa();

		if (s1.length() > s2.length())
		{
			return s1;
		}
		else
		{
			return s2;
		}
	}
}

int main()
{
	// Zadanie A)
	//==================================================================
	cout << "Podpunkt A) \n";

	Zwierze z1;
	cout << "Zwierze 1: " << z1.getNazwa() << " " << z1.getMasa() << endl;

	Zwierze* tablica = new Zwierze[2];

	tablica[0].setNazwa("Orangutan");
	tablica[0].setMasa(390);

	cout << "Zwierze 2: " << tablica[0].getNazwa() << " " << tablica[0].getMasa() << endl;

	tablica[1].setNazwa("Slon");
	tablica[1].setMasa(2900);

	cout << "Zwierze 3: " << tablica[1].getNazwa() << " " << tablica[1].getMasa() << endl;

	// Zadanie B)
	//==================================================================
	cout << "\nPodpunkt B) \n";

	if (tablica[1].czyCiezsze(400) == 1)
	{
		cout << "Zwierze nr 3 Jest ciezsze niz 400" << endl;
	}
	else
	{
		cout << "Zwierze nr 3 NIE Jest ciezsze niz 400" << endl;
	}

	// Zadanie C)
	//==================================================================
	cout << "\nPodpunkt C) \n";

	cout << "Porownujac dwa zwierzeta nasze elementy tablicy, dluzsza nazwe ma zwierze: " << zwierze_wiecej_liter(tablica) << endl;

	// Zadanie D)
	//==================================================================
	cout << "\nPodpunkt D) \n";

	delete[] tablica;
	//cout << "Licznik: " << get.licznik;

	return 0;
}