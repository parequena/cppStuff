#include <unistd.h>
#include <iostream>

int main()
{
    std::string child_buffer = "";
    std::cin >> child_buffer; // wait for father's messages
    std::cout << "CHILD2 received: " << child_buffer << "\n"; //return message to father

    // std::string str = "";
    // std::getline(std::cin, str);

    // std::cout << "Read: " << str << "\n";z
    // std::cout << "L:R:0";

    return 0;
}