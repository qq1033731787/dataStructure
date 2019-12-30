#ifndef LINK_H
#define LINK_H

#include <stdlib.h>
#include<iostream>

template <class T>
class Node{
public:
    T data;
    Node<T> *next, *pre;
    Node(T );
};

template <class T>
class 
Link{
public:
    Node<T> *head, *tail;
    Link();
    ~Link();
    void append(Node<T>*);
    void* getAddrByValue(T data);
    void print();
    void insertElementFrontValue(T, T);
    void reverse();
};

template <class T>
class
DoubleLink{
public:
    T data;
    Node<T> *head, *tail;
    DoubleLink();
    ~DoubleLink();
    void insertByPointer(Node<T>* target, Node<T>* t);
    void print();
    void append(Node<T>*);
};

template <class T>
class
CircleLink{
public:
    T data;
    Node<T> *head, *tail;
    CircleLink();
    ~CircleLink();
    int size();
    void print();
    void append(Node<T>*);
    void deleteFirst();
};

template <class T>
Node<T>::Node(T data){
    data = data;
    next = NULL;
}

template <class T>
Link<T>::Link(){
    head = tail = new Node<T>(-1);
}

template <class T>
Link<T>::~Link(){
    Node<T>* temp = head;
    while(head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
void Link<T>::append(Node<T>* t){
    tail->next = t;
    t->next = NULL;
    tail = t;
}

template <class T>
void* Link<T>::getAddrByValue(T data){
    Node<T>* ret = head->next;
    while(ret != NULL){
        if(ret->data == data){
            return ret;
        }
        ret = ret->next;
    }
    return NULL;
}

template <class T>
void Link<T>::print(){
    Node<T>* t = head->next;
    while(t){
        std::cout<<t->data<<std::endl;
        t = t->next;
    }
}

template <class T>
void Link<T>::insertElementFrontValue(T target, T insertValue){
    Node<T>* t = head;
    while(t && t->next){
        if(t->next->data == target){
            Node<T>* q = t->next;
            t->next = new Node<T>(insertValue);
            t->next->next = q;
            t = t->next;
        }
        t = t->next;
    }
}

template <class T>
void Link<T>::reverse(){
    Node<T> *p, *q, *r;
    p = head->next;
    if(p){
        q = p->next;
    }else{
        q = NULL;
        return;
    }
    while(q){
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    head->next->next = NULL;
    head->next = p;
}


template <class T>
void DoubleLink<T>::print(){
    Node<T>* t = head->next;
    while(t){
        std::cout<<t->data<<std::endl;
        t = t->next;
    }
}

template <class T>
void DoubleLink<T>::insertByPointer(Node<T>* target, Node<T>* insert){
    Node<T>* t = head;
    while(t && t->next){
        if(t->next == target){
            auto temp = t->next;
            t->next = insert;
            insert->next = temp;
            return;
        }
        t = t->next;
    }
}

template <class T>
void DoubleLink<T>::append(Node<T>* t){
    tail->next = t;
    t->next = NULL;
    tail = t;
}

template <class T>
DoubleLink<T>::DoubleLink(){
    head = tail = new Node<T>(-1);
}

template <class T>
DoubleLink<T>::~DoubleLink(){
    Node<T>* temp = head;
    while(head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
CircleLink<T>::CircleLink(){
    tail = new Node<T>(-1);
    tail->next = tail;
}

template <class T>
CircleLink<T>::~CircleLink(){
    Node<T>* temp = tail;
    int len = size();
    int i = 0;
    while(i < len){
        auto t = temp->next;
        delete temp;
        temp = t;
        i++;
    }
}

template <class T>
int CircleLink<T>::size(){
    auto t = tail->next;
    int ret = 0;
    while(t != tail){
        ret += 1;
        t = t->next;
    }
    return ret;
}

template <class T>
void CircleLink<T>::append(Node<T>* t){
    auto head = tail->next;
    tail->next = t;
    t->next = head;
    tail = t;
}

template <class T>
void CircleLink<T>::print(){
    Node<T>* t = tail->next->next;
    auto len = size();
    int i = 0;
    while(i < len){
        std::cout<<t->data<<std::endl;
        t = t->next;
        i += 1;
    }
}

template <class T>
void CircleLink<T>::deleteFirst(){
    auto len = size();
    if(len == 0){
        return;
    }
    auto head = tail->next;
    auto t = head->next;
    head->next = t->next;
    delete t;
}

template <class T>
void deleteEle(T* arr ,int location, int len){
    for(int i=location; i<len-1; i++){
        arr[i] = arr[i+1];
    }
}


#endif

