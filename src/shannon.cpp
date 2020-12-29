#include "shannon.h"
#include <map>

void sortP(float *arr, int L, int R) {
    int i = L;
    int j = R;
    float X = arr[L];
    while (i <= j) {
        while (arr[i] > X) {
            ++i;
        }
        while (arr[j] < X) {
            --j;
        }
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    }
    if (L < j) {
        sortP(arr, L, j);
    }
    if (i < R) {
        sortP(arr, i, R);
    }
}

void Shannon(int n, float *P, float *Q, int *L, int **C) {
    Q[0] = 0, L[0] = (int) (-std::log2(P[0]));
    for (int i = 1; i < n; ++i) {
        Q[i] = Q[i - 1] + P[i - 1];
        L[i] = (int) (-std::log2(P[i]));
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < L[i] + 1; ++j) {
            Q[i] = Q[i] * 2;
            C[i][j] = (int) (Q[i]);
            if (Q[i] > 1)
                Q[i] -= 1;
        }
    }
}

void printArray(std::vector<char> &arr, float *P, int size) {
    std::cout << "P:    ";
    for (int i = 0; i < size; ++i) {
        std::cout << P[i] << "\t";
    }
    std::cout << "\nChar: ";
    std::cout << arr[0] << "\t\t";
    for (int i = 1; i < size; ++i) {
        std::cout << arr[i] << "\t";
    }
    std::cout << "\n\n";
}

void printCharacters(int size, int L[], int **C) {
    std::cout << "L: ";
    for (int i = 0; i < size; ++i)
        std::cout << L[i] << "\t";
    std::cout << "\n\n[C]\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (C[i][j] == -1)
                std::cout << " "
                          << " ";
            else
                std::cout << C[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n\n";
}

void startEncoding() {
    std::string alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя1234567890- ";
    std::ifstream fin;
    std::map<char, double> para;
    fin.open("testBase4.dat", std::ifstream::binary);
    if (fin.is_open()) {
        char ch;
        int count = 0;
        for (char i : alphabet) {
            while (fin.get(ch)) {
                if (ch == i)
                    count++;
            }
            if (count != 0)
                para[i] = (double)count / (double)alphabet.length();
        }
    }
    fin.close();
    std::cout << alphabet;
/*    std::vector<char> arr(12);
    float P[12];
    //arrayInit(arr, P);
    sortP(P, 0, 12);
    printArray(arr, P, 12);
    float Q[12];
    int **C = new int *[12], L[12];
    for (int i = 0; i < 12; ++i)
        C[i] = new int[12];
    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 12; ++j)
            C[i][j] = -1;
    Shannon(12, P, Q, L, C);
    printCharacters(12, L, C);
    for (int i = 0; i < 12; ++i)
        delete[] C[i];
    delete[] C;*/
}