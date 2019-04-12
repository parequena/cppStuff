#include <iostream>

class A
{
protected:
    static int g_id;
    int id = 0;
public:
    A() { id = ++g_id; }
    virtual void getId() { std::cout << "id: " << id << "\n"; }
};

// Init id.
int A::g_id = 0;

class B : public A
{
    std::string name = "";
public:
    B(): B("noname") {}
    B(const std::string& s): name(s) {}

    void getId() override
    {
        std::cout << "name: " << name << " ";
        A::getId();
    }
};

int main()
{
    B b1;
    B b2("Pablo");

    b1.getId();
    b2.getId();
}