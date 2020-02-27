//
// Created by lzk on 2019-12-18.
//

#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

#include <iostream>
#include "queue.h"
const int DEFAULTSIZE = 2;

template<class T>
class Stack{
public:
    Stack(){}
    ~Stack(){}
    virtual void clear() = 0;
    virtual bool push(T) = 0;
    virtual bool pop(T&) = 0;
    virtual bool Top(T&) = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
};

template <class T>
class arrStack : public Stack<T>{
private:
    int maxSize;
    int top;
    T*  st;
public:
    arrStack();
    ~arrStack();
    void clear();
    bool push(T);
    bool pop(T&);
    bool Top(T&);
    bool isEmpty();
    bool isFull();
};

template<class T>
arrStack<T>::arrStack() {
    st = new T[DEFAULTSIZE];
    top = -1;
    maxSize = DEFAULTSIZE;
}

template<class T>
arrStack<T>::~arrStack() {
    delete[] st;
}

template<class T>
void arrStack<T>::clear() {
    top = -1;
}

template<class T>
bool arrStack<T>::push(T item) {
    if(top == maxSize - 1){
        auto tmp = new T[maxSize * 2];
        for(int i = 0;i < maxSize;i++){
            tmp[i] = st[i];
        }
        delete[] st;
        st = tmp;
        maxSize *= 2;
    }
    st[++top] = item;
    return true;
}

template<class T>
bool arrStack<T>::pop(T& item) {
    if(top == -1){
        return false;
    }
    item = st[top--];
    return true;
}

template<class T>
bool arrStack<T>::Top(T& item) {
    if(top == -1){
        return false;
    }
    item = st[top];
    return true;
}

template<class T>
bool arrStack<T>::isEmpty() {
    return top == -1;
}

template<class T>
bool arrStack<T>::isFull() {
    return top == maxSize - 1;
}

template<class T>
class lnkStack : public Stack<T>{
private:
    Node<T>* top;
    int size;
public:
    lnkStack();
    ~lnkStack();
    void clear();
    bool push(T);
    bool pop(T&);
    bool Top(T&);
    bool isEmpty();
    bool isFull();
};

template<class T>
lnkStack<T>::lnkStack() {
    top = NULL;
    size = 0;
}

template<class T>
lnkStack<T>::~lnkStack() {
    for(int i = 0;i < size;i++){
        auto tmp = top;
        top = top->next;
        delete tmp;
    }
}

template<class T>
void lnkStack<T>::clear() {
    for(int i = 0;i < size;i++){
        auto tmp = top;
        top = top->next;
        delete tmp;
    }
    size = 0;
    top = NULL;
}

template<class T>
bool lnkStack<T>::push(const T item) {
    Node<T>* node = new Node<T>(item);
    node->next = top;
    top = node;
    size++;
    return true;
}

template<class T>
bool lnkStack<T>::pop(T& item) {
    if(size == 0){
        return false;
    }

    auto node = top;
    item = node->data;
    top = top->next;
    delete node;
    size--;
    return true;
}

template<class T>
bool lnkStack<T>::Top(T& item) {
    if(size == 0){
        return false;
    }
    item = top->data;
    return true;
}

template<class T>
bool lnkStack<T>::isEmpty() {
    return size == 0;
}

template<class T>
bool lnkStack<T>::isFull() {
    return false;
}

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
        parent = reinterpret_cast<doubleStack*>(reinterpret_cast<long long>(this) - offsetof(doubleStack, S1));
    } else {
        parent = reinterpret_cast<doubleStack*>(reinterpret_cast<long long>(this) - offsetof(doubleStack, S2));
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
