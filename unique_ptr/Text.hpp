#ifndef TEXT_HPP
#define TEXT_HPP

#include <string_view>
#include <string>
#include <iostream>

struct Text_t
{
    // Ctor.
    explicit Text_t(std::string_view const& str) noexcept;

    // Dtor.
    ~Text_t() noexcept;

    // sayHello
    inline void say() const noexcept
    {
        std::cout << "Text_t: " << m_str << "\n";
    }

private:
    std::string m_str{};
};

#endif // TEXT_HPP
