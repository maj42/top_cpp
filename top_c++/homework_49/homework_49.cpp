#include <iostream>

template<typename... Grades>
double calcAverGrade(Grades... grades) {
    std::initializer_list<int> list{ grades... };
    int sum = 0;
    for (int grade : list) sum += grade;
    return double(sum) / sizeof...(grades);
}

int main()
{
    std::cout << calcAverGrade(10, 20, 30, 40, 50) << std::endl;
    std::cout << calcAverGrade(45) << std::endl;
    std::cout << calcAverGrade(1, 2, 3, 4, 5, 4, 4, 4, 4, 100) << std::endl;
}
