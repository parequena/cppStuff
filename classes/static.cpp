#include <iostream>
#include <vector>

struct A
{
    static int globalID;
    int id = 0;

    A(): id(++globalID) {}
};

int A::globalID = 0;

struct B
{
    B(): B(1) {}

    B(int as)
    {
        if(as >= 1)
        {
            aes.reserve(as);
            for(int i = 0; i < as; ++i)
                aes.emplace_back(new A());
        }
    }

    void printAEs()
    {
        std::cout << "AES: ";
        for(auto &a: aes)
            std::cout << a->id << " ";
        std::cout << "\n";
    }

    std::vector<A*> aes;
};

int main()
{
    B b1;
    B b2(3);

    b1.printAEs();
    b2.printAEs();
}
