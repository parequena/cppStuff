#include <iostream>
#include <vector>
#include <cstdint>

using VecInt = std::vector<int>;

struct Dummy
{
    Dummy(std::size_t size)
    {
        m_nums.reserve(size);
        for(auto i = 0; i < size; ++i)
            m_nums.emplace_back(i);
    }

    // This one will return an const reference (non modificable)
    inline const VecInt& getNums() const
    {
        std::cout << "const\n";
        return m_nums;
    }

    // This one will retrun a reference (modificable)
    inline       VecInt& getNums()      
    {
        std::cout << "non const\n";
        return const_cast<VecInt&>(const_cast<const Dummy*>(this)->getNums());
    }

private:
    VecInt m_nums {};
};

void printNumbers(const VecInt& vect)
{
    std::cout << "Vec:\t[ ";
    for(const auto& v : vect)
        std::cout << v << " ";
    std::cout << "]\n";
}

int main()
{
    Dummy dd(3);
    const Dummy cdd(6);

    printNumbers(dd.getNums());
    printNumbers(cdd.getNums());

    return 0;
}