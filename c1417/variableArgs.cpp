#include <stdarg.h>
#include <iostream>
#include <vector>
 
// My god, it's full of bugs
std::vector<std::string> va_println(int args_left, ...)
{
   va_list arg_lst;
   va_start(arg_lst, args_left);
   std::vector<std::string> ret;
   ret.reserve(args_left);

   while(args_left--)
   		ret.emplace_back(va_arg(arg_lst, const char*));
 
   va_end(arg_lst);
   return ret;
}
 
int main()
{
   auto A = va_println(3, "Hola", "mundo", "n");
   
   std::cout << "size: " << A.size() << "\n";
   for(auto &a : A)
   	std::cout << a << "\n";
}