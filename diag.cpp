#include <iostream>
#include <vector>
#include <chrono>

std::vector<int> getDiag(const std::vector<std::vector<int>>& mat)
{
    if(mat.size() != mat[0].size()) return {};

    std::vector<int> ret;
    ret.reserve(mat.size());

    for(auto i = 0; i < mat.size(); ++i)
    {
        for(auto j = 0; j < mat[0].size(); ++j)
        {
            if(i == j) ret.emplace_back(mat[i][j]);
        }
    }

    return ret;
}

std::vector<int> getDiag(const int nr, const int nc, const std::vector<int>& mat)
{
    if(nr != nc) return {};

    std::vector<int> ret;
    ret.reserve(nr);

    int c = 0;
    for(auto i = c; i < mat.size(); ++c, i+=nc)
        ret.emplace_back(mat[i + c]);

    return ret;
}

void printVect(const std::vector<int>& vec)
{
    for(auto v : vec)
        std::cout << v << "\t";
    std::cout << "\n";
}

void print(const std::vector<std::vector<int>>& mat)
{
    for(auto i = 0; i < mat.size(); ++i)
        printVect(mat[i]);
}

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cerr << "ERROR: Try ./exe <matSize>\n";
        return -1;
    }

    int size = std::atoi(argv[1]);
    int nr = size, nc = size;
    std::vector<std::vector<int>> mat;
    std::vector<int> matPlain;

    for(auto i = 0; i < nr*nc; ++i)
        matPlain.push_back(i);

    mat.resize(nr);
    for(auto i = 0, aux = 0; i < nr; ++i)
    {
        mat[i].resize(nc);
        for(auto j = 0; j < nc; ++j, aux++)
        {
            mat[i][j] = aux;
        }
    }

    
    // std::cout << "matPlain\n";
    // printVect(matPlain);
    // std::cout << "--------\n";

    // std::cout << "Mat\n";
    // print(mat);
    // std::cout << "--------\n";

    std::cout << "Diag\n";
    auto st1 = std::chrono::steady_clock::now();
    auto d1 = getDiag(mat);
    auto ed1 = std::chrono::steady_clock::now();
    // printVect(d1);
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(ed1 - st1).count() << "\n";
    std::cout << "--------\n";

    std::cout << "Diag plain\n";
    auto st2 = std::chrono::steady_clock::now();
    auto d2 = getDiag(nr, nc, matPlain);
    auto ed2 = std::chrono::steady_clock::now();
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(ed2 - st2).count() << "\n";
    // printVect(d2);
    std::cout << "--------\n";

    return 0;
}