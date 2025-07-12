#include <iostream>
#include <string>

//6.
void powitanie(const std::string& name, const std::string& greeting = "Czesc");

//8.
int fibbonacci(int n);

//9.
struct Osoba
{
	std::string imie, wiek;
}; 
void wypisz(const Osoba& ob);

//10.
class Prostokat
{
	int wysokosc, szerokosc;

public:
	Prostokat(int wysokosc, int szerokosc) : wysokosc{ wysokosc }, szerokosc{ szerokosc }
	{
	}

	int ObliczPole() const
	{
		return wysokosc * szerokosc;
	}
};


int main()
{

	//6.
	powitanie("Janek");

	//7.
	int size = 0;
	std::cin >> size;

	int *tab = new int[size];
	for (int i = 0; i < size; ++i)
		tab[i] = i;

	for (int i = 0; i < size; ++i)
		std::cout << tab[i] << std::endl;

	delete[] tab;

	//8.
	std::cout << std::endl;
	std::cout << fibbonacci(16) << std::endl;


	//9.
	Osoba ob{ "ww", "ww3" };
	wypisz(ob);

	//10.
	Prostokat prostokat{ 5, 2 };
	std::cout << prostokat.ObliczPole() << std::endl;
}

void powitanie(const std::string& name, const std::string& greeting)
{
	std::cout << greeting << " " << name << std::endl;
}

int fibbonacci(int n)
{
	if (n == 0) return 0;
	if (n == 1 || n == 2) return 1;

	return fibbonacci(n - 1) + fibbonacci(n - 2);
}


void wypisz(const Osoba& ob)
{
	std::cout << ob.imie << " " << ob.wiek << std::endl;
}


