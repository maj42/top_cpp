#include <iostream>
#include <stack>
#include <sstream>

char EXIT_SIGN = 'q';

bool isSign(std::string& str) {
	if (str.length() != 1) return false;
	switch (str[0]) {
	case '+':
	case '-':
	case '*':
	case '/':
		return true;
	default:
		return false;
	}
}

bool exitSign(std::string& str) {
	if (str.length() == 1 && str[0] == EXIT_SIGN) return true;
	return false;
}

double calculate(std::stack<double>& stack, char sign) {
	double first, second;
	
	first = stack.top();
	stack.pop();

	if (stack.empty()) return first;

	second = stack.top();
	stack.pop();

	switch (sign) {
	case '+':
		return first + second;
	case '-':
		return first - second;
	case '*':
		return first * second;
	case '/':
		if (!first) return second;
		return second / first;
	}
}

int main()
{
	std::stack<double> calcStack;
	std::string input;
	std::cout << "Calculator!!! (q for exit)" << std::endl;

	while (1) {
		std::cin >> input;
		if (exitSign(input)) break;
		if (isSign(input) && !calcStack.empty()) {
			calcStack.push(calculate(calcStack, input[0]));
			std::cout << calcStack.top() << std::endl;
		}
		else {
			calcStack.push(std::stod(input));
		}
	}
	std::cout << "Thanks for using calculator!";
}
