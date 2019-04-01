#include <iostream>

int main(int argc, char** argv)
{
    if(argc < 3)
    {
        std::cerr << "3 argumentos\n";
        return -1;
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    std::cout << "x: " << x << "\ty: " << y << "\n";

    int** mat = new int[x][];
    for(int i = 0; i < x; ++i)
        mat[i] = new int[y];

    /*for(int i = 0; i < x; ++i)
        delete[] mat[i];*/

    delete[] mat;
}