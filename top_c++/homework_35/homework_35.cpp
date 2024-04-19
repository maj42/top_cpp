#include <iostream>
#include <sstream> // double to string with precision
#include <complex> // complex numbers

using namespace std;

string doubleToStr(const double num, int prec = 6) {
    ostringstream ss;
    ss.precision(prec);
    ss << num;
    return move(ss).str();
}

//ax + b = 0
template <typename T> string findRoots(T a, T b) {
    return "Root is " + doubleToStr(double(-b) / a);
}

//ax^2 + bx + c = 0
template <typename T> string findRoots(const T a, const T b, const T c) {
    if (!a) {
        string root = findRoots(b, c);
        return "It's a linear function. " + root;
    }
    double discr = b * b - 4 * a * c;
    if (discr > 0) {
        double first = (-b + sqrt(discr)) / 2 * a;
        double second = (-b - sqrt(discr)) / 2 * a;
        return "There are two real roots: " + doubleToStr(first) + " and " + doubleToStr(second);
    }
    else if (!discr) {
        double root = (double(-b) / 2 * a);
        return "There is one real root: " + doubleToStr(root);
    }
    else {
        complex<double> first ((double)(-b) / 2 * a, sqrt(-discr) / 2 * a );
        complex<double> second((double)(-b) / 2 * a, -sqrt(-discr) / 2 * a );
        return "There are two complex roots: " + doubleToStr(first.real()) + " + " + doubleToStr(first.imag()) + "i and "
            + doubleToStr(second.real()) + " + " + doubleToStr(second.imag()) + "i";
    }
}

int main()
{
    cout << findRoots(2, 5) << endl;
    cout << findRoots(0, 2, 5) << endl;
    cout << findRoots(2.4, 4.4, 0.6) << endl;
    cout << findRoots(2, 3, 17) << endl;
}