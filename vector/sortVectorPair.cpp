#include <vector>
#include <iostream>
#include <algorithm>

struct A
{
	std::string str = "";
	A(const std::string& s): str(s) {}
};

void vpprint(const std::vector<std::pair<int, std::string>>& v)
{
	auto size = v.size();

	std::cout << "---------------------\n";
	for(auto i = 0; i < size; ++i)
		std::cout << v[i].first << " : " << v[i].second << "\n";
	std::cout << "---------------------\n";
}

int main(int argc, char const *argv[])
{
	std::vector<std::pair<int, A*>> v1, v2;

	v1.push_back(std::make_pair(1, new A("aa")));
	v1.push_back(std::make_pair(3, new A("ab")));
	v1.push_back(std::make_pair(2, new A("ccc")));

	vpprint(v1);
	std::sort(v1.begin(), v1.end());
	vpprint(v1);

	return 0;
}