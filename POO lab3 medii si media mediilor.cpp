// 3 modificatori:
// 1. Private: Datele sunt accesibile doar in aceeasi clasa
// 2. Protected: Datele sunt accesibile in aceeasi clasa si in clasele derivate
// 3. Public : Datele sunt accesibile in aceeasi clasa, in clasele derivate (mostenite) si in exterior
#include <iostream>
#include <string>

using namespace std;

class Persoana
{
protected:
	string nume;
	int varsta;
public:
	// Cream un constructor
	Persoana(string nume, int varsta)
	{
		this->nume = nume;
		this->varsta = varsta;
	}
	// Metoda de afisare
	void afisare_detalii()
	{
		cout << "Nume: " << nume << ", Varsta: " << varsta << endl;
	}
};

// Cream o clasa derivata/mostenita din Clasa Persoana
class Student : public Persoana
{
private:
	float medie;
public:
	// Constructor :
	Student(string nume, int varsta, float medie) : Persoana(nume, varsta)
	{
		this->medie = medie;
	}
	// Suprascrierea metodei de afisare:
	void afiseaza_informatii()
	{
		cout << "Nume: " << nume << ", Varsta: " << varsta << ", Media: " << medie << endl;
	}
	float getMedie() {
		return medie;
	}
};

int main()
{
	/*
	// Cream un obiect de tip Student
	Student s("Ion", 21, 10);
	s.afiseaza_informatii();
	*/

	int n;
	cout << "Introduceti numarul de studenti: "; cin >> n;
	Student** studenti = new Student * [n];
	float s = 0;

	for (int i = 0; i < n; i++)
	{
		string nume;
		int varsta;
		float medie;

		cout << "Introduceti nume student: "; cin >> nume;
		cout << "Introduceti varsta student: "; cin >> varsta;
		cout << "Introduceti media student: "; cin >> medie;

		studenti[i] = new Student(nume, varsta, medie);
		s += medie;
	}

	cout << "Studentii introduci sunt: " << endl;

	for (int i = 0; i < n; i++)
		studenti[i]->afiseaza_informatii();

	cout << "\n Media mediilor este: " << s / n << endl;
	
	return 0;
}
// sa se scrie un program in C++ pentru gestiunea unei gradini zoologice folosind clase, obiecte si conceptul mosterire
// vei avea o clasa ANIMAL si din ease deriva alte clase, de ex pt pasari vor 
// fi alte atribute (dura de viata, lungime aripi), pt caini (rasa, caine de vanatoare, casa, rescue, competitii
//  treuie modificata dwoar clasa principala si clasa derivara 
//  LA FINAL SE AFISEAZA REZ CU CLASA DE ANIMALE
//