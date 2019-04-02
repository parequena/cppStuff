#include <iostream>
#include <stdlib.h>

int main(int argc, char** argv)
{
	srand (time(NULL));
	
	if(argc < 3)
		return -1;

	int x = atoi(argv[1]), y = atoi(argv[2]);

	switch(rand() % 4)
	{
		case 0:
			++x;
		break;

		case 1:
			--x;
		break;

		case 2:
			++y;
		break;

		case 3:
			--y;
		break;
	}

	std::cout << x << " " << y << "\n";

	return 0;
}
