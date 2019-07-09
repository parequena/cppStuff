#include <iostream>

struct Clase
{
	std::string str;

	Clase()
	{
		str = "Default";
	}

	Clase(const std::string& s)
	{
		str = s;
	}

	void print()
	{
		std::cout << str << "\n";
	}
};

int main()
{
	Clase c1;
	Clase c2("Pepe");

	c1.print();
	c2.print();
	return 0;
}
