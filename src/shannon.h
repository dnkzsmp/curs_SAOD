#ifndef CURS_SHANNON_H
#define CURS_SHANNON_H
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
void sortP(float *arr, int L, int R);
void Shannon(int n, float *P, float *Q, int *L, int **C);
void printArray(std::vector<char> &arr, float *P, int size);
void printCharacters(int size, int L[], int **C);
void startEncoding();
#endif
