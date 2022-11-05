#include <iostream>
#include <algorithm>
#include <vector>

int solution(std::vector<int> statues) {
    auto max = *std::max_element(statues.begin(), statues.end());
    auto min = *std::min_element(statues.begin(), statues.end());
    return (max - min + 1) - statues.size();
}
