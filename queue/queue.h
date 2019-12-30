//
// Created by lzk on 2019-12-12.
//

#ifndef DATASTRUCTURE_QUEUE_H
#define DATASTRUCTURE_QUEUE_H

#include <iostream>
#include <stack>
template <class T>
class Queue {
    virtual void clear()=0;
    virtual bool isEmpty()=0;
    virtual bool isFull()=0;
    virtual bool getFront(T&)=0;
    virtual bool enQueue(T)=0;
    virtual bool deQueue(T&)=0;
};


template <class T>
class arrQueue : public Queue<T>{
private:
    T* arr;
    int size;
    int cap;
    int head, tail;
public:
    arrQueue();
    ~arrQueue();
    void clear();
    bool isEmpty();
    bool isFull();
    bool enQueue(T item);
    bool getFront(T&);
    bool deQueue(T&);
    bool enQueueFromHead(T);
    bool deQueueFromTail(T&);
};

template <class T>
class linkQueue : public Queue<T>{
public:
    class Node{
    public:
        T item;
        Node* next;
    };
private:
    Node* head;
    Node* tail;
public:
    linkQueue();
    ~linkQueue();
    void clear();
    bool isEmpty();
    bool isFull();
    bool getFront(T&);
    bool enQueue(T item);
    bool deQueue(T&);
};

template <class T>
class stackQueue : public Queue<T>{
private:
    std::stack<T> s1, s2;
public:
    void clear();
    bool isEmpty();
    bool isFull();
    bool enQueue(T item);
    bool getFront(T&);
    bool deQueue(T&);
};

template<class T>
class deque : public Queue<T>{
private:
    int* arr;
    int front, tail;
    int size;
public:
    deque();
    ~deque();
    void clear();
    bool isEmpty();
    bool isFull();
    bool enQueue(T item);
    bool getFront(T&);
    bool deQueue(T&);
};

int DefaultSize = 10;

template<class T>
arrQueue<T>::arrQueue() {
    arr = new T[DefaultSize];
    head = tail = size = 0;
    cap = DefaultSize;
}

template <class T>
arrQueue<T>::~arrQueue() {
    delete[] arr;
}

template<class T>
void arrQueue<T>::clear() {
    head = tail = size = 0;
}

template<class T>
bool arrQueue<T>::isEmpty() {
    return size == 0;
}

template<class T>
bool arrQueue<T>::getFront(T &item) {
    if (size <= 0) {
        return false;
    } else {
        item = arr[head];
        return true;
    }
}

template<class T>
bool arrQueue<T>::isFull() {
    return size == cap;
}

template<class T>
bool arrQueue<T>::enQueue(const T item) {
    if (size >= cap) {
        return false;
    } else {
        arr[tail] = item;
        tail = (tail + 1) % cap;
        size++;
        return true;
    }
}

template<class T>
bool arrQueue<T>::deQueue(T &item) {
    if (size <= 0) {
        return false;
    } else{
        item = arr[head++];
        size--;
        return true;
    }
}

template <class T>
bool arrQueue<T>::enQueueFromHead(T item) {
    if(isFull()){
        return false;
    }
    head = (head - 1) % cap;
    arr[head] = item;
    size++;
    return true;
}

template <class T>
bool arrQueue<T>::deQueueFromTail(T& item) {
    if(isEmpty()){
        return false;
    }
    tail = (tail - 1) % cap;
    item = arr[tail];
    size--;
    return true;
}

template <class T>
linkQueue<T>::linkQueue() {
    head = tail = nullptr;
}

template <class T>
linkQueue<T>::~linkQueue() {
    Node* tmp;
    while(head != nullptr){
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

template <class T>
bool linkQueue<T>::isFull() {
    return false;
}

template <class T>
bool linkQueue<T>::isEmpty() {
    return head == nullptr;
}

template <class T>
void linkQueue<T>::clear() {
    Node* tmp;
    while(head != nullptr){
        tmp = head;
        head = head->next;
        free(tmp);
    }
    head = tail = nullptr;
}

template <class T>
bool linkQueue<T>::enQueue(const T item) {
    if(head == nullptr){
        head = new(Node);
        head->item = item;
        tail = head;
        return true;
    }

    Node* tmp = new(Node);
    tmp->item = item;
    tail->next = tmp;
    tail = tmp;
    return true;
}

template <class T>
bool linkQueue<T>::deQueue(T & item) {
    if(head == nullptr){
        return false;
    }

    Node* tmp = head;
    item = tmp->item;
    head = head->next;
    free(tmp);
    return true;
}

template <class T>
bool linkQueue<T>::getFront(T& item) {
    if(head == nullptr){
        return false;
    }

    item = head->item;
    return true;
}

template <class T>
bool stackQueue<T>::isEmpty() {
    return s1.empty() && s2.empty();
}

template <class T>
bool stackQueue<T>::isFull() {
    return false;
}

template <class T>
void stackQueue<T>::clear() {
    s1 = s2 = std::stack<int>();
}

template <class T>
bool stackQueue<T>::enQueue(T item) {
    s1.push(item);
    return true;
}

template <class T>
bool stackQueue<T>::deQueue(T& item) {
    if(isEmpty()){
        return false;
    }
    if(!s2.empty()){
        item = s2.top();
        s2.pop();
        return true;
    }
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    item = s2.top();
    s2.pop();
    return true;
}

template <class T>
bool stackQueue<T>::getFront(T& item) {
    if(isEmpty()){
        return false;
    }
    if(!s2.empty()){
        item = s2.top();
        return true;
    }
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    item = s2.top();
    return true;
}

template <class T>
deque<T>::deque() {
    arr = new T[DefaultSize];
    front =
}

#endif //DATASTRUCTURE_QUEUE_H
