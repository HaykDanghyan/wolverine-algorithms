#include <iostream>

void swapBits(int& n, int i, int j) {
	if ((n & (1 << i)) and !(n & (1 << j))) {
		n |= (1 << j);
		n ^= (1 << i);
	} 
	if (!(n & (1 << i)) and (n & (1 << j))) {
		n ^= (1 << j);
		n |= (1 << i);
	}
}

int main() {
	int n = 15;
	swapBits(n, 1, 5);
	std::cout << n << std::endl;
	return 0;
}
