#include <iostream> // std::cout
#include <iterator> // std::size_t

template <class T, std::size_t N>
struct Array
{
    using FixArray = Array<T,N>;
    
    // Ctor.
    Array()
        : m_size{ 0 }
        , m_capacity{ N }
        , m_data{ new T[N] }
    { }

    // Ctor.
    Array(const T& e)
    : m_size{ N }
    , m_capacity{ N }
    , m_data{ new T[N] }
    {
        for(auto i = 0; i < N; ++i)
            m_data[i] = e;
    }

    // Dtor.
    ~Array()
    {
        delete[] m_data;
        m_data = nullptr;
    }

    // Operator=.
    inline const T& operator[](const std::size_t idx) const
    {
        if(idx < 0 || idx >= N) throw std::logic_error("Array index out of bounds");
        
        return m_data[idx];
    }

    // Operator=.
    // inline T& operator[](const std::size_t idx) { return const_cast<T&>(const_cast<const FixArray*>(this)->operator[](idx)); }

    // getSize.
    inline std::size_t size() const { return m_size; }

    // getCapacity.
    inline std::size_t capacity() const { return m_capacity; }

    // push_back.
    void push_back(const T& emt)
    {
        if(m_size == m_capacity) return;

        m_data[m_size] = emt;
        ++m_size;
    }

    // clear.
    void clear()
    {
        for(auto i =  0; i < m_capacity; ++i)
            pop_back();
    }

    // pop_back.
    void pop_back()
    {
        if(m_size == 0) return;

        m_data[m_size] = NULL;
        --m_size;
    }


    // cout.
    friend std::ostream& operator<<(std::ostream& os, const FixArray& arr)
    {
        os << "Arr: [ ";
        for(auto i = 0; i < arr.size(); ++i)
        {
            os << arr[i] << " ";
        }
        os << "]";

        return os;
    }

private:
    // Vector size.
    std::size_t m_size { 0 };

    // Vector capacity.
    std::size_t m_capacity { 0 };

    // Data.
    T* m_data { nullptr };
};


int main()
{
    // Create the array.
    constexpr int size = 3;
    Array<int, size> arr;

    // Fill the vector.
    for(auto i = 0; i < size; ++i)
        arr.push_back(size);
    std::cout << arr << "\n";

    // Erase last element.
    arr.pop_back();
    std::cout << arr << "\n";

    // Push an element.
    arr.push_back(4);
    std::cout << arr << "\n";

    // Clear the vector.
    arr.clear();
    std::cout << arr << "\n";

    // Create an other array.
    Array<std::string, 2> arr2("Hola");
    std::cout << arr2 << "\n";

    return 0;
}