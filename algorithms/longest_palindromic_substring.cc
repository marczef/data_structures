#include <iostream>
#include <stdint.h>
#include <string>

std::string longest_palindromic_substring(std::string palindrom) {
    std::string result {};

    for(size_t i=0; i < palindrom.size(); i++) {
        //odd cases
        auto left = i, right = i;
            while (left >= 0 and right != palindrom.size() and palindrom[left] == palindrom[right]) {
                if(result.size() < right - left + 1) {
                    result = palindrom.substr(left, right - left + 1);
                }
                left --;
                right ++;
            }
        //even cases
        left = i, right = i + 1;
        while (left >= 0 and right != palindrom.size() and palindrom[left] == palindrom[right]) {
            if(result.size() < right - left + 1) {
                result = palindrom.substr(left, right - left + 1);
            }
            left --;
            right ++;
        }
    }
    return result;
}