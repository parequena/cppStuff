#pragma once

#include <memory>

template <class T>
struct TNode
{
    // Ctor
    TNode(const T data, const TNode& node)
    : m_data{data}
    , m_next(std::make_unique(node->m_next->get()))
    {}

private:
    // Node's data.
    T m_data {};

    // Pointer to next.
    std::unique_ptr<TNode> m_next { nullptr };
};
