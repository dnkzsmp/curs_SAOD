#ifndef CURS_CREATEQUEUE_H
#define CURS_CREATEQUEUE_H
#include "Info.h"
#include "Queue.h"
#include <cstring>
#include <iostream>
#include <sstream>
int comparator(char *fio, char *key);
bool binarySearch1(Info **arr, char key[], Queue &queue);
void binarySearch(Info **arr, Queue &queue);
#endif