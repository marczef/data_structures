#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <algorithm>

uint8_t kadanes_algorithm(std::vector<int8_t> array) {
    int8_t curr_sum = array[0];
    auto max_sum = curr_sum;
    int8_t start = 0, end = 0, curr_index =0;
    for(size_t i=1; i<array.size(); i++)
    {   
        if (curr_sum + array[i] < array[i]) {
            curr_sum = array[i];
            curr_index = i;
        }
        else {
            curr_sum = curr_sum + array[i];
        }
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
            start = curr_index;
            end = i + 1;
        }
    }

    std::vector<int8_t> subarray {array.begin() + start, array.begin() + end};
    for (int i = 0; i < subarray.size(); i++)
        printf("%i ", subarray[i]);

    printf("%i\n", max_sum);
    return max_sum;

}
