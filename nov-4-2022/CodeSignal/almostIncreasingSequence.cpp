#include <iostream>
#include <vector>

bool solution(std::vector<int> sequence) {
    int x1 = 0;
    int x2 = 0;
    for (int i = 0; i < sequence.size() - 1; ++i) {
        if (sequence[i] >= sequence[i + 1]) {
            ++x1;
        }
    }
    for (int i = 0; i < sequence.size() - 2; ++i) {
        if (sequence[i] >= sequence[i + 2]) {
            ++x2;
        }
    }
    if (x1 < 2 && x2 < 2) {
        return true;
    }
    return false;
}

