#include <iostream>
#include <queue>

int main()
{
    int k = 4;
    std::queue<int> fifo;

    for(int i = 0; i < k; ++i)
        fifo.push(i);

    for(int i = 0; i < k; ++i)
    {
        std::cout << fifo.front() << " ";
        fifo.pop();
    }
    std::cout << "\n";

    return 0;
}