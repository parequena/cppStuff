#include <iostream>

auto getcosa(int a)
{
	if(a == 0)
		return 0;
	else if(a == 1)
		return 1.0f;
}

int main(int argc, char const *argv[])
{
	std::cout << "0: " << getcosa(0) << "\n";
	std::cout << "1: " << getcosa(1) << "\n";

	return 0;
}