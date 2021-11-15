#ifndef READ_BIN_HPP
#define READ_BIN_HPP

#include <cstdint>
#include <vector>
#include <fstream>

std::vector<std::byte> readBin(std::string const &fileName)
{
    std::ifstream file(fileName, std::ifstream::binary);

    if (!file)
    {
        std::cerr << "ERROR, FILE: " << fileName << " not found.\n";
        return {};
    }

    const auto fileSize = [&]() -> std::size_t
    {
        file.seekg(0, std::ifstream::end); // Go to end.
        const auto lenght{file.tellg()};   // Get actual position.
        file.seekg(0, std::ifstream::beg); // Go to begin.
        return lenght;
    }();

    std::vector<std::byte> bytes;
    bytes.resize(fileSize);

    file.read(reinterpret_cast<char *>(bytes.data()), fileSize); // To read properly, data must be initialized!
    file.close();

    return bytes;
}

#endif /* READ_BIN_HPP */
