#ifndef CURS_QUEUE_H
#define CURS_QUEUE_H
#include "Info.h"
#include <cstring>
#include <iostream>
class Queue {
private:
    struct Node {
        Info *elArr;
        Node *next;
        int index;
    };
    Node *head, *tail;
    int size = 0;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    void push(Info *&el);
    void print() const;
    static bool compare(Node *x, Node *y);
    int getSize() const;
    Info *&getEl(int i);
    void SelectSort();
    ~Queue();
};
#endif
