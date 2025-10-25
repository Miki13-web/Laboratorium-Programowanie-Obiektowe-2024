/*
	autor Miko³aj Bednarczyk
*/
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Osoba
{
protected:
	string imie;
	string nazwisko;
	int rok_ur;

public:
	//konstruktor domyœlny
	Osoba() {
		imie = "Nieznane", nazwisko = "Nieznane", rok_ur = 0;
	}

	//konstruktor
	Osoba(string vorname, string name, int uro) {
		imie = vorname, nazwisko = name, rok_ur = uro;
	}

	// gettery i settery
	string getImie() { return imie; }
	void setImie(string vorname) { imie = vorname; }
	string getNazwisko() { return nazwisko; }
	void setNazwisko(string name) { nazwisko = name; }
	int getRok_ur() { return rok_ur; }
	void setRok_ur(int ur) { rok_ur = ur; }

	//Metoda wirtualna
	virtual void wypisz()
	{
		cout << "Imie: " << imie << " Nazwisko: " << nazwisko << "\nRok urodzenia: " << rok_ur << endl;
	}

};

class Student : public Osoba
{
private:
	string kierunek_studiow;
	int rok;
public:
	// domyœlny konstruktor zaproponowany przez visuala
	Student() = default;

	//Konstruktor wieloargumentowy z list¹ inicjalizacyjn¹
	Student(string imie, string nazwisko, int rok_ur, string kierunek_studiow, int rok)
		: Osoba(imie, nazwisko, rok_ur), kierunek_studiow(kierunek_studiow), rok(rok)
	{
	}

	void wypisz()
	{
		cout << "Imie: " << imie << " Nazwisko: " << nazwisko << "\nRok urodzenia: " << rok_ur <<
			"\nKierunek studiow: " << kierunek_studiow << " Rok: " << rok << endl;
	}
};

class Pracownik : public Osoba
{
private:
	string miejsce_pracy;
	string zawod;
public:
	// domyœlny konstruktor zaproponowany przez visuala
	Pracownik() = default;

	//Konstruktor wieloargumentowy z list¹ inicjalizacyjn¹
	Pracownik(string imie, string nazwisko, int rok_ur, string miejsce_pracy, string zawod)
		: Osoba(imie, nazwisko, rok_ur), miejsce_pracy(miejsce_pracy), zawod(zawod)
	{
	}

	//Konstruktor kopiujacy ktory zmienia nazwisko i rok urodzenia na podane
	Pracownik(const Pracownik& pracownik, string nazw, int year)
	{
		imie = pracownik.imie;
		nazwisko = nazw;
		rok_ur = year;
		miejsce_pracy = pracownik.miejsce_pracy;
		zawod = pracownik.zawod;
	}

	void wypisz()
	{
		cout << "Imie: " << imie << " Nazwisko: " << nazwisko << "\nRok urodzenia: " << rok_ur <<
			"\nMiejsce pracy: " << miejsce_pracy << " Zawod: " << zawod << endl;
	}
};

//Funkcja przyjmuje tablice wskaznikow i zwraca tablice wskaznikow
Osoba** funkcja(Osoba** tab, int& rozmiar)
{
	int licznik = 0;
	int wiek;
	for (int i = 0; i < rozmiar; i++)
	{
		wiek = 2024 - (tab[i]->getRok_ur());
		if (wiek < 30) licznik++;
	}
	Osoba** nowa_tab = new Osoba * [licznik];

	licznik = 0;
	for (int i = 0; i < rozmiar; i++)
	{
		wiek = 2024 - (tab[i]->getRok_ur());
		if (wiek < 30)
		{
			nowa_tab[licznik] = tab[i];
			licznik++;
		}
	}

	rozmiar = licznik;

	return nowa_tab;
}

int main()
{
	// Zadanie A)
	//==================================================================
	cout << "Podpunkt A) \n" << endl;

	Osoba* czlowiek1 = new Osoba("Czarek", "Zegarek", 1999);

	cout << "Osoba nr 1\n";
	czlowiek1->wypisz();

	//Wypisanie za pomoca getterow
	//cout << "Osoba nr 1\n" << "Imie: " << czlowiek1.getImie() << "\nNazwisko: " << czlowiek1.getNazwisko() << "\nRok urodzenia: " << czlowiek1.getRok_ur() << endl;

	// Zadanie B)
	//==================================================================
	cout << "\nPodpunkt B) \n" << endl;

	Student student1("Paris", "Platynow", 1995, "Informatyka Techniczna", 1);
	cout << "Student nr 1:\n";
	student1.wypisz();

	// Zadanie C)
	//==================================================================
	cout << "\nPodpunkt C) \n" << endl;

	string nazw;
	int rok_u;

	Pracownik prac1("Andrzej", "Duda", 1972, "Warszawa", "Skryba");
	cout << "Pracownik nr1\n";
	prac1.wypisz();

	cout << "Wprowadz nowe nazwisko dla drugiego pracownika: ";
	cin >> nazw;
	cout << "Wprowadz rok jego urodzenia: ";
	cin >> rok_u;

	// konstruktor kopiujacy i zmieniajcy nazwisko i rok
	Pracownik prac2(prac1, nazw, rok_u);
	cout << "\nPracownik nr2\n";
	prac2.wypisz();

	// Zadanie D)
	//==================================================================
	cout << "\nPodpunkt D) \n" << endl;

	int rozmiar = 4;
	int rozmiar_kopia;
	rozmiar_kopia = rozmiar;
	Osoba** tab = new Osoba * [rozmiar];

	tab[0] = czlowiek1;
	tab[1] = &student1;
	tab[2] = &prac1;
	tab[3] = &prac2;

	for (int i = 0; i < rozmiar; i++)
	{
		(*tab[i]).wypisz();
		cout << endl;
	}

	// Zadanie E)
	//==================================================================
	cout << "\nPodpunkt E) \n" << endl;
	// zmienna na adres zwroconej tablicy
	//uzylem tego dla wygody by miec rozmair nowej tablicy
	Osoba** adres = funkcja(tab, rozmiar);
	Osoba** tab_nowa = new Osoba * [rozmiar];
	tab_nowa = funkcja(tab, rozmiar_kopia);

	for (int i = 0; i < rozmiar; i++)
	{
		(*tab_nowa[i]).wypisz();
		cout << endl;
	}

	// DRUGI SPOSOB

	//niewazne usunalem

	// KONIEC ==========================================================

	return 0;
}


