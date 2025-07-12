#include <iostream>

//11.
class Prostokat
{
	int wysokosc, szerokosc;

public:
	Prostokat(int wysokosc, int szerokosc) : wysokosc{ wysokosc }, szerokosc{ szerokosc }
	{
	}

	int ObliczPole()
	{
		return wysokosc * szerokosc;
	}

	Prostokat operator+(const Prostokat& p);
};

Prostokat Prostokat::operator+(const Prostokat& p)
{
	Prostokat prostokat{wysokosc+p.wysokosc, szerokosc+p.szerokosc};
	return prostokat;
}

//12.
template<typename T>
T max(T a, T b)
{
	return (a > b) ? a : b;
}

//13.
enum class Kolor {
	KOLOR_CZERWONY = 1,
	KOLOR_ZIELONY,
	KOLOR_NIEBIESKI
};

//14.
void Swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

//15.
struct DzieleniePrzezZero
{
};

int Div(int a, int b)
{
	if (b == 0) {
		DzieleniePrzezZero dz;
		throw dz;
	}
	
	return a / b;
}

int main()
{
	//11.
	Prostokat pr{ 2, 3 };
	Prostokat p2{ 2, 3 };
	pr = pr + p2;
	std::cout << pr.ObliczPole() << std::endl;

	//12.
	std::cout << max<int>(5, 2) << std::endl;

	//13.
	Kolor kolor = Kolor::KOLOR_CZERWONY;
	switch (kolor)
	{
	case Kolor::KOLOR_CZERWONY:
		std::cout << "CZERWONY" << std::endl;
		break;
	case Kolor::KOLOR_ZIELONY:
		std::cout << "ZIELONY" << std::endl;
		break;
	case Kolor::KOLOR_NIEBIESKI:
		std::cout << "NIEBIESKI" << std::endl;
		break;
	default:
		break;
	}

	//14.
	int a = 5;
	int b = 7;
	std::cout << a << " " << b << std::endl;
	Swap(&a, &b);
	std::cout << a << " " << b << std::endl;


	//15.
	try
	{
		Div(1, 0);
	}
	catch (DzieleniePrzezZero)
	{
		std::cout << "Dzielenie przez 0" << std::endl;
	}

}
