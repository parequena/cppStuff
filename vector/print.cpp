#include <iostream>
#include <vector>

void print(const std::vector<std::string>& strings)
{
	for(auto& s : strings)
	{
		std::cout << s << "\n";
	}
}

int main()
{
	std::vector<std::string> v = {"Hola", "Estoy", "haciendo un print", "de este vector"};
	print(v);
	return 0;
}
