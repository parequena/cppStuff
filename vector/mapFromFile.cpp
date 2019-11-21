#include <iostream>
#include <vector>


int main()
{
    std::vector<int> map = {
        #include "res/myMap.txt"
    };

    std::cout << "Map Size: " << map.size() << "\n";

    for(auto _ : map)
        std::cout << _ << " ";
    std::cout << "\n";

    return 0;
}