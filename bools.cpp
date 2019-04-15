#include <iostream>
#include <vector>
int main()
{
    std::vector<bool> v = {1,0,1,1};
    bool check = true;
    std::cout << "check: " << check << "\n";
    for(auto b: v)
    {
        if(!b)
        {
            check = false;
            break;
        }
        std::cout << "b: " << b << "\n";
    }
    std::cout << "check: " << check << "\n";

    return 0;
}