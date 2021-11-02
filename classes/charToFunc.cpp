#include <iostream>

struct Parent
{
    // Ctor.
    Parent()
        : Parent(0)
    { }
    
    // Ctor.
    Parent(int val)
        : m_val(val)
    { }

    // Set Val
    void setVal(int val)
    {
        if (val < 0) return;
        if (val < 4) m_val = val;
    }

    void caller()
    {
        IntToFunc* k = ItoM;

        while (k->in != 0)
        {
            if (k->in == m_val)
            {
                k->ac();
                return;
            }
        	
            ++k;
        }

    }

private:
    // Value.
    int m_val{ 0 };

private:
    struct IntToFunc
    {
        int in;
        void (*ac)();
    };

    static inline IntToFunc ItoM[] =
    {
        {1, []() { std::cout << "1\n"; } },
        {2, []() { std::cout << "19\n"; } },
        {3, []() { std::cout << "50\n"; } },
        {0, nullptr}
    };
};

int main()
{
    Parent p;
    int r { 0 };

    do
    {
        std::cout << "Tell my why?  ";
        std::cin >> r;
        p.setVal(r);
        p.caller();

    } while (r != 0);

    return 0;
}