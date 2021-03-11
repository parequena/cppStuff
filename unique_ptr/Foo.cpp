#include "Foo.hpp"
#include "Text.hpp"

Foo_t::Foo_t(int n) noexcept
    : Foo_t(n, "")
{

}

// Ctor.
Foo_t::Foo_t(int n, std::string_view const& str) noexcept
    : m_n(std::make_unique<int>(n))
    , m_text(std::make_unique<Text_t>(str))
{
    
}

// Dtor.
Foo_t::~Foo_t() noexcept
{

}

// say text.
void Foo_t::sayText() const noexcept
{
    std::cout << "-----------\n";
    const int n = *(m_n.get());

    for(auto i { 0 }; i < n; ++i)
        m_text->say();
}