#include <iostream>
#include <cmath>
#include <string>
using namespace std;
//Создайте структуру, описывающую простую
//дробь.Реализуйте арифметические операции с дробями :
//сумму, разность, умножение, деление
struct Fraction {
    int num;
    int den;
    
    string print() {
        return to_string(num) + "/" + to_string(den);
    }
};

int gcd(int a, int b) { // функция нахождения наибольшего общего делителя
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void reduceFraction(Fraction& frac) { // сокращение дроби
    int divisor = gcd(frac.num, frac.den);
    frac.num /= divisor;
    frac.den /= divisor;
}

void impoperToMixed(Fraction& frac) { // преобразование неправильной в простую
    int wholePart = frac.num / frac.den;
    frac.num %= frac.den;
    if (wholePart != 0) {
        std::cout << wholePart << " ";
    }
    std::cout << frac.num << "/" << frac.den << std::endl;
}

Fraction add(const Fraction& frac1, const Fraction& frac2) {
    int commDen = frac1.den * frac2.den;
    int resNum = frac1.num * (commDen / frac1.den) + frac2.num * (commDen / frac2.den);
    Fraction result{ resNum, commDen };
    reduceFraction(result);
    return result;
}

Fraction subtr(const Fraction& frac1, const Fraction& frac2) {
    int commDen = frac1.den * frac2.den;
    int resNum = frac1.num * (commDen / frac1.den) - frac2.num * (commDen / frac2.den);
    Fraction result{ resNum, commDen };
    reduceFraction(result);
    return result;
}

Fraction prod(const Fraction& frac1, const Fraction& frac2) {
    Fraction result{ frac1.num * frac2.num, frac1.den * frac2.den };
    reduceFraction(result);
    return result;
}

Fraction div(const Fraction& frac1, const Fraction& frac2) {
    Fraction result{ frac1.num * frac2.den, frac1.den * frac2.num };
    reduceFraction(result);
    return result;
}

int main()
{
    Fraction frac1 = { 7,4 };
    Fraction frac2 = { 1, 3 };
    
    Fraction addRes = add(frac1, frac2);
    Fraction subtrRes = subtr(frac1, frac2);
    Fraction prodRes = prod(frac1, frac2);
    Fraction divRes = div(frac1, frac2);

    
    cout << frac1.print() << " + " << frac2.print() << " = " << addRes.print() << endl;
    cout << frac1.print() << " - " << frac2.print() << " = " << subtrRes.print() << endl;
    cout << frac1.print() << " * " << frac2.print() << " = " << prodRes.print() << endl;
    cout << frac1.print() << " / " << frac2.print() << " = " << divRes.print() << endl;
}
