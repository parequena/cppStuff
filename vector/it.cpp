
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> myv = {1, 2, 4, 5, 6};
	std::vector<int> vec  = std::vector<int>(myv.size());

	for(auto it = myv.begin(); it != myv.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";

	for(auto v : vec)
		std::cout << v << " ";
	std::cout << "\n";

	auto  vecIt = vec.begin();
	for(auto it = myv.begin(); it != myv.end(); ++it, ++vecIt)
	{
		*vecIt = *it;
	}

	for (auto v : vec)
		std::cout << v << " ";
	std::cout << "\n";

	return 0;
}
