#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

static std::vector<int> vect{};

void printVector(auto const &vector)
{
    std::cout << "Vect [ ";
    for (auto v : vector)
        std::cout << v << ' ';

    std::cout << "]\n";
}

int main()
{
    std::string str{};
    int k{};
    bool exec = true;

    std::thread th([&exec]()
                   {
            while(exec)
            {
                printVector(vect);
                std::this_thread::sleep_for(std::chrono::seconds{5});
            }; });

    do
    {
        std::cout << "Insert number:\n";
        std::getline(std::cin, str);

        k = std::stoi(str);

        if (k == 0)
        {
            exec = false;
            break;
        }

        vect.emplace_back(k);

    } while (k != 0);

    std::cout << "Bye!\n";
    printVector(vect);
    th.join();
}