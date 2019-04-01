#include <iostream>
#include <vector>

class miVector
{
	std::vector<int> idx;

public:
	miVector(const std::vector<int> i)
	{
		std::copy(i.begin(), i.end(), idx);
	}

	std::vector<int> getVector()
	{
		return idx;
	}

	std::vector<int>& getIdx()
	{
		return &idx;
	}
};

int main()
{
	std::vector<int> a =  {1, 2, 3, 4, 5};
	miVector b(a);
	std::vector<int> c = b.getVector();
	auto d = b.getIdx();

	for(auto & cc : c)
		std::cout << cc << " ";
	std::cout << "\n";
}
