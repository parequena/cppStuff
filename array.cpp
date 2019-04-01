#include <iostream>

int main()
{
	//int** mat = nullptr;
	std::cout << "GetIn:\n";
	int x = 0;
	int y = 0;
	std::cin >> x  >> y;
	std::cout << "x: " << x  << "\ty: " << y << "\n";

	int **mat = new int*[x];
	
	for(int i = 0; i < x; i++)
	{
		for(int j = 0; j < y; j++)
		{
			mat[i] = new int[y];
			mat[i][j] = 1;
			std::cout << mat[i][j] << " ";
		}
		std::cout << "\n";
	}

	for(int i = 0; i < x; i++)
		delete[] mat[i];
	delete[] mat;
	return 0;
}
