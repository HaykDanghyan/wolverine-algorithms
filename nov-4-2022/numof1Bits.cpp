#include <iostream>

int numof1Bits(int n) {
	int count = 0;
	while (n) {
		if (n & 1) {
			++count;
		}
		n >>= 1;
	}
	return count;
}

int main() {
	std::cout << numof1Bits(15) << std::endl;
}
