/*
Creación de una lista enlazada "TList" que tenga los siguientes métodos:
    a. std::size_t Size();                  // Retorna el número de elemmentos.
    b. void Push(const std::string& str);   // Añade la cadena a la lista.
    c. std::string First();                 // Retorna el primer elemeto de la lista.
    d. std::string Next();                  // Retrona el siguiente lemento de la lista.
    e. std::string& Pop();                  // Elimina y retorna el primer elemento de la lista.
    f. void Reset();                        // Elimina todos los elementos de la lista.
*/

#include <iostream>
#include <memory>

struct TList
{
    // Ctor.
    TList(const std::string& str);

    // Get size.
    std::size_t Size() const;

    // Push an element.
    void Push(const std::string& str);

    // Get first element.
    std::string First() const;

    // Get next element;
    std::string Next() const;

    // Pop first element.
    std::string& Pop();

    // Reset the list.
    void Reset();

private:
    // Node.
    struct TNode
    {
        // Data
        const std::string m_data{};

        // Next
        std::unique_ptr<TNode> m_next { nullptr };

        TNode(const std::string& str)
        : m_data{str}
        , m_next{ nullptr }
        {}

        TNode(const std::string& str, TNode* node)
        : m_data{str}
        , m_next{node}
        {}
    };

    // Node list.
    std::unique_ptr* m_node { nullptr };
};

int main()
{
    return 0;
}

// Ctor.
TList::TList(const std::string& str)
{

}