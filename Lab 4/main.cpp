/*
	autor Miko³aj Bednarczyk
*/
#include <iostream>
#include <string>

using namespace std;

class Samochod
{
private:
	string marka;
	string model;
	int cena;

public:
	void setMarka(string brand) { marka = brand; }
	string getMarka() { return marka; }
	void setModel(string type) { model = type; }
	string getModel() { return model; }
	void setCena(int price) { cena = price; }
	int getCena() { return cena; }

	void WypiszAuto()
	{
		cout << getMarka() << " " << getModel() << " " << getCena() << endl;
	}

};

class Garaz
{
private:
	string nazwa;
	Samochod* samochody[15];
	int licznik_aut = 0;

public:
	int suma = 0;
	void setNazwa(string name) { nazwa = name; }
	string getNazwa() { return nazwa; }

	Samochod* getSamochody() { return *samochody; }

	Garaz(string nazwa) { this->nazwa = nazwa; cout << getNazwa() << endl; }

	void dodajAuto(Samochod* wsk_auto)
	{
		licznik_aut++;
		if (licznik_aut <= 15)
		{
			samochody[licznik_aut - 1] = wsk_auto;
			cout << "Dodano Auto nr. " << licznik_aut << endl;
		}
		else
			cout << "\n Brak miejsca w garazu \nNie mozna dodac auta\n";
	}
	void wypisz_samochody()
	{
		for (int i = 0; i < licznik_aut; i++)
		{
			samochody[i]->WypiszAuto();
		}
	}

	void wartoscAut()
	{
		for (int i = 0; i < licznik_aut; i++)
		{
			suma += samochody[i]->getCena();
		}
		cout << "suma: " << suma;
	}
};


int main()
{
	// Zadanie A)
	//==================================================================
	cout << "Podpunkt A) \n";

	Samochod tab1[2];
	Samochod tab2[3];

	tab1[0].setMarka("Fiat");
	tab1[0].setModel("Punto");
	tab1[0].setCena(3500);
	tab1[1].setMarka("Opel");
	tab1[1].setModel("Astra");
	tab1[1].setCena(2400);

	tab2[0].setMarka("Fiat");
	tab2[0].setModel("Seicento");
	tab2[0].setCena(3800);
	tab2[1].setMarka("Fiat");
	tab2[1].setModel("Tipo");
	tab2[1].setCena(46000);
	tab2[2].setMarka("Opel");
	tab2[2].setModel("Frontera");
	tab2[2].setCena(35800);

	cout << "Tablica samochodow 1: \n";
	cout << "Marka: " << tab1[0].getMarka() << " model: " << tab1[0].getModel() << " cena: " << tab1[0].getCena() << endl;
	cout << "Marka: " << tab1[1].getMarka() << " model: " << tab1[1].getModel() << " cena: " << tab1[1].getCena() << endl;

	cout << "\nTablica samochdow 2: \n";
	cout << "Marka: " << tab2[0].getMarka() << " model: " << tab2[0].getModel() << " cena: " << tab2[0].getCena() << endl;
	cout << "Marka: " << tab2[1].getMarka() << " model: " << tab2[1].getModel() << " cena: " << tab2[1].getCena() << endl;
	cout << "Marka: " << tab2[2].getMarka() << " model: " << tab2[2].getModel() << " cena: " << tab2[2].getCena() << endl;

	// Zadanie B)
	//==================================================================
	cout << "\nPodpunkt B) \n" << endl;

	Garaz garaz1("Garaz Mikolaja");
	Garaz garaz2("Garaz Adama");

	// Zadanie C)
	//==================================================================
	cout << "\nPodpunkt C) \n";

	cout << "\nDodawanie do garazu Mikolaja: \n";
	garaz1.dodajAuto(tab1);
	garaz1.dodajAuto(tab1 + 1);

	cout << "\nDodawanie do garazu Adama: \n";
	garaz2.dodajAuto(tab1);
	garaz2.dodajAuto(tab1 + 1);
	garaz2.dodajAuto(tab2);
	garaz2.dodajAuto(tab2 + 1);
	garaz2.dodajAuto(tab2 + 2);

	//=================================================================
	// wyswietlanie danych garazow
	cout << "\nGaraz 1:\n";
	cout << garaz1.getNazwa() << endl;
	cout << "Samochody:\n";
	garaz1.wypisz_samochody();


	cout << "\nGaraz 2:\n";
	cout << garaz2.getNazwa() << endl;
	cout << "Samochody:\n";
	garaz2.wypisz_samochody();


	// Zadanie D)
	//==================================================================
	cout << "\nPodpunkt D) \n";
	garaz1.wartoscAut();
	cout << endl;
	garaz2.wartoscAut();
	return 0;
}