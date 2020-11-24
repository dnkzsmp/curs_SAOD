#include "Queue.h"

int Queue::cmp(const void *a, const void *b) {
    const Info *x = (Info *) a;
    const Info *y = (Info *) b;
    int comp = strcmp(x->street, y->street);
    if (comp > 0)
        return 1;
    if (comp < 0)
        return -1;
    comp = x->numOfHome - y->numOfHome;
    if (comp < 0)
        return -1;
    if (comp > 0)
        return 1;
    comp = x->numOfFlat - y->numOfFlat;
    if (comp < 0)
        return -1;
    if (comp > 0)
        return 1;
    return 0;
}

void Queue::push(Info *&el) {
    Node *temp = new Node;
    temp->elArr = el;
    temp->next = nullptr;
    if (head == nullptr)
        head = tail = temp;
    else {
        tail->next = temp;
        tail = temp;
    }
    size++;
}

int Queue::index = 0;

int Queue::getIndex() {
    index++;
    return index;
}

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

void Queue::SelectSort() {
    Node *temp = head;
    Info *data;
    while (temp) {
        Node *present = temp->next;
        Node *min = temp;
        while (present) {
            if (cmp(min, present) > 0)
                min = present;
            present = present->next;
        }
        data = temp->elArr;
        temp->elArr = min->elArr;
        min->elArr = data;
        temp = temp->next;
    }
}

void Queue::deleteEl() {
    if (head == nullptr) {
        std::cout << "Queue is empty\n";
        return;
    } else {
        Node *temp;
        temp = head;
        head = head->next;
        if (head == nullptr)
            tail = nullptr;
        delete temp;
    }
}

Info *&Queue::getEl(int i) {
    if (head != nullptr) {
        int count = 0;
        if (count == i)
            return head->elArr;
    } else
        head = head->next;
    return getEl(i - 1);
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