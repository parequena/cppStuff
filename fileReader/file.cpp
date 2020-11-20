#include <iostream>
#include <fstream>
#include <string_view>
#include <vector>

constexpr auto K_fileName { "fichero.txt" };

struct Archivo
{
    Archivo(const std::string_view fileName)
        : m_fileName(fileName)
        , m_file(fileName.data())
    {
        if(!m_file.good())
        {
            std::cerr << "File: " << m_fileName << " couldn't be opened.\n";
        }
    }


    void read()
    {
        if(!m_file.good())
        {
            std::cerr << "File: " << m_fileName << " is not open.\n";
            return;
        }

        std::string line;
        while(std::getline(m_file, line))
        {
            m_fileStr.push_back(line);
            line.clear();
        }
    }

    void printFile() const
    {
        auto line = 1;
        for(const auto& l : m_fileStr)
        {
            std::cout << line << ": " << l << "\n";
            ++line;
        }
    }

    ~Archivo()
    {
        m_file.close();
    }

    // File name.
    const std::string& FileName() const { return m_fileName; }

private:
    // FileName
    std::string m_fileName;

    // File
    std::ifstream m_file;

    // All hte file.
    std::vector<std::string> m_fileStr;
};

int main()
{
    Archivo file(K_fileName);

    std::cout << "Nombre del fichero: " << file.FileName() << "\n";
    file.read();
    file.printFile();

    return 0;
}