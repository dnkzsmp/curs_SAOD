#ifndef CURS_TREEA2_H
#define CURS_TREEA2_H
#include "Queue.h"
struct Vertex {
    Info *data;
    Vertex *left;
    Vertex *right;
};
int compareInfo(Info *&a, Info *&b);
void addElement(Vertex *&root, Info *&el, Queue &queue);
void A2(int l, int r, Queue &queue, Vertex *&root);
void ObhodLeftToRight(Vertex *root, short int &quantity);
Vertex *Search(Vertex *root, short int flat);
#endif