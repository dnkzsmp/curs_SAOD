#include "createQueue.h"
#include "printInfo.h"
#include "quickSort.h"
#include "startMenu.h"
#include "shannon.h"
#include <iostream>

void searchInTree(Vertex *root) {
    short int flat, home;
    char day[3]{};
    std::cout << "Enter home: ";
    std::cin >> home;
    std::cout << "Enter flat: ";
    std::cin >> flat;
    std::cout << "Enter day: ";
    std::cin >> day;
    Search(root, home, flat, day);
}

void startA2(Vertex *&root, Queue &queue) {
    int W[queue.getSize()];
    for (int &i : W)
        i = rand() % 100;
    W[0] = 0;
    A2(0, queue.getSize() - 1, queue, root, W);
}

void startMenu(Info **arr) {
    short int choice, quantity = 0;
    Queue queue;
    Vertex *root = nullptr;
Point:
    std::cout << "1) View base" << std::endl;
    std::cout << "2) Sort base" << std::endl;
    std::cout << "3) Create queue" << std::endl;
    std::cout << "4) Show A2 tree" << std::endl;
    std::cout << "5) Search in tree" << std::endl;
    std::cout << "6) Encoding" << std::endl;
    std::cout << "7) Exit" << std::endl;
    std::cin >> choice;
    switch (choice) {
        case 1:
            printInfo(arr);
            goto Point;
        case 2:
            QuickSort(arr, 0, 3999);
            goto Point;
        case 3:
            binarySearch(arr, queue);
            goto Point;
        case 4:
            queue.SelectSort();
            startA2(root, queue);
            ObhodLeftToRight(root, quantity);
            std::cout << "Quantity: " << quantity << std::endl;
            goto Point;
        case 5:
            searchInTree(root);
            goto Point;
        case 6:
            startEncoding();
        case 7:
        default:
            break;
    }
}