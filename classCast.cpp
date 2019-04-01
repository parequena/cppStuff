#include <iostream>
#include <vector>

struct A
{
	virtual void saluda() = 0;
};

struct B : public A
{
	inline void saluda() override { std::cout << "Hola desde B\n"; };
};

struct C : public A
{
	inline void saluda() override { std::cout << "Hola desde C\n"; };
};


int main(int argc, char const *argv[])
{
	std::vector<A*> aes;
	aes.reserve(2);
	aes.emplace_back(new B());
	aes.emplace_back(new C());

	for(auto& a : aes)
		a->saluda();
		// (dynamic_cast<C*>(a))->saluda();

	return 0;
}