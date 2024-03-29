#include "treeA1.h"

bool compare(Vertex *x, Info *y) {
    if (x->data->numOfHome < y->numOfHome)
        return true;
    else if (x->data->numOfHome == y->numOfHome) {
        if (x->data->numOfFlat < y->numOfFlat)
            return true;
        else if (x->data->numOfFlat == y->numOfFlat) {
            if (x->data->street[0] < y->street[0])
                return true;
            else if (x->data->street[0] == y->street[0]) {
                if (x->data->street[1] < y->street[1])
                    return true;
                else
                    return false;
            } else
                return false;
        } else
            return false;
    }
    return false;
}

void addElement(Vertex *&root, Info *&el, Queue &queue, int W) {
    Vertex **p = &root;
    while (*p != nullptr) {
        if (!compare(*p, el))
            p = &(*p)->left;
        else if (compare(*p, el))
            p = &(*p)->right;
        else
            break;
    }
    if (*p == nullptr) {
        *p = new Vertex;
        (*p)->data = el;
        (*p)->weight = W;
        (*p)->left = nullptr;
        (*p)->right = nullptr;
    }
}

void A1(int size, Queue &queue, Vertex *&root, int *W) {
    queue.sortWeights(W, 0, size - 1);
    for (int i = 0; i < size; ++i)
        addElement(root, queue.getEl(i), queue, W[i]);
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

void Search(Vertex *root, short int home, short int flat, const char *street) {
    Vertex *p = root;
    while (p != nullptr) {
        if (p->data->numOfHome > home)
            p = p->left;
        else if (p->data->numOfHome < home)
            p = p->right;
        else if (p->data->numOfHome == home) {
            if (p->data->numOfFlat > flat)
                p = p->left;
            else if (p->data->numOfFlat < flat)
                p = p->right;
            else if (p->data->numOfFlat == flat) {
                if (p->data->street[0] > street[0])
                    p = p->left;
                else if (p->data->street[0] < street[0])
                    p = p->right;
                else if (p->data->street[0] == street[0]) {
                    if (p->data->street[1] > street[1])
                        p = p->left;
                    else if (p->data->street[1] < street[1])
                        p = p->right;
                    else if (p->data->street[1] == street[1])
                        break;
                } else
                    break;
            } else
                break;
        } else
            break;
    }
    if (p != nullptr) {
        std::cout << p->data->fio << "\t";
        std::cout << p->data->street << "\t";
        std::cout << p->data->numOfHome << "\t";
        std::cout << p->data->numOfFlat << "\t";
        std::cout << p->data->dateOfSettling << "\n\n";
    } else
        std::cout << "Not found\n\n";
}