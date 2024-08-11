#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <memory>
#include <string>
#include <vector>

namespace {
    int8_t BUCKETS {5};
}

class Node {
    public:
    std::string data;
    std::shared_ptr<Node> next;

    Node(std::shared_ptr<Node>& node_) : data(node_.get()->data), next(std::move(node_.get()->next)) {}
    Node() : data(0), next(nullptr) {}
    Node(std::string data_) : data(data_), next(nullptr) {}
    Node(std::string data_, std::shared_ptr<Node> next_) : data(data_), next(std::move(next_)) {}
};

class HashTable {
    public:
    HashTable();
    // Destructor
    // ~HashTable();
    
    void insert(const std::string& data);
    std::shared_ptr<Node> remove(const std::string& data);
    void remove(const std::shared_ptr<Node>);
    std::shared_ptr<Node> get(const std::string& data);
    bool find(std::string data);
    void print();
    
    // private: 
    std::vector<std::shared_ptr<Node>> hashTable;

    int32_t hashFunction(const Node &node);

};

HashTable::HashTable() {
    hashTable.resize(BUCKETS);
    for(auto i=0; i<BUCKETS; i++) {
        hashTable[i] = nullptr;
    }
}

void HashTable::insert(const std::string& data) {
    Node node {data};
    auto index = hashFunction(node);
    if (hashTable[index] == nullptr){
        hashTable[index] = std::make_shared<Node>(node);
    }
    else {
        auto currNode = hashTable[index];
        while (currNode->next != nullptr)
        {
            currNode = currNode->next;
        }
        currNode->next = std::make_shared<Node>(node);
        
    }

}

std::shared_ptr<Node> HashTable::remove(const std::string& data) {
    Node node {data};
    auto index = hashFunction(node);
    auto currNode = hashTable[index];
    auto prevNode = std::shared_ptr<Node>(nullptr);
    if(currNode == nullptr){
        return nullptr;
    }

    if(currNode->data == data) {
        hashTable[index] = currNode->next;
        return currNode;
    }

    while (currNode != nullptr)
    {
        if(currNode->data == data) {
            prevNode->next = currNode->next;
            return currNode;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
    return currNode;
}

std::shared_ptr<Node> HashTable::get(const std::string& data) {
    Node node {data};
    auto index = hashFunction(node);
    auto currNode = hashTable[index];
    while (currNode != nullptr)
    {
        if(currNode->data == data) {
            return currNode;
        }
        currNode = currNode->next;
    }
    return nullptr;
}

void HashTable::print() {
    for(auto index=0; index<BUCKETS; index++) {
        printf("BUCKET: %i ->    ", index);
        auto currNode = hashTable[index];
        uint32_t counter = 0;
        while (currNode != nullptr)
        {
            printf("NODE : %i, DATA: %s;   ->   ", counter, currNode->data.c_str());
            currNode = currNode->next;
        }
        printf("\n");
    }
}

int32_t HashTable::hashFunction(const Node &node) {
    uint32_t index = 0;
    for(auto i=node.data.begin(); i != node.data.end(); i++) {
        index += (uint32_t)*i;
    }
    return index % BUCKETS;
}

// int main() {
//     HashTable hashTable1;
//     for(auto i : {"mama", "tata", "tiruriru", "abstrakcja", "matka", "magnez", "zelazo", "hashtable", "lala", "oll", "m"}) {
//         hashTable1.insert(i);
//     }
//     hashTable1.print();
//     auto mama_val = hashTable1.get("mama");
//     printf("\n%s", mama_val != nullptr ? mama_val->data.c_str() : "nullptr");

//     auto null_val = hashTable1.get("nullopt");
//     printf("\n%s\n", null_val != nullptr ? null_val->data.c_str() : "nullptr");

//     hashTable1.remove("matka");
//     hashTable1.print();
// }