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
   if( args.size() <= 1 )
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

   // Create pipes for communication
   int fd_child_to_parent[2], fd_parent_to_child[2];
   pipe(fd_child_to_parent);
   pipe(fd_parent_to_child);

   auto const pid = fork();
   if (pid == 0)
   {
      // Child process.
      close(fd_child_to_parent[STDIN_FILENO]); // Close the reading end of the pipe.
      dup2(fd_child_to_parent[STDOUT_FILENO], STDOUT_FILENO); // Redirect stdout to the pipe.

      close(fd_parent_to_child[STDOUT_FILENO]); // Close the writing end of the pipe.
      dup2(fd_parent_to_child[STDIN_FILENO], STDIN_FILENO); // Redirect stdin to the pipe.

      // Execute the binary file with arguments.
      auto const binToRead { args[0] };
      execve(binToRead.c_str(), childArgs.data(), nullptr);

      // If execve fails, it will print an error message.
      std::cerr << "ERROR - Execution failed\n";
      return EXIT_FAILURE;
   }

   // Parent process.

   // Close unused pipe ends.
   close(fd_child_to_parent[STDOUT_FILENO]);
   close(fd_parent_to_child[STDIN_FILENO]);

   std::string toChild;
   std::cout << "Write something to child:\t";
   std::getline(std::cin, toChild);

   // Write to the child process.
   if ( write(fd_parent_to_child[STDOUT_FILENO], toChild.c_str(), toChild.size()) == -1) 
   {
      std::cerr << "ERROR - Writing to the child\n";
      return EXIT_FAILURE;
   }

   close(fd_parent_to_child[STDOUT_FILENO]); // Close the writing end of the pipe.

   std::cout << "Received from child:\n----------\n";
   char buffer[1024];
   ssize_t bytesRead{};
   while ((bytesRead = read(fd_child_to_parent[STDIN_FILENO], buffer, sizeof(buffer))) > 0)
   {
      std::string readFromChild(buffer, bytesRead);
      std::cout << "\033[1;31m" << readFromChild << "\033[0m\n";
   }
   std::cout << "----------\n";

   // Close the reading end of the pipe and wait for the child process to exit.
   close(fd_child_to_parent[STDIN_FILENO]);
   wait(nullptr);

   return EXIT_SUCCESS;
}

int main(int const argc, char const* const* const argv)
{
   auto result = std::ranges::subrange(&argv[1], &argv[argc]);
   std::vector<std::string> args{ result.begin(), result.end() };

   return better_main(args);
}
