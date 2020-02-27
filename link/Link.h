#ifndef LINK_H
#define LINK_H

#include <stdlib.h>
#include<iostream>

template<class T>
class List{
public:
    virtual ~List(){}
    void clear();
    bool isEmpty();
    bool append(const T value);
    bool insert(const int p, const T value);
    bool Delete(const int p);
    bool getValue(const int p, T& value);
    bool setValue(const int p, const T value);
    bool getPos(int& p, const T value);
};

template<class T>
class arrList : public List<T>{
private:
    T* arr;
    int maxSize;
    int curLen;
    int position;
public:
    explicit arrList(int size){
        arr = new T[size];
        maxSize = size;
        curLen = position = 0;
    }
    ~arrList() override{
        delete[] arr;
    }

    void clear(){
        delete [] arr;
        arr = new T[maxSize];
        curLen = position = 0;
    }

    int length(){return curLen;}
    bool append(T value);
    bool insert(int p, T value);
    bool Delete(int p);
    bool getPos(int& p, T value);
};

template<class T>
bool arrList<T>::append(const T value) {
    if(curLen >= maxSize){
        return false;
    }

    arr[curLen++] = value;
    return true;
}

template<class T>
bool arrList<T>::getPos(int& p, const T value) {
    int i;
    for(i = 0;i < curLen;i++){
        if(value == arr[i]){
            p = i;
            return true;
        }
    }

    p = -1;
    return false;
}

template<class T>
bool arrList<T>::insert(const int p, const T value) {
    if(curLen >= maxSize || p < 0 || p > curLen){
        return false;
    }

    for(int i = curLen;i > p;i--){
        arr[i] = arr[i-1];
    }

    arr[p] = value;
    curLen++;
    return true;
}

template<class T>
bool arrList<T>::Delete(const int p) {
    if(curLen == 0 || p < 0 || p >= curLen){
        return false;
    }

    for(int i = p;i < curLen -1;i++){
        arr[i] = arr[i+1];
    }

    curLen--;
    return true;
}

template<class T>
class Node {
public:
    T data;
    Node<T> *next, *pre;

    Node(T);
};

template<class T>
class
Link {
public:
    Node<T> *head, *tail;

    Link();

    virtual ~Link();

    void append(Node<T> *);

    void *getAddrByValue(T data);

    void print();

    void insertElementFrontValue(T, T);

    void reverse();
};

template<class T>
class
DoubleLink {
public:
    T data;
    Node<T> *head, *tail;

    DoubleLink();

    virtual ~DoubleLink();

    void insertByPointer(Node<T> *target, Node<T> *t);

    void print();

    void append(Node<T> *);
};

template<class T>
class
CircleLink {
public:
    T data;
    Node<T> *head, *tail;

    CircleLink();

    virtual ~CircleLink();

    int size();

    void print();

    void append(Node<T> *);

    void deleteFirst();
};

template<class T>
Node<T>::Node(T data) {
    this->data = data;
    next = NULL;
}

template<class T>
Link<T>::Link() {
    head = tail = new Node<T>(-1);
}

template<class T>
Link<T>::~Link() {
    Node<T> *temp = head;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template<class T>
void Link<T>::append(Node<T> *t) {
    tail->next = t;
    t->next = NULL;
    tail = t;
}

template<class T>
void *Link<T>::getAddrByValue(T data) {
    Node<T> *ret = head->next;
    while (ret != NULL) {
        if (ret->data == data) {
            return ret;
        }
        ret = ret->next;
    }
    return NULL;
}

template<class T>
void Link<T>::print() {
    Node<T> *t = head->next;
    while (t) {
        std::cout << t->data << std::endl;
        t = t->next;
    }
}

template<class T>
void Link<T>::insertElementFrontValue(T target, T insertValue) {
    Node<T> *t = head;
    while (t && t->next) {
        if (t->next->data == target) {
            Node<T> *q = t->next;
            t->next = new Node<T>(insertValue);
            t->next->next = q;
            t = t->next;
        }
        t = t->next;
    }
}

template<class T>
void Link<T>::reverse() {
    Node<T> *p, *q, *r;
    p = head->next;
    if (p) {
        q = p->next;
    } else {
        q = NULL;
        return;
    }
    while (q) {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    head->next->next = NULL;
    head->next = p;
}


template<class T>
void DoubleLink<T>::print() {
    Node<T> *t = head->next;
    while (t) {
        std::cout << t->data << std::endl;
        t = t->next;
    }
}

template<class T>
void DoubleLink<T>::insertByPointer(Node<T> *target, Node<T> *insert) {
    Node<T> *t = head;
    while (t && t->next) {
        if (t->next == target) {
            auto temp = t->next;
            t->next = insert;
            insert->next = temp;
            return;
        }
        t = t->next;
    }
}

template<class T>
void DoubleLink<T>::append(Node<T> *t) {
    tail->next = t;
    t->next = NULL;
    tail = t;
}

template<class T>
DoubleLink<T>::DoubleLink() {
    head = tail = new Node<T>(-1);
}

template<class T>
DoubleLink<T>::~DoubleLink() {
    Node<T> *temp = head;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template<class T>
CircleLink<T>::CircleLink() {
    tail = new Node<T>(-1);
    tail->next = tail;
}

template<class T>
CircleLink<T>::~CircleLink() {
    Node<T> *temp = tail;
    int len = size();
    int i = 0;
    while (i < len) {
        auto t = temp->next;
        delete temp;
        temp = t;
        i++;
    }
}

template<class T>
int CircleLink<T>::size() {
    auto t = tail->next;
    int ret = 0;
    while (t != tail) {
        ret += 1;
        t = t->next;
    }
    return ret;
}

template<class T>
void CircleLink<T>::append(Node<T> *t) {
    auto head = tail->next;
    tail->next = t;
    t->next = head;
    tail = t;
}

template<class T>
void CircleLink<T>::print() {
    Node<T> *t = tail->next->next;
    auto len = size();
    int i = 0;
    while (i < len) {
        std::cout << t->data << std::endl;
        t = t->next;
        i += 1;
    }
}

template<class T>
void CircleLink<T>::deleteFirst() {
    auto len = size();
    if (len == 0) {
        return;
    }
    auto head = tail->next;
    auto t = head->next;
    head->next = t->next;
    delete t;
}

template<class T>
void deleteEle(T *arr, int location, int len) {
    for (int i = location; i < len - 1; i++) {
        arr[i] = arr[i + 1];
    }
}


#endif

