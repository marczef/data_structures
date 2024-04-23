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

void LinkedList::insert(uint8_t value) {
    auto currNode = head;
    Node newNode(value);

    if(head == nullptr) {
        head = std::make_shared<Node>(newNode);
    }
    else {
        while(currNode->next != nullptr) {
            currNode = currNode->next;
        }
        currNode->next = std::make_shared<Node>(newNode);
    }
}

void LinkedList::deleteNode(uint8_t value) {
    auto currNode = head;
    std::shared_ptr<Node> prevNode = nullptr;

    if(head == nullptr) {
        printf("No nodes to delete");
    }
    else {
        while(currNode != nullptr) {
            if(currNode->data == value) {
                if(currNode == head) {
                    head = head->next;
                }
                else {
                    prevNode->next = currNode->next;
                }
            }
            else {
                prevNode = currNode;
            }
            currNode = currNode->next;
        }
    }
}

void LinkedList::deleteBeginning() {
    if(head == nullptr) {
        printf("No nodes to delete");
    }
    else {
        head = head->next;
    }
}

void LinkedList::deleteEnd() {
    if(head == nullptr) {
        printf("No nodes to delete");
    }
    else if(head->next == nullptr) {
        head = nullptr;
    }

    else {
        for(auto currNode{head->next}, prevNode{head}; currNode != nullptr; currNode = currNode->next, prevNode = prevNode->next) {
            if(currNode->next == nullptr) {
                prevNode->next = nullptr;
            }
        }

    }
}

void LinkedList::print() {
    auto currNode = head;
    uint8_t nrOfNode = 0;

    if(head == nullptr) {
        printf("empty list");
    }

    else {
        while(currNode != nullptr) {
            printf("Node numer: %u, value: %u \n",nrOfNode, currNode->data);
            nrOfNode ++;
            currNode = std::move(currNode->next);
        }
    }
}

int main() {
    LinkedList list;
    list.insert(4);
    // list.insert(5);
    // list.insert(6);
    // list.insert(78);
    list.deleteEnd();
    list.print();
}