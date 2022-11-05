#include <iostream>

std::string evenOrOdd(int n) {
	int countof1 = 0;
	while (n != 0) {
		if (n & 1) {
			++countof1;
		}
		n >>= 1;
	}
	if (countof1 & 1) {
		return "odd";
	}
	return "even";
}

int main() {
	std::cout << evenOrOdd(10) << std::endl;
	return 0;
}
