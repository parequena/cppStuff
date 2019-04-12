#include <iostream>

int main()
{
    int i = -1;

    do
    {
        std::cout << "Number: \n";
        std::cin >> i;
        std::cout << "i : " << i << "\n";
    } while(i < 0 || i > 3);
    
    return 0;    
}