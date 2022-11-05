#include <iostream>

bool powerof2(int n) {
	return !(n & (n - 1));
}

int main() {
	std::cout << std::boolalpha << powerof2(4);
}
