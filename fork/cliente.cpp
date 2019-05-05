#include <iostream>

int main()
{
    std::string fromParent = "";

    std::getline(std::cin, fromParent);

    std::cout << "Recived fromParent: " << fromParent << " and said this\n";
}