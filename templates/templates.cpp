#include <iostream>
#include <vector>

template <class T>
void printNumber(T num)
{
    std::cout << "Number: " << num << "\n";
}

template <class T>
void printVector(const std::vector<T>& v)
{
    for(auto _ : v)
        std::cout << _ << " ";
    std::cout << "\n";
}

template <class T>
void printArray(T v)
{
    for(auto i = 0; i < 3; ++i)
        std::cout << v[i] << " ";
    std::cout << "\n";
}

int main()
{
    int i = 1;
    float k = 2;
    double m = 3;

    printNumber(i);
    printNumber(k);
    printNumber(m);

    std::vector<int> v1 = {1, 2, 3};
    std::vector<float> v2 = {1.5, 2.8, 3.3};

    printVector(v1);
    printVector(v2);

    int a[] = {1, 2, 3};
    float b[] = {1.2, 2.45, 3.3};

    printArray(a);
    printArray(b);

    printArray(v1);

    return 0;
}