#include <iostream>

struct A
{
    void (*action)(int);
};

struct B : A
{
    void print(int a)
    {
        std::cout << "Hola " << a << "<-\n";
    }

    // action = &print;
};

void imprime(int a)
{
    for(int i = 0; i < a; ++i)
        std::cout << "a";
    std::cout << "\n";
}

int main()
{
    A a;

    a.action = &imprime;
    (*a.action)(4);

    B b;
    (*b.action)(3);

    return 0;
}