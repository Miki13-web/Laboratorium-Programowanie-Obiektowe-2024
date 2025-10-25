/*
	autor Miko³aj Bednarczyk
*/
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Ulamek
{
private:
	int licznik;
	int mianownik;

public:
	//konstruktor domyœlny
	Ulamek() {
		licznik = 1, mianownik = 1;
		//cout << "Ulamek utworzony" << endl; 
	}

	// konstruktor z list¹ inicjalizacyjn¹ dla wygody poprostu
	Ulamek(int L, int M) : licznik(L), mianownik(M) {
	}

	//konstruktor konwertuj¹cy
	Ulamek(int Liczba) : licznik(Liczba), mianownik(1) {
	}

	// gettery i settery
	int getLicznik() { return licznik; }
	void setLicznik(int L) { licznik = L; }
	int getMianownik() { return mianownik; }
	void setMianownik(int M) { mianownik = M; }

	// operator konwertujacy
	operator double() const {
		return static_cast<double>(licznik) / static_cast<double>(mianownik);
	}

	// metoda z polecenia
	void liczbaMieszana()
	{
		int calosci;
		calosci = licznik / mianownik;
		licznik = licznik - (calosci * mianownik);
		cout << "Liczba mieszna z tego ulamka wyglada nastepujaco : " << calosci << " i " << licznik << "/" << mianownik << endl;
	}

};

Ulamek podziel(Ulamek u1, Ulamek u2)
{
	// tworze obiekt u3 i getterami i setterami ustawiam odpowiednio dzielenie
	Ulamek u3;
	u3.setLicznik(u1.getLicznik() * u2.getMianownik());
	u3.setMianownik(u1.getMianownik() * u2.getLicznik());

	return u3;
}

double pierwiastkuj(double liczba)
{
	double wynik;
	wynik = sqrt(liczba);
	return wynik;
}

// dla wygody mam  funkcje NWD
int NWD(int a, int b)
{
	int pom;

	while (b != 0)
	{
		pom = b;
		b = a % b;
		a = pom;
	}

	return a;
}

void ile_nieskracalnych(int liczba)
{
	int licznik = 0;
	// z przekazanej liczby calkowitej tworze ulamek u1 mianownik to liczba przekazana, zaœ licznk jest o 1 mniejszy
	Ulamek u1(liczba - 1, liczba);

	cout << "\nDla liczby " << liczba << " ulamki nieskracalne : \n";
	for (int i = liczba - 1; i >= 1; i--)
	{
		//jezeli nwd dwoch liczb jest rowny 1 to nie da sie ich skrocic
		if (NWD(u1.getLicznik(), u1.getMianownik()) == 1)
		{
			cout << u1.getLicznik() << "/" << u1.getMianownik() << " , ";
			licznik++;
		}
		u1.setLicznik(i - 1);
	}
	cout << endl << "Dla danej liczby " << liczba << " takich ulamkow jest: " << licznik << endl;
}
int main()
{
	// Zadanie A)
	//==================================================================
	cout << "Podpunkt A) \n" << endl;

	Ulamek u1(2, 3);
	Ulamek u2(3, 4);

	cout << "Ulamek nr 1:  " << u1.getLicznik() << "/" << u1.getMianownik() << endl;
	cout << "Ulamek nr 2:  " << u2.getLicznik() << "/" << u2.getMianownik() << endl;

	// Zadanie B)
	//==================================================================
	cout << "\nPodpunkt B) \n" << endl;

	Ulamek u3;
	u3 = podziel(u1, u2);
	cout << "Wynik dzielenia ulamkow z podpunktu A):  " << u3.getLicznik() << "/" << u3.getMianownik() << endl;

	// Zadanie C)
	//==================================================================
	cout << "\nPodpunkt C) \n" << endl;

	//wykorzystanie konstruktora konwertujacego z liczby typu in na obiekt klasy Ulamek
	cout << "Wynik dzielenia ulamka 2/3 z liczba 4:  " << podziel(u1, 4).getLicznik() << "/" << podziel(u1, 4).getMianownik() << endl;

	// Zadanie D)
	//==================================================================
	cout << "\nPodpunkt D) \n" << endl;

	// wykorzystanie operatora konwersji z obiektu klasy Ulamek na typ double
	cout << "Wynik pierwiastkowania ulamka nr 1 wynosi: " << pierwiastkuj(u1) << endl;

	// Zadanie E)
	//==================================================================
	cout << "\nPodpunkt E) \n" << endl;

	Ulamek u4(53, 12);
	cout << "Ulamek to " << u4.getLicznik() << "/" << u4.getMianownik() << endl;
	u4.liczbaMieszana();

	// Zadanie F)
	//================================================================
	cout << "\nPodpunkt F) \n";

	ile_nieskracalnych(7);
	ile_nieskracalnych(25);
	ile_nieskracalnych(54);

	return 0;
}


