#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>

template <typename T>
struct GestionedVector
{
    void print() const noexcept
    {
        std::cout << "\n-------------------\nLast: " << lastValid_ << "\t||\t";
        std::cout << "Vect: [ ";
        for (std::size_t i{}; i < lastValid_; ++i)
        {
            std::cout << data_[i] << ", ";
        }
        std::cout << "]\n";
    }

    template <typename... Args>
    constexpr T &add(Args &&... args) noexcept
    {
        auto const &size{data_.size()};
        std::cout << "Size: " << size << "\t\t";
        std::cout << "Last: " << lastValid_ << '\n';

        if (size == lastValid_)
        {
            ++lastValid_;
            return data_.emplace_back(std::forward<Args>(args)...);
        }

        auto &cmp = data_[lastValid_];
        cmp = T{std::forward<Args>(args)...};
        ++lastValid_;
        return cmp;
    }

    constexpr void remove_idx(std::size_t idx)
    {
        if (idx >= data_.size())
        {
            throw std::out_of_range("Index MUST be lesser than vector size!");
        }

        std::iter_swap(data_.end() - 1, data_.begin() + idx);
        --lastValid_;
    }

    constexpr void remove(T &&val)
    {
        auto p = std::find(data_.begin(), data_.end(), std::forward<T>(val));
        if (p == data_.end())
        {
            throw std::invalid_argument("Value must exist on the vector!");
        }

        remove_idx(p - data_.begin());
    }

private:
    std::vector<T> data_{};
    std::size_t lastValid_{};
};

int main()
{
    GestionedVector<float> gv;

    gv.add(8.f);
    gv.add(16.f);
    gv.add(32.f);
    gv.add(48.f);

    // gv.remove_idx(1);
    gv.remove(16.f);
    gv.add(100.f);

    gv.print();
}