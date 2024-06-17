#include <iostream>
#define PI 3.14159265

namespace Shape {
	class Rectangle {
		double sizeA, sizeB;
	public:
		Rectangle(double A, double B) : sizeA(A), sizeB(B) {}
		double getSizeA() const { return sizeA; };
		double getSizeB() const { return sizeB; };
	};

	class Circle {
		double rad;
	public:
		Circle(double rad) : rad(rad) {}
		double getRad() const { return rad; };
	};
}

std::ostream& operator<<(std::ostream& os, Shape::Rectangle& shape) {
	std::cout << "Rectangle with sizes " << shape.getSizeA() << " and " << shape.getSizeB() << std::endl;
	return os;
}

std::ostream& operator<<(std::ostream& os, Shape::Circle& shape) {
	std::cout << "Circle with radius " << shape.getRad() << std::endl;
	return os;
}

namespace Utility {
	template<class T>
	void print(T shape) {
		std::cout << shape << std::endl;
	}

	template<class T>
	double perimeter(T shape) {
		if constexpr (std::is_same_v<T, Shape::Circle>) { return 2 * PI * shape.getRad(); }
		else if constexpr (std::is_same_v<T, Shape::Rectangle>) { return 2 * shape.getSizeA() + 2 * shape.getSizeB(); }
	}

	template<class T>
	double area(T shape) {
		if constexpr (std::is_same_v<T, Shape::Circle>) { return PI * shape.getRad() * shape.getRad(); }
		else if constexpr (std::is_same_v<T, Shape::Rectangle>) { return shape.getSizeA() * shape.getSizeB(); }
	}
}

int main() {
	Shape::Circle circle{ 10.2 };
	Shape::Rectangle rect{ 20, 10 };

	Utility::print(circle);
	Utility::print(rect);

	std::cout << "Perimeters: " << std::endl;
	std::cout << Utility::perimeter(circle) << std::endl;
	std::cout << Utility::perimeter(rect) << std::endl;

	std::cout << std::endl;

	std::cout << "Areas: " << std::endl;
	std::cout << Utility::area(circle) << std::endl;
	std::cout << Utility::area(rect) << std::endl;
}
