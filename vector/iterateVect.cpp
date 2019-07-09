#include <iostream>
#include <vector>
#include <chrono>

void fillVect(std::vector<int>& v, const int size)
{
    v.reserve(size);
    for(auto i = 0; i < size; ++i)
        v.emplace_back(i);
}

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cerr << "ERROR: Try ./exe <matSize>\n";
        return -1;
    }

    int size = std::atoi(argv[1]);
    std::vector<int> v1, v2, v3;
    fillVect(v1, size);
    fillVect(v2, size);
    fillVect(v3, size);

    auto acum1 = 0, acum2 = 0, acum3 = 0;

    auto st = std::chrono::steady_clock::now();
    for(auto i = 0; i < size; ++i)
        acum1 += v1[i];
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - st).count() << "\n";

    st = std::chrono::steady_clock::now();
    for(auto v : v2)
        acum2 += v;
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - st).count() << "\n";

    st = std::chrono::steady_clock::now();
    for(auto it = v3.begin(); it != v3.end(); ++it)
        acum3 += *it;
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - st).count() << "\n";

    std::cout << "Acum1: " << acum1 << "\n";
    std::cout << "Acum2: " << acum2 << "\n";
    std::cout << "Acum3: " << acum3 << "\n";

    return 0;
}