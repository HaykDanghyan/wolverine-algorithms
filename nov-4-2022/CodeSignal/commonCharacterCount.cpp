#include <iostream>
#include <string>
#include <algorithm>

int solution(std::string s1, std::string s2) {
    int c1[26] = {};
    int c2[26] = {};
    for (const auto& el : s1) {
        c1[el - 'a']++;
    }
    for (const auto& el : s2) {
        c2[el - 'a']++;
    }
    int returnValue = 0;
    for (int i = 0; i < 26; ++i) {
        returnValue += std::min(c1[i], c2[i]);
    }
    return returnValue;
}

