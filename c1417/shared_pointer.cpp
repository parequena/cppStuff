#include <iostream>
#include <memory>

struct myStruct
{
    int m_int{0};
    myStruct(int t_int): m_int{t_int} {}
};

int main()
{
    std::shared_ptr<myStruct> s1;
    // std::cout << "Int s1: " << s1->m_int << "\n"; // We cannot call s1, because its pointing to nullptr (?).

    { // Create a new ambit
        std::shared_ptr<myStruct> s2 = std::make_shared<myStruct>(3);
        std::cout << "Int s2: " << s2->m_int << "\n";
        s1 = s2;
    }

    std::cout << "Int s1: " << s1->m_int << "\n";
    // std::cout << "Int s2: " << s2->m_int << "\n"; // Compiler doesn't know s2, because we exited the ambit, and s2 was destroyed.

    return 0;
}