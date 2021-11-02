#include <iostream>

int main()
{

	int* p = new int(1);
	auto a = *p;
	auto b = &a;
	auto c = p;
	auto d = &p;

	std::cout << "*p : " << a << "\n&a : " << b << "\n p : " << c << "\n&p : " << d << "\n";
	return 0;
}
