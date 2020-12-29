#include "Queue.h"

void Queue::push(Info *&el) {
    Node *temp = new Node;
    temp->elArr = el;
    temp->index = size;
    temp->next = nullptr;
    if (head == nullptr)
        head = tail = temp;
    else {
        tail->next = temp;
        tail = temp;
    }
    size++;
}

<<<<<<< HEAD
=======
void Queue::sortWeights(int *arr, int L, int R) {
    int i = L;
    int j = R;
    int X = arr[L];
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
        sortWeights(arr, L, j);
    }
    if (i < R) {
        sortWeights(arr, i, R);
    }
}

>>>>>>> 72b0458448d0ecec2bd18eb4b339c3755e189996
void Queue::print() const {
    if (head == nullptr) {
        std::cout << "Queue is empty\n";
        return;
    }
    Node *temp = head;
    int i = 0;
    std::cout << "Size: " << size << std::endl;
    while (temp) {
        std::cout << i + 1 << ") ";
        std::cout << temp->elArr->fio << "\t";
        std::cout << temp->elArr->street << "\t";
        std::cout << temp->elArr->numOfHome << "\t";
        std::cout << temp->elArr->numOfFlat << "\t";
        std::cout << temp->elArr->dateOfSettling << "\n";
        ++i;
        temp = temp->next;
    }
}

int Queue::getSize() const {
    return size;
}

<<<<<<< HEAD
bool Queue::compare(Node *x, Node *y) {
    if (x->elArr->numOfHome < y->elArr->numOfHome)
        return true;
    else if (x->elArr->numOfHome == y->elArr->numOfHome) {
        if (x->elArr->numOfFlat < y->elArr->numOfFlat)
            return true;
        else if (x->elArr->numOfFlat == y->elArr->numOfFlat) {
            if (x->elArr->street[0] < y->elArr->street[0])
                return true;
            else if (x->elArr->street[0] == y->elArr->street[0]) {
                if (x->elArr->street[1] < y->elArr->street[1])
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

void Queue::SelectSort() {
    Node *temp = head;
    Info *data;
    while (temp) {
        Node *present = temp->next;
        Node *min = temp;
        while (present) {
            if (compare(min, present))
                min = present;
            present = present->next;
        }
        data = temp->elArr;
        temp->elArr = min->elArr;
        min->elArr = data;
        temp = temp->next;
    }
}

=======
>>>>>>> 72b0458448d0ecec2bd18eb4b339c3755e189996
Info *&Queue::getEl(int i) {
    Node *temp = head;
    if (head != nullptr) {
        while (temp->index != i) {
            temp = temp->next;
        }
        if (temp->index == i) {
            return temp->elArr;
        }
    }
}

Queue::~Queue() {
    Node *temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}