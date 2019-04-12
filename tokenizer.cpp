#include <string>
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
enum class Axis { null, X, Y };
enum class Direction { null, POS, NEG };

class A
{
protected:
	std::string letters = "abcdefghijklmnopqrstuvwxyz";
	std::string numbers = "1234567890";

	int x = 0, y = 0;
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
	}

public:
	A(int _x, int _y):
		x(_x), y(_y)
	{}
	virtual void update() = 0;
	inline int getX() { return x; }
	inline int getY() { return y; }

	virtual bool checkSyntax(const std::string& base)
	{
		return base.length() >= 3 && base.length() <= 5 && base[1] == ':' && (base.length() < 4 || base[3] == ':');
	}
};

struct B : public A
{
	B(int _x, int _y): A(_x, _y) {}

	void move(int& dir, int steps)
	{
		dir += steps;
	}

	bool checkSyntax(const std::string& base) override
	{
		return A::checkSyntax(base) && (base[0] == 'M' || base[0] == 'm');
	}

	// Moving.
	void update() override
	{
		std::string str = "";
		std::cout << "Give me commands:\n";
		std::getline(std::cin, str);
		auto v1 = tokenize(str);

		int action = 0, totalActions = v1.size(), steps = 0;
		std::string corr = "";
		while (action < totalActions)
		{
			W
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