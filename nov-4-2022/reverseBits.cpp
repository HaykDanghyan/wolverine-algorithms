#include <iostream>

void reverseBits(int& n) {
	for (int i = 0; i < 8; ++i) {
		if (n & (1 << i)) {
			n ^= (1 << i);
		} else {
			n |= (1 << i);
		}
	}
}

int main() {
	int n = 15;
	reverseBits(n);
	std::cout << n << std::endl;
}
