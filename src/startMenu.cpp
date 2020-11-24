#include "createQueue.h"
#include "printInfo.h"
#include "quickSort.h"
#include "startMenu.h"
#include <iostream>

void printVertex(Vertex *p) {
    std::cout << p->data->fio << "\t";
    std::cout << p->data->street << "\t";
    std::cout << p->data->numOfHome << "\t";
    std::cout << p->data->numOfFlat << "\t";
    std::cout << p->data->dateOfSettling << "\n";
}

void searchInTree(Vertex *root) {
    short int flat;
    std::cout << "Enter flat: ";
    std::cin >> flat;
    Vertex *p = Search(root, flat);
    if (p != nullptr) {
        printVertex(p);
    } else
        std::cout << "Not found\n";
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
    std::cout << "6) Exit" << std::endl;
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
            A2(0, queue.getSize() - 1, queue, root);
            ObhodLeftToRight(root, quantity);
            std::cout << "Quantity: " << quantity << std::endl;
            goto Point;
        case 5:
            searchInTree(root);
            goto Point;
        case 6:
        default:
            break;
    }
}