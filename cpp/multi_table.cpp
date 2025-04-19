#include <iostream>
#include <sstream>
#include <string>

std::string multi_table(int number) {
	std::stringstream ss;

	for (int i = 1; i <= 10; ++i) {
		ss << i << " * " << number << " = " << i * number;

		if (i < 10) {
			ss << '\n';
		}
	}

	return ss.str();
}

int main() {
	std::cout << multi_table(5);

	return 0;
}