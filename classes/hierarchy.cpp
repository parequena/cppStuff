#include <iostream>
#include <string>

struct Parent
{
    explicit Parent(const std::string_view str)
        : m_str(str)
    {}

    constexpr void saySomething() const
    {
        p_saySomething();
    }

protected:
    std::string m_str{""};

private:
    virtual void p_saySomething() const
    {
        std::cout << m_str.data() << '\n';
    }
};

struct Child1 : Parent
{
    explicit Child1(const std::string_view str, int nTimes)
        : Parent(str)
        , m_nTimes(nTimes) 
    {}

private:
    int m_nTimes{0};

    virtual void p_saySomething() const
    {
        for(auto i = 0; i < m_nTimes; ++i)
            std::cout << m_str.data() << '\n';
    }
};


int main()
{
    Parent p{"Hello I'm the parent"};
    p.saySomething();

    Child1 c{"I'm not your son!", 3};
    c.saySomething();
}