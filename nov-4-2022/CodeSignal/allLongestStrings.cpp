#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> solution(std::vector<std::string> vec) {
    std::vector<std::string> tmp;
    int max_length = vec[0].length();
    for(int i = 0; i < vec.size(); i++) {
        if(max_length < vec[i].length()) {
            max_length = vec[i].length();
        }
    }
    for(int i = 0; i < vec.size(); i++) {
        if(max_length == vec[i].length()) {
            tmp.push_back(vec[i]);
        }
    }
    return tmp;
}

