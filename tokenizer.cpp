#include <sstream>
#include <iostream>
#include <vector>

/*
Entradas posibles y significado:
Move
    M:R     : Move Right.
    M:L     : Move Left.
    M:U     : Move Up.
    M:D     : Move Down.

    M:X:Y   : Move on X direction and Y pixels.

Look
    L:R     : Look Right.
    L:L     : Look Left.
    L:U     : Look Up.
    L:D     : Look Down.

    L:X:Y   : Look on X direction and Y pixels.

Shoot
    S:R     : Shoot Right.
    S:L     : Shoot Left.
    S:U     : Shoot Up.
    S:D     : Shoot Down.

*/
enum class Actions { null, MOVE, LOOK, SHOOT };
enum class Axis { null, X, Y };
enum class Direction { null, POS, NEG };

class A
{
protected:
	std::string letters = "abcdefghijklmnopqrstuvwxyz";
	std::string numbers = "1234567890";

	int x = 0, y = 0;
	Actions act;
	Axis ax;
	Direction dir;

	std::vector<std::string> tokenize(const std::string& str)
	{
	    std::istringstream ss(str);
	    std::string token;

	    std::vector<std::string> tokens;
	    while(std::getline(ss, token, ' '))
	        tokens.push_back(token);

	    return tokens;
	    return {};
	}

public:
	A(int _x, int _y):
		x(_x), y(_y)
	{}
	virtual void update() = 0;
	inline int getX() { return x; }
	inline int getY() { return y; }
};

struct B : public A
{
	B(int _x, int _y): A(_x, _y) {}

	// Moving.
	void update() override
	{
		std::string str = "";
		std::cout << "Give me commands:\n";
		std::getline(std::cin, str);
		auto v1 = tokenize(str);

		int i = 0, j = 0, f = v1.size(), steps = 0;
		while(i < f)
		{
			while(v[i].size() >= 2) i++;
		}
		
	}
};

int main()
{
	A* a = new B(0, 0);
	std::cout << "x: " << a->getX() << "\ty: " << a->getY() << "\n"; 
	a->update();
	std::cout << "x: " << a->getX() << "\ty: " << a->getY() << "\n";
	return 0;
}