#include <iostream>
#include <vector>

int solution(std::vector<int> vec) {
    int el = -1001;
    for (int i = 0; i < vec.size() - 1; ++i) {
        int x1 = vec[i];
        int x2 = vec[i + 1];
        if (el < x1 * x2) {
            el = x1 * x2;
        }
    }
    return el;
}
