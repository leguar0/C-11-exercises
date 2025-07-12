#include <iostream>

//16. 
class CKontener
{
	int* tab;
	int size;

public:
	CKontener(int size);
	~CKontener();

	CKontener(const CKontener& ck);
	CKontener& operator=(const CKontener& ck);

	//17.
	CKontener(CKontener&& ck) noexcept;
	CKontener& operator=(CKontener&& ck) noexcept;


	void Wypisz();
};

CKontener::CKontener(int size)
	: size{size}, tab{new int[size]}
{
	for (int i = 0; i < size; ++i)
		tab[i] = i * 2;
}

CKontener::~CKontener()
{
	delete[] tab;
}

CKontener::CKontener(const CKontener& ck)
{
	size = ck.size;
	tab = new int[size];

	for (int i = 0; i < size; ++i)
		tab[i] = ck.tab[i];

}

CKontener& CKontener::operator=(const CKontener& ck)
{
	if (this != &ck)
	{
		delete[] tab;

		size = ck.size;
		tab = new int[size];

		for (int i = 0; i < size; ++i)
			tab[i] = ck.tab[i];
	}

	return *this;
}

CKontener::CKontener(CKontener&& ck) noexcept
{
	size = ck.size;
	tab = ck.tab;
	ck.tab = nullptr;
}

CKontener& CKontener::operator=(CKontener&& ck) noexcept
{
	if (this != &ck)
	{
		delete[] tab;
		
		size = ck.size;
		tab = ck.tab;

		ck.tab = nullptr;
	}

	return *this;
}

void CKontener::Wypisz()
{
	if (!tab) std::cout << "pustak" << std::endl;

	for (int i = 0; i < size; ++i)
		std::cout << tab[i] << " ";
	std::cout << std::endl;
}

int main()
{
	//16.
	CKontener ck{ 5 };
	ck.Wypisz();
	CKontener ck2 = ck;
	ck2.Wypisz();
	CKontener ck3{ 6 };
	ck3 = ck;
	ck3.Wypisz();

	//17.
	CKontener ck4{ 6 };
	ck4.Wypisz();
	ck4 = std::move(ck2);
	ck4.Wypisz();
	ck2.Wypisz();


	//18.


}