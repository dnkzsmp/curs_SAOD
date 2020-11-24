#include "quickSort.h"

int compareInfo(Info *&a, Info *&b) {
    if (strcmp(a->fio, b->fio) == 0)
        return strcmp(a->street, b->street);
    else
        return strcmp(a->fio, b->fio);
}

void QuickSort(Info **arr, int L, int R) {
    int i = L;
    int j = R;
    while (i <= j) {
        while (compareInfo(arr[i], arr[L]) < 0) {
            ++i;
        }
        while (compareInfo(arr[j], arr[L]) > 0) {
            --j;
        }
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    }
    if (L < j) {
        QuickSort(arr, L, j);
    }
    if (i < R) {
        QuickSort(arr, i, R);
    }
}