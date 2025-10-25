/*
	autor Miko³aj Bednarczyk
*/
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class LiczbaZespolona
{
private:
	double cz_rzeczywista;
	double cz_urojona;

public:
	//konstruktor domyœlny
	LiczbaZespolona() {
		cz_rzeczywista = 1, cz_urojona = 1;
	}

	LiczbaZespolona(double rze, double uro) {
		cz_rzeczywista = rze, cz_urojona = uro;
	}

	// gettery i settery
	double getCz_rzeczywista() { return cz_rzeczywista; }
	void setCz_rzeczywista(double rz) { cz_rzeczywista = rz; }
	double getCz_urojona() { return cz_urojona; }
	void setCz_urojona(double ur) { cz_urojona = ur; }

	//Przeciazony operator <<
	friend ostream& operator << (ostream& wyjscie, const LiczbaZespolona& liczba);
	//Przeciazony operator + jako metoda klasy
	LiczbaZespolona operator+ (LiczbaZespolona liczba) { return LiczbaZespolona(cz_rzeczywista + liczba.cz_rzeczywista, cz_urojona + liczba.cz_urojona); }
	//Przeciazony operator * 
	LiczbaZespolona operator* (LiczbaZespolona liczba) { return LiczbaZespolona((cz_rzeczywista * liczba.cz_rzeczywista) - (cz_urojona * liczba.cz_urojona), (cz_rzeczywista * liczba.cz_urojona) + (cz_urojona * liczba.cz_rzeczywista)); }
	//Przeciazony operator / 
	LiczbaZespolona operator/ (LiczbaZespolona liczba) { return LiczbaZespolona(((cz_rzeczywista * liczba.cz_rzeczywista) + (cz_urojona * liczba.cz_urojona)) / (pow(liczba.cz_rzeczywista, 2) + pow(liczba.cz_urojona, 2)), ((cz_urojona * liczba.cz_rzeczywista) - (cz_rzeczywista * liczba.cz_urojona)) / (pow(liczba.cz_rzeczywista, 2) + pow(liczba.cz_urojona, 2))); }
};

// funkcja globalna do wypisywania przeciazony operator <<
ostream& operator<< (ostream& wyjscie, const LiczbaZespolona& liczba) {
	if (abs(liczba.cz_urojona) == 1)
		if (liczba.cz_urojona > 0)
			return wyjscie << liczba.cz_rzeczywista << " + " << "i\n";
		else
			return wyjscie << liczba.cz_rzeczywista << " - " << "i\n";

	if (liczba.cz_urojona > 0)
		return wyjscie << liczba.cz_rzeczywista << " + " << liczba.cz_urojona << "i\n";
	if (liczba.cz_urojona < 0)
		return wyjscie << liczba.cz_rzeczywista << " " << liczba.cz_urojona << "i\n";

	if (liczba.cz_urojona == 0)
		return wyjscie << liczba.cz_rzeczywista << "\n";

}

int main()
{
	// Zadanie A)
	//==================================================================
	cout << "Podpunkt A) \n" << endl;

	LiczbaZespolona liczba_Z1(2, 1);
	LiczbaZespolona liczba_Z2(-3, -7);
	cout << "Liczba Z1:\n" << liczba_Z1;
	cout << "\nLiczba Z2:\n" << liczba_Z2;

	// Zadanie B)
	//==================================================================
	cout << "\nPodpunkt B) \n" << endl;

	cout << "Z1 + Z2 = " << liczba_Z1 + liczba_Z2 << endl;

	// Zadanie C)
	//==================================================================
	cout << "\nPodpunkt C) \n" << endl;

	cout << "Z1 * Z2 = " << liczba_Z1 * liczba_Z2 << endl;

	// Zadanie D)
	//==================================================================
	cout << "\nPodpunkt D) \n" << endl;

	cout << "Z1 / Z2 = " << liczba_Z1 / liczba_Z2 << endl;

	// KONIEC ==========================================================

	return 0;
}


