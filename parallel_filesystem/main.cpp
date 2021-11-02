/*
    Project: [[ None ]]
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2021
*/

// Compilation:
//      g++ -std=c++20 main.cpp -o main -Wall -Wextra -Wpedantic -Werror -ltbb
// Execution:
//      ./main

#include <iostream>
#include <filesystem>
#include <execution>
#include <algorithm>

static const std::string path{"folder"};

int main()
{
    namespace fs = std::filesystem;

    // std::for_each(std::execution::par_unseq, b, e, fnc);

    auto const &dir = fs::directory_iterator{path};

    auto b = std::begin(dir);
    auto e = std::end(dir);

    // std::for_each(std::execution::par_unseq, dir.begin(), dir.end(),
    //               [](auto const &d)
    //               {
    //                   std::cout << "File: " << d << '\n';
    //               });

    return EXIT_SUCCESS;
}