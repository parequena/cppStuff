#include <iostream>

constexpr auto k{"hello"};

int main()
{
   std::cout << "This is a normal color\n";
   std::cout << "\033[1;31mbold red text\033[0m\n";
   std::cout << "\033[1;96;100mProbando Cyan negrita, fondo gris " << k << ", a ti tambien.\033[0m\n";

   return EXIT_SUCCESS;
}
