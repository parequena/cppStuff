#include <iostream>
#include <stdio.h>
#include <tensorflow/c/c_api.h>

int main()
{
	std::cout << "TensorFlow: " << TF_Version() << "\n";
	return 0;
}
