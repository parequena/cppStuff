#include <iostream>
#include <memory>

// template <class T>
// void printPointer(const std::unique_ptr<T>& ptr)
// {
//     std::cout << "Ptr: " << *(ptr.get()) << "\n";
// }

// Rule of zero?
template <class T>
class myStruct
{
    int m_timesToPrint{0};
    std::unique_ptr<T> m_ptr;

public:
    myStruct(int tToPrint, const T& val)
    : m_timesToPrint(tToPrint), m_ptr(std::make_unique<T>(val))
    { }

    myStruct() = default;
    myStruct(const myStruct&) = default;
    
    

    friend std::ostream& operator<<(std::ostream& os, const myStruct<T>& rhs)
    {
        for(auto i = 0; i < rhs.m_timesToPrint; ++i)
        {
            os << *(rhs.m_ptr.get()) << "\n";
        }
        os << "---------------\n";
        return os;
    }
};



int main()
{
    // printPointer(std::move(std::make_unique<int>(3)));
    // printPointer(std::move(std::make_unique<std::string>("String pointer")));

    myStruct<int> m1(3, 3);
    myStruct<int> m2 = m1;
    // myStruct<std::string> m3(2, std::make_unique<std::string>("Hello"));

    std::cout << m1;
    std::cout << m2;
    // std::cout << m3;

    return 0;
}