#include "../inc/linked_list.h"

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