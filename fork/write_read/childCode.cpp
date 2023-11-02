/*
   This is an handler example code.
   This code just prints something.
*/
#include <iostream>

int main(int const argc, char const* const* const argv)
{     
   int nTimes{ 1 };
   if( argc >= 2 )
   {
      nTimes = std::atoi(argv[1]);
   }
   else if( argc < 1)
   {
      std::cerr << "ERROR - Try executing: ./childCode <nTimes to std::cout>\n";
      return EXIT_FAILURE;
   }

   std::string fromParent{};
   std::cout << "Read from parent:\t";
   std::getline(std::cin, fromParent);

   std::cout << "\nFrom parent:\n++++++\n" << fromParent << "\n++++++\n";

   for(int i{}; i < nTimes; ++i)
   {
      std::cout << i << "\tTest from child code\n";
   }
   
   return EXIT_SUCCESS;
}
