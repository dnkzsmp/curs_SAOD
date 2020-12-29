#ifndef CURS_TREEA1_H
#define CURS_TREEA1_H
#include "Queue.h"
struct Vertex {
    Info *data;
    int weight;
    Vertex *left;
    Vertex *right;
};
int compareInfo(Info *&a, Info *&b);
void addElement(Vertex *&root, Info *&el, Queue &queue, int W);
void A1(int size, Queue &queue, Vertex *&root, int *W);
void ObhodLeftToRight(Vertex *root, short int &quantity);
void Search(Vertex *root, short int home, short int flat, const char *street);
#endif