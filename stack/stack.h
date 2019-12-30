//
// Created by lzk on 2019-12-18.
//

#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

#include <iostream>

template<class T>
class doubleStack {
private:
    T* arr;
    int size;
    int head1, head2;
public:
    explicit doubleStack(int);

    class innerStack {
    private:
        bool first;
        doubleStack* parent;
    public:
        explicit innerStack(bool);

        bool push(T);

        bool pop(T &);

        bool isFull();

        bool isEmpty();
    }S1, S2;
};

template<class T>
doubleStack<T>::doubleStack(int i):
    S1(innerStack(true)),
    S2(innerStack(false))
{
    arr = new T[i];
    size = i;
    head1 = 0;
    head2 = i - 1;
}

template<class T>
doubleStack<T>::innerStack::innerStack(bool b) {
    first = b;
    if (first) {
        parent = reinterpret_cast<doubleStack*>(reinterpret_cast<long >(this) - offsetof(doubleStack, S1));
    } else {
        parent = reinterpret_cast<doubleStack*>(reinterpret_cast<long >(this) - offsetof(doubleStack, S2));
    }
}

template<class T>
bool doubleStack<T>::innerStack::isEmpty() {
    if (first) {
        //std::cout << "HEAD1 " << parent->head1 << "      HEAD2 " << parent->head2 << std::endl;
        return parent->head1 == 0;
    }
    return parent->head2 == parent->size - 1;
}

template<class T>
bool doubleStack<T>::innerStack::isFull() {
    return parent->head2 + 1 == parent->head1;
}

template<class T>
bool doubleStack<T>::innerStack::push(const T item) {
    if (isFull()) {
        return false;
    }

    if (first) {
        parent->arr[parent->head1++] = item;
    } else {
        parent->arr[parent->head2--] = item;
    }
    return true;
}

template<class T>
bool doubleStack<T>::innerStack::pop(T &item) {
    if (isEmpty()) {
        return false;
    }
    if (first) {
        item = parent->arr[--parent->head1];
    } else {
        item = parent->arr[++parent->head2];
    }
    return true;
}

#endif //DATASTRUCTURE_STACK_H
