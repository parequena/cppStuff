#include <iostream>

struct A
{
	std::string str;

	A(const A& a):
		A(a.str)
	{ }

	A(const std::string& s):
		str(s)
	{ }
};

void print(const std::string& str)
{
	std::cout << "str: " << str << "\n";
}

int main()
{

	const std::string s1 = "Pablo";
	print(s1);
	print("Antonio");
	return 0;
}
