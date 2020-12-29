#include "Info.h"
#include "startMenu.h"
#include <iostream>
#include <windows.h>

int main() {
    Info arr[4000];
    FILE *fin = fopen("testBase4.dat", "rb");
    fread(arr, sizeof(Info), 4000, fin);
    Info **narr = new Info *[4000];
    for (int i = 0; i < 4000; ++i)
        narr[i] = &arr[i];
    fclose(fin);
    startMenu(narr);
}
