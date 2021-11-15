#include <iostream>
#include <cstddef>

#include "writeBin.hpp"
#include "readBin.hpp"

inline static std::string kFileName{"binary.bin"};

template <typename type_t>
void printVector(std::vector<type_t> const &vector)
{
    std::cout << "Vector [ ";
    for (auto v : vector)
        std::cout << static_cast<int>(v) << ' ';

    std::cout << "]\n";
}

int main(int, char **)
{
    constexpr std::size_t kSize{6};
    std::byte b{1};

    std::vector<std::byte> bytes{};
    bytes.reserve(kSize);

    for (auto i = 0; i < kSize; ++i)
        bytes.emplace_back(b << i);

    if (!writeBin(kFileName, bytes))
    {
        std::cerr << "No write\n";
        return EXIT_FAILURE;
    }

    std::vector<std::byte> read = readBin(kFileName);

    std::cout << "In:\n\t";
    printVector(bytes);
    std::cout << "Out:\n\t";
    printVector(read);

    return EXIT_SUCCESS;
}
