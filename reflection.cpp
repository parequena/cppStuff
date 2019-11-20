#include <iostream>

struct A
{
    int i = 0;

    A(): A(0) {};
    A(int _i): i(_i) {};
};

struct B : public A
{
    B(int _i): A(_i) {};
};

struct C : public A
{
    C(int _i): A(_i) {};
};

struct intToA
{
    int num;
    A* a;
};

intToA itoa[] =
#include "mapping.txt"

int main(int argc, char* argv[])
{
    const int k = 2;
    // if(argc != k)
    //     std::cerr << "argc != " << k << "\n";
        
    intToA* i = itoa;
        
    int number = 2; // atoi(argv[1]);
        
    A* a;
    
    // std::cout << "a->i: " << a->i << "\n";

    while(i->num != -1)
    {
        if(i->num == number)
        {
            a = i->a;
            std::cout << "num: " << i->num << "\n";
        }

        ++i;
    }

    std::cout << "a->i: " << a->i << "\n";

    return 0;
}
