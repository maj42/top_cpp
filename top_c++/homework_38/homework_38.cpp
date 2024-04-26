#include <iostream>

class Dot {
public:
	Dot(float x, float y, float z) : x(x), y(y), z(z) {};
	Dot() : x(0), y(0), z(0) {};

	void print() {
		std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
	}

	void set(float newX, float newY, float newZ) {
		x = newX;
		y = newY;
		z = newZ;
	}

	float getX() {
		return x;
	}

	void setX(float newX = 0) {
		x = newX;
	}

	float getY() {
		return y;
	}

	void setY(float newY = 0) {
		y = newY;
	}

	float getZ() {
		return z;
	}

	void setZ(float newZ = 0) {
		z = newZ;
	}

private:
	float x{0};
	float y{0};
	float z{0};
};

int main()
{
	Dot dot1{ 1, 2, 3 };
	Dot dot2;

	dot1.print();
	dot2.print();

	dot1.set(12, 21, 33.3);
	dot2.setX(12.5);
	std::cout << dot1.getY() << std::endl;
	std::cout << dot2.getX() << std::endl;

	dot1.print();
	dot2.print();
}
