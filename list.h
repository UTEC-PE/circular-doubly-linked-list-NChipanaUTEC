#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* start;
        int nodes;
    public:
        List(){
            start = NULL;
            nodes = 0;
        }
        T front(){
        if (nodes == 0)
            cout << "Lista Vacia" << endl;
        else
            return start -> data;
        }
        T back(){
        if (nodes == 0)
            cout << "Lista Vacía" << endl;
        else
            return start -> prev -> data;
        }
        void push_front(T value){
            auto* temp = new Node<T>;
            temp -> data = value;
            if(nodes == 0){
                start = temp;
                start -> next = start;
                start -> prev = start;
            }
            else if(nodes == 1){
                start -> next = temp;
                start -> prev = temp;
                temp -> next = start;
                temp -> prev = start;
            }
            else{
                start -> prev -> next = temp;
                temp -> next = start;
                temp -> prev = start -> prev;
                start -> prev = temp;
            }
            start = temp;
            nodes ++;
        }
        void push_back(T value){
            auto* temp = new Node<T>;
            temp -> data = value;
            if(nodes == 0){
                start = temp;
                start -> next = start;
                start -> prev = start;
            }
            else if(nodes == 1){
                start -> next = temp;
                start -> prev = temp;
                temp -> next = start;
                temp -> prev = start;
            }
            else{
                start -> prev -> next = temp;
                temp -> next = start;
                temp -> prev = start -> prev;
                start -> prev = temp;
            }
            nodes ++;
        }
        void pop_front(){
            if(nodes == 0)
                cout << "Lista Vacía" << endl;
            else if(nodes == 1)
                start = NULL;
            else{
                start -> prev -> next = start -> next;
                start -> next -> prev = start -> prev;
                start = start -> next;
            }
            nodes --;
        }
        void pop_back(){
            if(nodes == 0)
                cout << "Lista Vacía" << endl;
            else if(nodes == 1)
                start = NULL;
            else{
                start -> prev -> prev -> next = start;
                start -> prev -> prev = start -> prev;
            }
            nodes --;
        }
        T get(int position){
            auto* temp = start;
            for(int i = 0; i < position; i++){
                temp = temp -> next;
            }
            return temp -> data;
        }
        void concat(List<T> &other){
            start -> prev -> next = other.start;
            other.start -> prev = start -> prev;
        }
        bool empty(){
            return nodes == 0;
        }
        int size(){
            return nodes;
        }
        void clear(){
            while(nodes > 0){
                pop_front();
            }
            nodes = 0;
        }
        Iterator<T> begin(){
            return Iterator<T>(start);
        }
        Iterator<T> end(){
            return Iterator<T>(start->prev);
        }

        ~List(){}
};

#endif