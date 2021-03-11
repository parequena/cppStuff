#include "Text.hpp"

Text_t::Text_t(std::string_view const& str) noexcept
    : m_str(str.data())
{

}

// Dtor.
Text_t::~Text_t() noexcept
{

}
