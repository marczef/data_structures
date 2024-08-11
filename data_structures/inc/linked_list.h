#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <memory>

class Node {
    public:
    uint8_t data;
    std::shared_ptr<Node> next;

    Node(std::shared_ptr<Node>& node_) : data(node_.get()->data), next(std::move(node_.get()->next)) {}
    Node() : data(0), next(nullptr) {}
    Node(uint8_t data_) : data(data_), next(nullptr) {}
    Node(uint8_t data_, std::shared_ptr<Node> next_) : data(data_), next(std::move(next_)) {}
};

class LinkedList {
    private:
    std::shared_ptr<Node> head;
    
    public:
    LinkedList() : head(nullptr) {}

    void insert(uint8_t value);
    void deleteNode(uint8_t value);
    void deleteBeginning();
    void deleteEnd();
    void print();
};