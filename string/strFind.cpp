// string::find
#include <iostream>       // std::cout
#include <string>         // std::string

int main ()
{
    std::string str = "MMA";

    std::cout << "M at : " << str.find("M") << "\n";
    std::cout << ". at : " << str.find(".") << "\n";
    std::cout << "sizet: " << static_cast<size_t>(-1) << "\n";

    return 0;
}