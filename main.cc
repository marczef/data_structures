#include "data_structures\inc\linked_list.h"

int main() {
    LinkedList list;
    list.insert(4);
    // list.insert(5);
    // list.insert(6);
    // list.insert(78);
    list.deleteEnd();
    list.print();
    std::cout<<"Hello word";
}