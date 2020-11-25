#include "createQueue.h"

int comparator(char *fio, char *key) {
    char str[4]{};
    strncat(str, fio, 3);
    if (strcmp(str, key) > 0)
        return -1;
    else if (strcmp(str, key) < 0)
        return 1;
    else
        return 0;
}

bool binarySearch1(Info **arr, char key[], Queue &queue) {
    int l = 0, r = 3999, m;
    int next = 0;
    while (l < r) {
        m = (l + r) / 2;
        if (comparator(arr[m]->fio, key) > 0)
            l = m + 1;
        else
            r = m;
    }
    if (comparator(arr[r]->fio, key) == 0) {
        while (comparator(arr[r + next]->fio, key) == 0) {
                queue.push(arr[r + next]);
                ++next;
                if (r + next > 3999)
                    break;
        }
    }
    return false;
}

void binarySearch(Info **arr, Queue &queue) {
    char key[4];
    std::cout << "Enter key: ";
    std::cin >> key;
    binarySearch1(arr, key, queue);
    //queue.SelectSort();
    queue.print();
}