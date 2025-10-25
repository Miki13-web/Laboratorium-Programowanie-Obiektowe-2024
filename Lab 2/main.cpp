/*
	autor Miko³aj Bednarczyk
*/
#include <iostream>
#include <string>

using namespace std;

class Pasazer
{
private:
	string imie;
	string nazwisko;
	int wiek;

public:
	//Pasazer::Pasazer(string = "brak", string = "brak", int = 0);

	void setImie(string vorname) { imie = vorname; }
	string getImie() { return imie; }
	void setNazwisko(string name) { nazwisko = name; }
	string getNazwisko() { return nazwisko; }
	void setWiek(int age) { wiek = age; }
	int getWiek() { return wiek; }
};

class Autokar
{
private:
	string miejsce_docelowe;
	static const int ilosc_miejsc = 10;
	Pasazer tab[ilosc_miejsc];
	int licznik = 0;

public:
	void wypisz() { cout << "\nMiejsce docelowe: " << miejsce_docelowe << endl << "Ilosc miejsc: " << ilosc_miejsc << endl; for (int i = 0; i < ilosc_miejsc; i++) { cout << tab[i].getImie() << " " << tab[i].getNazwisko() << " " << tab[i].getWiek() << endl; }; }
	void dodajPasazera(Pasazer tablica[]) { if (licznik < 10) { tab[licznik].setImie(tablica[licznik].getImie()); tab[licznik].setNazwisko(tablica[licznik].getNazwisko()); tab[licznik].setWiek(tablica[licznik].getWiek()); licznik++; }; }
	void zmienWiek() { int age, n; cout << "\nPodaj nr pasazera od 1 do 10:"; cin >> n; cout << "Podaj nowy wiek: "; cin >> age; tab[n - 1].setWiek(age); }

	void setMiejsce_docelowe(string place) { miejsce_docelowe = place; }
	string getMiejsce_docelowe() { return miejsce_docelowe; }
	int getIlosc_miejsc() { return ilosc_miejsc; }
};


int main()
{

	//========================================
	//podpunkt A)
	cout << "Podpunkt A" << endl;
	Pasazer p1;
	p1.setImie("Jakub");
	p1.setNazwisko("Bednarczyk");
	p1.setWiek(22);
	cout << "Nazwisko pasazera: " << p1.getNazwisko() << endl;

	//==================================================
	// Podpunkt B)
	cout << "\nPodpunkt B)" << endl << "Stworzono tablice, nic nie trzeba bylo wypisywac" << endl;
	Pasazer* tablica = new Pasazer[200];

	for (int i = 0; i < 200; i++)
	{
		tablica[i].setImie("Kubus");
		tablica[i].setNazwisko("Baranowski");
		tablica[i].setWiek(i);
	}

	//Wypisanie dla sprawdzenia
	/*cout << "\nPodpunkt B)" << endl;
	for (int i = 0; i < 200; i++)
	{
		cout << tablica[i].getImie() << endl;
		cout << tablica[i].getNazwisko() << endl;
		cout << tablica[i].getWiek() << endl;
	}
	*/

	//==================================================
	//Podpunkt C
	cout << "\nPodpunkt C)" << endl;
	Autokar aut1;

	aut1.setMiejsce_docelowe("Krakow");
	for (int i = 0; i < aut1.getIlosc_miejsc(); i++)
	{
		aut1.dodajPasazera(tablica);
	}

	aut1.wypisz();

	//========================================================
	//Podpunkt D)

	cout << "\nPodpunkt D)" << endl;

	aut1.zmienWiek();

	// kolejne wypisanie dla spraWDZENIA
	cout << "\nNowe wypisanie dla sprawdzenia" << endl;
	aut1.wypisz();
	return 0;
}