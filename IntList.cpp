#include <iostream>
#include "IntList.h"

using namespace std;

// struct IntNode {
//     int data;
//     IntNode *next;
//     IntNode(int data) : data(data), next(0) {}
// };

// class IntList {
//     private:
//         IntNode *head;
//         IntNode *tail;
//     public:
//         IntList();
//         ~IntList();
//         void display() const;
//         void push_front(int value);
//         void pop_front();
//         bool empty() const;
// };

IntList::IntList() {
    head = 0;
    tail = 0;
}

IntList::~IntList() {
    while (head != 0) {
        pop_front();
    }
}

void IntList::display() const {
    for (IntNode *curr = head; curr != 0; curr = curr->next) {
        if (curr->next != 0) {
            cout << curr->data << " ";
        }
        else {
            cout << curr->data;
        }
    }
}

void IntList::push_front(int value) {
    IntNode *temp = new IntNode(value);
    temp->next = this->head;
    this->head = temp;
    if (tail == 0) {
        tail = temp;
    }
}

void IntList::pop_front() {
    IntNode *temp = head;
    head = head->next;
    delete temp;
    if (head == 0) {
        tail = 0;
    }
}

bool IntList::empty() const {
    if (head == 0) {
        return true;
    }
    else {
        return false;
    }
}