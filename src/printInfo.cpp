#include "printInfo.h"

void printInfo(Info **arr) {
    int step;
    int start = 0, end = 20;
    bool flag = true;
    while (flag) {
        std::cout << "Next page? 1/2/0" << std::endl;
        std::cin >> step;
        if (step == 0 or end > 4000)
            flag = false;
        else if (step == 1 and end <= 4000) {
            for (int i = start; i < end; ++i) {
                std::cout << i + 1 << ") ";
                std::cout << arr[i]->fio << "\t";
                std::cout << arr[i]->street << "\t";
                std::cout << arr[i]->numOfHome << "\t";
                std::cout << arr[i]->numOfFlat << "\t";
                std::cout << arr[i]->dateOfSettling << "\n";
            }
            end += 20;
            start += 20;
        } else if (step == 2 and start > 0 and end >= 20) {
            end -= 20;
            start -= 20;
            for (int i = start; i < end; ++i) {
                std::cout << i + 1 << ") ";
                std::cout << arr[i]->fio << "\t";
                std::cout << arr[i]->street << "\t";
                std::cout << arr[i]->numOfHome << "\t";
                std::cout << arr[i]->numOfFlat << "\t";
                std::cout << arr[i]->dateOfSettling << "\n";
            }
        }
    }
}