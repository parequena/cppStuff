#include <iostream>
#include <vector>
#include <stdlib.h>
#include <chrono>

template<class I = int>
void printVector(const std::vector<I>& vec)
{
    for(auto v : vec)
        std::cout << v << " ";
    std::cout << "\n";
}

int main(int argc, char** argv)
{
    srand(time(0));

    const int kArgs = 2;
    if(argc != kArgs)
    {
        std::cerr << "ERROR: " << argc << " given and expected " << kArgs << "\n";
        std::cerr << "Try: ./exe <number>\n";
    }

    auto vSize = std::atoi(argv[1]);
    std::cout << "Vector size: " << vSize << "\n";

    std::vector<int> v1(vSize), v2(vSize), v3(vSize);

    for(auto i = 0; i < vSize; ++i)
        v1[i] = rand() % 20 + 1;

    // std::cout << "v1:\n";
    // printVector(v1);
    // std::cout << "----------------\n";

    auto st = std::chrono::steady_clock::now();
    auto it = v2.begin();
    for(auto i = v1.begin(); i != v1.end(); ++i, ++it)
        *it = *i;
    auto ed = std::chrono::steady_clock::now();
    std::cout << "NS: " << std::chrono::duration_cast<std::chrono::milliseconds>(ed-st).count() << "\n";

    st = std::chrono::steady_clock::now();
    std::copy(v1.begin(), v1.end(), v3.begin());
    ed = std::chrono::steady_clock::now();
    std::cout << "NS: " << std::chrono::duration_cast<std::chrono::milliseconds>(ed-st).count() << "\n";

}