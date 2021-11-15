#ifndef WRITE_BIN_HPP
#define WRITE_BIN_HPP

#include <vector>
#include <string>
#include <fstream>

bool writeBin(std::string const &fileName, std::vector<std::byte> const &bytes)
{
    std::ofstream fileBin(fileName, std::ostream::binary | std::ostream::trunc); // Bin type, trunc to delete.

    if (!fileBin)
    {
        std::cerr << "ERROR: Couldn't open file: " << fileName << '\n';
        return false;
    }

    fileBin.write(reinterpret_cast<const char *>(bytes.data()), bytes.size() * sizeof(bytes[0]));
    fileBin.close();

    return true;
}

#endif /* WRITE_BIN_HPP */
