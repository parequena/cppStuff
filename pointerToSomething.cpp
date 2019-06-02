#include <iostream>

struct A
{
	int* id;
	int _id;
	
	A(int i)
	{
		_id = *id;
		id = new int(i);
	}
};

int main()
{
	A a(4);
	std::cout << " id: " << *(a.id) << "\n";
	std::cout << "_id: " << a._id << "\n";
}
