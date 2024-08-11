#include <iostream>
#include <stdint.h>
#include <stack>

void insert_at_bottom(std::stack<int8_t> &stack, int8_t new_bottom) {
    if (stack.size() > 0) {
        auto top = stack.top();
        stack.pop(); 
        insert_at_bottom(stack, new_bottom);
        stack.push(top);
    }
    else 
        stack.push(new_bottom);
}

void reverse_stack(std::stack<int8_t> &stack) {
    if (stack.size() > 0) {
        auto top = stack.top();
        stack.pop();
        reverse_stack(stack);
        insert_at_bottom(stack, top);
    }
}

void print(std::stack<int8_t> &stack) {
    if (!stack.empty()) {
        auto top = stack.top();
        stack.pop();
        print(stack);
        printf("%i ", top);
        stack.push(top);
    }
}

// int main() {
//     std::stack<int8_t> stack({1, 2, 3, 4, 5});
//     reverse_stack(stack);
//     print(stack);
// }