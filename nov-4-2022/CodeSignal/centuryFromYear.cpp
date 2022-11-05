#include <iostream>

int solution(int year) {
    if (!(year % 100)) {
        return year / 100;
    }
    return year / 100 + 1;
}