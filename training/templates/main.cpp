#include <iostream>

// Typename ou class
template <typename T>

void displayValue(const T &value) {
	std::cout << value << std::endl;
}

int main(void) {
	int a = 5;
	float b = 5.12f;
	char c = 'c';
	std::string s = "string";

	displayValue(a);
	displayValue(b);
	displayValue(c);
	displayValue(s);
}