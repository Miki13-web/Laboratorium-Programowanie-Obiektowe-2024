/*
	autor Miko³aj Bednarczyk
*/
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Przedmiot
{
private:
	string nazwa;
	int atak;
	int obrona = rand() % 100 + 20;

public:
	Przedmiot() {
		nazwa = "Defaultowy pancerz";
		atak = 1;
		obrona = rand() % 100 + 20;;
	}
	Przedmiot(string Nazwa, int Atak, int Obrona) {
		nazwa = Nazwa;
		atak = Atak;
		obrona = Obrona;
	}
	Przedmiot(const Przedmiot& przedmiot, int Obrona) {
		nazwa = przedmiot.nazwa;
		atak = przedmiot.atak;
		obrona = Obrona;
	}
	void setNazwa(string name) { nazwa = name; }
	string getNazwa() { return nazwa; }
	void setAtak(int attack) { atak = attack; }
	int getAtak() { return atak; }
	void setObrona(int defence) { obrona = defence; }
	int getObrona() { return obrona; }

	void wyswietlPrzedmiot() {
		cout << "Nazwa: " << nazwa << endl;
		cout << "Atak: " << atak << endl;
		cout << "Obrona: " << obrona << endl;
	}
};

class Bohater
{
private:
	string imie;
	string klasa;
	int punkty_hp;
	Przedmiot* ekwipunek[3] = {};
	static int licznik_przedmiotow;

public:
	void setImie(string name1) { imie = name1; }
	string getImie() { return imie; }
	void setKlasa(string class1) { klasa = class1; }
	string getKlasa() { return klasa; }
	void setPunkty(int punkty) { punkty_hp = punkty; }
	int getPunkty() { return punkty_hp; }

	Bohater() {
		imie = "Domyslne";
		klasa = "Domyslna";
		punkty_hp = 1000;
	}
	Bohater(string IMIE, string KLASA) {
		imie = IMIE;
		klasa = KLASA;
		punkty_hp = 1000;
	}
	Bohater(const Bohater& postac) {
		imie = postac.imie;
		klasa = postac.klasa;
		punkty_hp = postac.punkty_hp;
		for (int i = 0; i < 3; i++)
		{
			ekwipunek[i] = new Przedmiot(*postac.ekwipunek[i]);
		}
	}

	void setEkwipunek(Przedmiot* p1)
	{
		ekwipunek[licznik_przedmiotow] = p1;
		licznik_przedmiotow++;
	}

	void usunPrzedmiot(string Nazwa) {
		for (int i = 0; i < 3; i++)
		{
			if ((*ekwipunek[i]).getNazwa() == Nazwa)
			{
				ekwipunek[i] = nullptr;
				licznik_przedmiotow--;
			}
		}
	}

	string zwrocNajwiekszaObrona()
	{
		int najwieksza = ekwipunek[0]->getObrona();
		int nr = 0;
		for (int i = 1; i < 3; i++)
		{
			if (ekwipunek[i]->getObrona() > najwieksza)
			{
				najwieksza = ekwipunek[i]->getObrona();
				nr = i;
			}
		}
		return ekwipunek[nr]->getNazwa();
	}

	void wyswietlBohatera()
	{
		cout << "Imie: " << imie << endl;
		cout << "Klasa: " << klasa << endl;
		cout << "Punkty zdrowia: " << punkty_hp << endl;
		cout << "Ekwipunek: " << endl << ekwipunek[0]->getNazwa() << endl;
		cout << (*ekwipunek[1]).getNazwa() << endl;
		cout << ekwipunek[2]->getNazwa() << endl;
	}
};
int Bohater::licznik_przedmiotow = 0;

int main()
{
	srand(time(NULL));
	int wart;

	// Zadanie A)
	//==================================================================
	cout << "Podpunkt A) \n" << endl;

	Przedmiot przed1;
	cout << "Przedmiot 1" << endl;
	przed1.wyswietlPrzedmiot();

	Przedmiot* przed2;
	przed2 = new Przedmiot("miecz", 130, 27);
	cout << "\nPrzedmiot 2" << endl;
	przed2->wyswietlPrzedmiot();

	cout << "\nPodaj nowa wartosc obrony dla przedmiotu nr 3" << endl;
	cin >> wart;
	Przedmiot przed3(*przed2, wart);
	cout << "Przedmiot 3" << endl;
	przed3.wyswietlPrzedmiot();

	// Zadanie B)
	//==================================================================
	cout << "\nPodpunkt B) \n" << endl;

	Przedmiot tab[2];
	tab[0].setAtak(55);
	tab[0].setObrona(90);
	tab[0].setNazwa("Zbroja Geralta");

	tab[1].setAtak(2);
	tab[1].setObrona(30);
	tab[1].setNazwa("Helm Lokiego");

	cout << "Tablica dwuelementowa przedmiotow " << endl;
	tab[0].wyswietlPrzedmiot();
	cout << endl;
	tab[1].wyswietlPrzedmiot();

	// Zadanie C)
	//==================================================================
	cout << "\nPodpunkt C) \n" << endl;

	cout << "Bohater 1: \n";
	Bohater bohater1("Geralt", "Rzeznik");
	bohater1.setEkwipunek(&przed1);
	bohater1.setEkwipunek(przed2);
	bohater1.setEkwipunek(&przed3);
	bohater1.wyswietlBohatera();

	// Zadanie D)
	//==================================================================
	cout << "\nPodpunkt D) \n" << endl;

	cout << "Bohater 2: \n";
	Bohater bohater2(bohater1);
	bohater2.setImie("Gaunter o'Dim");
	bohater2.setKlasa("Diabel");
	bohater2.usunPrzedmiot("miecz");
	bohater2.setEkwipunek(tab);
	bohater2.setEkwipunek(tab + 1);

	bohater2.wyswietlBohatera();


	// Zadanie E)
	//==================================================================
	cout << "\nPodpunkt E) \n" << endl;

	cout << "Bohater nr 1 najwieksza obrona: " << endl;
	cout << bohater1.zwrocNajwiekszaObrona() << endl;
	cout << "Bohater nr 2 najwieksza obrona: " << endl;
	cout << bohater2.zwrocNajwiekszaObrona() << endl;

	return 0;
}