#ifndef CURS_QUEUE_H
#define CURS_QUEUE_H
#include "Info.h"
#include <cstring>
#include <iostream>
#include <algorithm>
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
<<<<<<< HEAD
    static bool compare(Node *x, Node *y);
    int getSize() const;
    Info *&getEl(int i);
    void SelectSort();
=======
    void sortWeights(int *W, int L, int R);
    int getSize() const;
    Info *&getEl(int i);
>>>>>>> 72b0458448d0ecec2bd18eb4b339c3755e189996
    ~Queue();
};
#endif
