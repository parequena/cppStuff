#include <iostream>

void printNumber1(const int n)
{
    std::cout << "1: " << n << "\n";
}

void printNumber2(const int n)
{
    std::cout << "2: " << n << "\n";
}

void printNumber(const int n, void(*f)(const int))
{
    (*f)(n);
}

int main()
{
    void (*func)(const int);
    func = &printNumber1;
    // const int i = 1;
    printNumber(1, *func);

    func = &printNumber2;
    printNumber(1, *func);

    return 0;
}