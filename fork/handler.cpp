/*
   Handler code that opens a fork and executes a child
   program (a process) to read their std::cout.

   This code should work with any C++ > 03 standard (C++20's stuff like std::span),
   but for me I'll compile it with C++20.

   Steps:
   g++ -std=c++20 -fsanitize=address childCode.cpp -o childCode
   g++ -std=c++20 -fsanitize=address handler.cpp -o handler
   ./handler childCode
*/
#include <iostream>  // std::cerr
#include <span>      // std::span
#include <string>    // std::string
#include <vector>    // std::vector
#include <unistd.h>  // close, fork, execve

static int better_main(std::span<std::string> const args)
{
   if( args.size() == 1 )
   {
      std::cerr << "ERROR - Try executing: ./handler <binary file> <bin file args...>\n";
      return EXIT_FAILURE;
   }

   std::vector<char*> childArgs{};
   childArgs.reserve(args.size() + 1);
   for(auto const& arg : args)
   {
      childArgs.emplace_back( const_cast<char*>( arg.c_str() ) );
   }
   childArgs.emplace_back(nullptr);

   // Create pipe to read from code.
   int fd_child_to_parent[2];
   pipe(fd_child_to_parent);

   auto const pid = fork();
   if(pid == 0)
   {
      // Child process.
      close(fd_child_to_parent[STDIN_FILENO]); // Close reading on pipe.
      dup2(fd_child_to_parent[STDOUT_FILENO], STDOUT_FILENO); // Swap std::cout by pipe.

      // Execute binary file, without arguments.
      auto const binToRead { args[0] };
      execve(binToRead.c_str(), childArgs.data(), nullptr);

      std::cerr << "This error shouldn't be executed!\n";
      // The code after execve will only be executed if execve fails.
      dup2(STDOUT_FILENO, fd_child_to_parent[STDOUT_FILENO]); // Restore std::cout.
      close(fd_child_to_parent[STDOUT_FILENO]); // Close writing pipe.
      
      return EXIT_FAILURE;
   }

   close(fd_child_to_parent[STDOUT_FILENO]); // Close writing on pipe.
   dup2(fd_child_to_parent[STDIN_FILENO], STDIN_FILENO); // Swap std::cin by pipe.

   std::cout << "Recieved from child:\n----------\n";
   std::string readFromChild{};
   while ( std::getline(std::cin, readFromChild) )
   {
      std::cout << readFromChild << '\n';
   }
   
   std::cout << "----------\n";

   
   dup2(STDIN_FILENO, fd_child_to_parent[STDIN_FILENO]); // Restore std::cin.
   close(fd_child_to_parent[STDIN_FILENO]); // Close reading pipe.

   return EXIT_SUCCESS;
}

int main(int const argc, char const* const* const argv)
{
   auto result = std::ranges::subrange(&argv[1], &argv[argc]);
   std::vector<std::string> args{ result.begin(), result.end() };

   return better_main(args);
}
