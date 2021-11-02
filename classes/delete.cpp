#include <iostream>

class A
{
    int a = 0;
protected:
    virtual int getA() = 0;
    virtual void shoutA() = 0;
};

class B : A
{
int b = -1;

public:
    B() { b = -1; };
    B(int _b): b(_b) {};

    inline int getA() override { return b; };
    inline void shoutA() override { return; };
};

int main()
{
    B bb{3};
    B ba{};

    std::cout << "B->getA(): " << ba.getA() << "\n";
    std::cout << "B->getA(): " << bb.getA() << "\n";
}

