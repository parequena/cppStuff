#include <iostream>

struct A
{
    A(const std::string& s)
    : str(s)
    {
        std::cout << "A: " << str << '\n';
    }

    inline void printA() const
    {
        std::cout << "s: " << str << '\n';
    }

private:
    std::string str {};
};

struct B
{
    B(const std::string& s1, const std::string& s2)
    : a1(s1)
    , a2(new A(s2))
    {
        std::cout << "B\n";
    }

    // inline void deleteA1() { delete a1; }
    inline void deleteA2() { delete a2; a2 = nullptr; }
    inline void printB() const
    {
        a1.printA();
        if(a2) a2->printA();
    }

private:
    A& a1;
    A* a2 { nullptr };
};

int main()
{
    const std::string s1 { "s1" };
    const std::string s2 { "s2" };

    B b(s1, s2);

    b.printB();
    b.deleteA2();
    b.printB();

    return 0;
}