#include<iostream>

void print(const int* i)
{
    std::cout << i << "\n";
}

int main()
{
    int* i = new int(3);
    print(i);
    delete i;
}