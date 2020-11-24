#include "treeA2.h"

void addElement(Vertex *&root, Info *&el, Queue &queue) {
    Vertex **p = &root;
    while (*p != nullptr) {
        if (Queue::cmp(*p, el) < 0)
            p = &(*p)->left;
        else if (Queue::cmp(*p, el) >= 0)
            p = &(*p)->right;
        else
            break;
    }
    if (*p == nullptr) {
        *p = new Vertex;
        (*p)->data = el;
        (*p)->left = nullptr;
        (*p)->right = nullptr;
    }
}

void A2(int l, int r, Queue &queue, Vertex *&root) {
    double wes = 0, sum = 0;
    int W[queue.getSize()];
    for (int j = 0; j < queue.getSize(); ++j)
        W[j] = rand() % 100;
    if (l <= r) {
        for (int i = l; i <= r; ++i)
            wes = wes + W[i];
        int i;
        for (i = l; i < r; ++i) {
            if (sum < wes / 2 and sum + W[i] >= wes / 2)
                break;
            sum = sum + W[i];
        }
        addElement(root, queue.getEl(i), queue);
        queue.deleteEl();
        A2(l, i - 1, queue, root);
        A2(i + 1, r, queue, root);
    }
}

void ObhodLeftToRight(Vertex *root, short int &quantity) {
    if (root != nullptr) {
        quantity++;
        ObhodLeftToRight(root->left, quantity);
        std::cout << root->data->fio << "\t";
        std::cout << root->data->street << "\t";
        std::cout << root->data->numOfHome << "\t";
        std::cout << root->data->numOfFlat << "\t";
        std::cout << root->data->dateOfSettling << "\n";
        ObhodLeftToRight(root->right, quantity);
    }
}

int compareDate(char *first, char *second) {
    char str[2]{}, str2[2]{};
    strncat(str, first, 2);
    strncat(str2, second, 2);
    int result = strcmp(str, str2);
    if (result < 0)
        return 1;
    if (result > 0)
        return -1;
    return 0;
}

Vertex* Search(Vertex *root, short int flat) {
    Vertex *p = root;
    while (p != nullptr) {
        //date > p->data->numOfFlat and home > p->data->numOfHome
        if (flat > p->data->numOfFlat)
            p = p->left;
        else if (flat < p->data->numOfFlat)
            p = p->right;
        else
            break;
    }
    if (p != nullptr)
        return p;
    return nullptr;
}