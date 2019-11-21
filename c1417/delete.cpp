#include <iostream>

template <class T>
void printNumber(const T num)
{
    std::cout << "Num: " << num << "\n";
}

void printNumber(double) = delete;

int main()
{
    int i = 0;
    float f = 2.4f;
    uint8_t u = 23;
    double d = 2.32;

    printNumber(i);
    printNumber(f);
    printNumber(u);
    // printNumber(d); // Compiler fails, because we deleted a that fction.

    return 0;
}
