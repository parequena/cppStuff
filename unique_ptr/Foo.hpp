#ifndef FOO_HPP
#define FOO_HPP

#include <memory>
#include <iostream>
#include <string_view>

struct Text_t;

struct Foo_t
{
    // Ctor.
    explicit Foo_t(int n) noexcept;

    // Ctor.
    explicit Foo_t(int n, std::string_view const& str) noexcept;

    // Dtor.
    ~Foo_t() noexcept;

    // sayHello
    inline void say() const noexcept
    {
        std::cout << "Foo: Hello!\n";
    }

    // say text.
    void sayText() const noexcept;

private:
    std::unique_ptr<int> m_n { nullptr };
    std::unique_ptr<Text_t> m_text { nullptr };
};

#endif // FOO_HPP
