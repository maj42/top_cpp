#include <iostream>
#define sq(a) (a)*(a)

class Point {
public:
	Point(float x, float y, float z) : x(x), y(y), z(z) {};
	Point() : x(0), y(0), z(0) {};

	void changePoint(float chX, float chY, float chZ) {
		this->set(x + chX, y + chY, z + chZ);
	}

	float calcDist(const Point& other = Point()) {
		return (sqrt(sq(x - other.x) + sq(y - other.y) + sq(z - other.z)));
	}

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
	Point point1{ 1, 2, 3 };
	Point point2;

	std::cout << "Created two dots: " << std::endl;
	point1.print();
	point2.print();

	std::cout << "Setting coordinates: " << std::endl;
	point1.set(12, 21, 33.3);
	point2.setX(12.5);
	std::cout << point1.getY() << std::endl;
	std::cout << point2.getX() << std::endl;
	point1.print();
	point2.print();

	std::cout << "Moving point1: " << std::endl;
	point1.changePoint(-10, -23, 1000);
	point1.print();
	point2.print();

	std::cout << "Calculating distance between points: " << std::endl;
	std::cout << point1.calcDist(point2) << std::endl;
}
