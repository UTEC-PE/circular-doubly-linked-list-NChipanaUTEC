#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    void killSelf(){
        delete(this);
    }
    void print_next(){
        if (next != NULL){
            next -> print_next();
        }
        std::cout << data << " ";
    }
};

#endif
