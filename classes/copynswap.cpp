#include <iostream>
#include <cstdint>
#include <cstring>

//
// MY CLASS
//
class MyClass
{
    // My Vector.
    int* m_myVect;

    // My Vector size.
    int m_vectSize;

    // Ctor.
    MyClass();

public:
    // Ctor.
    MyClass(const int size, const int value);

    // Copy Ctor.
    MyClass(const MyClass&);

    // Operator=.
    MyClass& operator=(MyClass);

    // Dtor.
    ~MyClass();

    // Operator<<
     friend std::ostream& operator<<(std::ostream& os, const MyClass& rhs);
};

// Ctor.
MyClass::MyClass():
    MyClass(0, 0)
{ }

// Ctor.
MyClass::MyClass(const int size, const int value):
    m_vectSize(size),
    m_myVect(new int[size]) {
        for(auto i = 0; i < size; ++i) {
            m_myVect[i] = value;
        }
}

// Copy Ctor.
MyClass::MyClass(const MyClass& rhs):
    m_vectSize(rhs.m_vectSize),
    m_myVect(new int[rhs.m_vectSize]) {
        std::memcpy(m_myVect, rhs.m_myVect, m_vectSize*sizeof(int));
        std::cout << "Copy ctor.\n";
}

// Operator=.
MyClass& MyClass::operator=(MyClass rhs) {
    std::swap(m_myVect, rhs.m_myVect);
    std::swap(m_vectSize, rhs.m_vectSize);

    std::cout << "operator=.\n";

    return *this;
}

// Dtor.
MyClass::~MyClass() {
    if(m_myVect) {
        delete m_myVect;
        m_myVect = nullptr;
    }

    m_vectSize = 0;
}

// Operator<<
std::ostream& operator<<(std::ostream& os, const MyClass& rhs) {
    os << "Size: " << rhs.m_vectSize << "\nV = [ ";
    for(auto i = 0; i < rhs.m_vectSize; ++i) {
        os << rhs.m_myVect[i] << " ";
    }
    os << "]\n";

    return os;
}

//
// MAIN
//
int main() {

    MyClass m1(3, 3);
    std::cout << m1;
    MyClass m2(m1);
    std::cout << m2;

    return 0;
}