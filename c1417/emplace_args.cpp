#include <iostream>
#include <vector>
#include <string>

int main(int argc, const char *argv[])
{
    std::vector<std::string> args;
    args.reserve(argc);

    for(auto i = 0; i < argc; ++i)
        args.emplace_back(argv[i]);

    for(auto i = 0; i < args.size(); ++i)
    {
        std::cout << "Arg[" << i << "]: " << args[i] << '\n';
    }

    return 0;
}