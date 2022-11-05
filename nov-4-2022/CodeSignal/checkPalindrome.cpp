#include <iostream>

bool solution(std::string s) {
    int i = 0;
    int j = s.length() - 1;
    for (; i < s.length() / 2; ++i, --j) {
        if (s[i] != s[j]) {
           return false;
        }
    }
    return true;
}    