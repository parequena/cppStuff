#include <unistd.h>
#include <iostream>

int main()
{
    int child_frame = 0;
    char child_buffer[1024];
    do{
        std::cin >> child_buffer; //wait for father's messages
        std::cout << "CHILD received: " << child_buffer<< " at frame " << child_frame << "\n"; //return message to father
    }while(++child_frame);

    return 0;
}