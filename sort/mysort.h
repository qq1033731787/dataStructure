//
// Created by Administrator on 2020/3/1.
//

#ifndef DATASTRUCTURE_MYSORT_H
#define DATASTRUCTURE_MYSORT_H

#include <cmath>
#include <fstream>
#include <iostream>

int t = INT_MAX;
void insertSort(int* arr, int size){
    int tmp;
    for(int i = 1;i < size;i++){
        int j ;
        tmp = arr[i];
        for(j = i - 1;j >= 0 && arr[j] > tmp;j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = tmp;
    }
}

void modInsertSort(int* arr, int size, int delta){
    int tmp;
    for(int i = delta;i < size;i += delta){
        int j ;
        tmp = arr[i];
        for(j = i - delta;j >= 0 && arr[j] > tmp;j -= delta){
            arr[j + delta] = arr[j];
        }
        arr[j + delta] = tmp;
    }
}

void shellSort(int* arr, int size){
    for(int delta = size / 2;delta > 0;delta /= 2){
        for(int i = 0;i < size / delta;i++){
            modInsertSort(arr, size - i, delta);
        }
    }
    modInsertSort(arr, size, 1);
}

void selectSort(int* arr, int size){
    int tmp, minRecord;
    for(int i = 0;i < size;i++){
        minRecord = i;
        for(int j = i + 1;j < size;j++){
            if(arr[j] < arr[minRecord]){
                minRecord = j;
            }
        }
        tmp = arr[minRecord];
        arr[minRecord] = arr[i];
        arr[i] = tmp;
    }
}

void bubbleSort(int* arr, int size){
    bool flag = false;
    int tmp;
    for(int j = size;j > 0;j--){
        for(int i = 0;i < j - 1;i++){
            if(arr[i] > arr[i+1]){
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                flag = true;
            }
        }
        if(!flag){
            break;
        }
    }
}

int partition(int* arr, int i, int j){
    int tmp = arr[i];
    while(i < j){
        while(arr[j] >= tmp && i < j){
            j--;
        }

        if(i < j){
            arr[i] = arr[j];
        }

        while(arr[i] <= tmp && i < j){
            i++;
        }

        if(i < j){
            arr[j] = arr[i];
        }
    }
    arr[i] = tmp;
    return i;
}

void quickSort(int* arr, int i, int j){
    if(i < j){
        int loc = partition(arr, i, j);
        quickSort(arr, i, loc - 1);
        quickSort(arr, loc + 1, j);
    }
}

void merge(int* arr, int i, int j, int m, int n){
    int length = j - i + n - m + 2;
    int s = i;
    int* tmp = new int[length];
    int loc = 0;
    while(i <= j && m <= n){
        if(arr[i] <= arr[m]){
            tmp[loc++] = arr[i++];
        }else{
            tmp[loc++] = arr[m++];
        }
    }

    while(i <= j){
        tmp[loc++] = arr[i++];
    }
    while(m <= n){
        tmp[loc++] = arr[m++];
    }

    m = 0;
    for(i = 0;i < length;i++){
        arr[s++] = tmp[m++];
    }
    delete[] tmp;
}

void mergeSort(int* arr, int i, int j){
    if(i < j){
        mergeSort(arr, i, i + (j - i) / 2);
        mergeSort(arr, i + (j - i) / 2 + 1, j);
        merge(arr, i, i + (j - i) / 2, i + (j - i) / 2 + 1, j);
    }
}


void radixSort(int* arr, int n, int d, int r){
    int* count = new int[r];
    int* tmp = new int[n];

    for(int x = 1;x <= d;x++){
        for(int i = 0;i < n;i++){
            tmp[i] = arr[i];
        }

        for(int i = 0;i < r;i++){
            count[i] = 0;
        }

        for(int i = 0;i < n;i++){
            count[arr[i] % int(pow(10, x)) / int(pow(10, x - 1))]++;
        }
//        std::cout<< "\n\n" << count[0] << "\n";
        for(int i = 1;i < r;i++){
            count[i] = count[i - 1] + count[i];
//            std::cout<< i << "  :  " << count[i] << std::endl;
        }
        for(int i = n - 1;i >= 0;i--){
            arr[--count[tmp[i] % int(pow(10, x)) / int(pow(10, x - 1))]] = tmp[i];
        }
    }
    delete[] count;
    delete[] tmp;
}

class Node{
public:
    int key;
    int next;
    Node(){
        key = 0;
        next = -1;
    }
};

class Queue{
public:
    int head;
    int tail;
    Queue(){
        head = -1;
        tail = -1;
    }
};

void radixSortLink(Node* arr, int n, int d, int r){
    Queue queue[r];
    int first = 0;

    for(int x = 1;x <= d;x++){
        //distribute
        for(int i = 0;i < r;i++){
            queue[i].head = -1;
            queue[i].tail = -1;
        }

        for(int i = first;i != -1;i = arr[i].next){
            int k = arr[i].key % int(pow(10, x)) / int(pow(10, x - 1));
            if(queue[k].head == -1){
                queue[k].head = queue[k].tail = i;
            } else{
                arr[queue[k].tail].next = i;
                queue[k].tail = i;
            }
        }

        //collect
        int head = -1;
        int tail = -1;
        for(int i = 0;i < r;i++){
            if(head == -1 && queue[i].head != -1){
                head = queue[i].head;
            }

            if(queue[i].head != -1 && tail != -1){
                arr[tail].next = queue[i].head;
            }

            if(queue[i].tail != -1){
               tail = queue[i].tail;
            }
        }
        first = head;
        arr[tail].next = -1;

        for(int i = 0;i < n;i++){
            std::cout<< "KEY:  " << arr[i].key << " NEXT: " << arr[i].next << std::endl;
        }
    }

    //adjust
    int j = first;
    for(int i = 0;i < n - 1;i++){
        Node tmp;
        tmp = arr[j];
        arr[j] = arr[i];
        arr[i] = tmp;
        arr[i].next = j;
        j = tmp.next;
        while (j <= i){
            j = arr[j].next;
        }
    }
}

void indexSort(int* arr, int size){
    int index[size];
    for(int i = 0;i < size;i++){
        index[i] = i;
    }

    //get index array
    int i,j;
    for(i = 1;i < size;i++){
        for(j = i - 1;j >= 0 && arr[index[j]] > arr[i];j--){
            index[j + 1] = index[j];
        }
        index[j + 1] = i;
    }

    //adjust
    for(i = 0;i < size;i++){
        if(index[i] == i){
            continue;
        }

        int cur = i;
        int tmp = arr[i];
        int finalIndex = index[i];
        while(finalIndex != i){
            arr[cur] = arr[finalIndex];
            index[cur] = cur;
            cur = finalIndex;
            finalIndex = index[finalIndex];
        }
        arr[cur] = tmp;
        index[cur] = cur;
    }
}

class matrix{
private:
    int* count;
    int  size;
    int  m[8][8];
public:
    matrix() = default;
    matrix(int m[][8], int size){
        for(int i = 0;i < 8;i++){
            for(int j = 0;j < 8;j++){
                this->m[i][j] = m[i][j];
            }
        }

        this->size = size;
        count = new int[size];
        for(int i = 0;i < size;i++){
            count[i] = 0;
        }
    }

    int& operator [] (int index){
        if(count[index] < size){
            int ret = m[index][count[index]];
            return m[index][count[index]];
        }
        return t;
    }

    void add(int index){
        count[index]++;
    }
};

template <class T>
class loserTree{
private:
    int maxSize;
    int n;
    int lowExt;
    int offset;
    int* B;
    T exts;
    int internalNodes;
    int win;
    void Play(int p, int lc, int rc);
    int winner(int a, int b){
        int aa = exts[a];
        int bb = exts[b];
        return exts[a] <= exts[b] ? a : b;
    }
    int loser(int a, int b){
        return exts[a] <= exts[b] ? b : a;
    }


public:
    loserTree(T& exts, int size){
        n = size;
        B = new int[n - 1];
        this->exts = exts;
        for(internalNodes = 1;internalNodes <= n - 1;internalNodes = (internalNodes + 1) * 2 - 1);
        lowExt = 2 * (n - 1 - ((internalNodes + 1) / 2 - 1));
        offset = internalNodes;
    }
    ~loserTree(){
        delete[] B;
    }
    int getParent(int i){
        if(i < lowExt){
            return (i + offset - 1) / 2;
        }else{
            return (i + 1 - lowExt +  n - 2 - 1) / 2;
        }
    }
    void init();
    void replay(int);

    int remove(){
        std::cout<< exts[win] << std::endl;
        exts.add(win);
        return win;
    }
    void print(){
        std::cout<< win + 1 << std::endl;
        for(int x = 0;x < n - 1;x++){
            std::cout<< B[x] + 1 << std::endl;
        }
        std::cout<< "\n\n\n";
    }
};

template <class T>
void loserTree<T>::Play(int p, int lc, int rc) {
    B[p] = loser(lc, rc);
    int tmp1 = winner(lc, rc);
    while(p > 0 && p % 2 == 0){
        int tmp2 = winner(B[(p - 1) / 2], tmp1);
        B[(p - 1) / 2] = loser(B[(p - 1) / 2], tmp1);
        tmp1 = tmp2;
        p = (p - 1) / 2;
    }

    if(p == 0){
        win = tmp1;
    } else{
        B[(p - 1) / 2] = tmp1;
    }
}

template <class T>
void loserTree<T>::init() {
    int i;
    for(i = 1;i < lowExt;i += 2){
        Play(getParent(i), i - 1, i);
    }

    i = lowExt;
    if(n % 2){
        Play(getParent(i), B[getParent(i)], i);
        i += 2;
    }else{
        i++;
    }

    for(;i < n;i += 2){
        Play(getParent(i), i - 1, i);
    }
    //print();
}

template <class T>
void loserTree<T>::replay(int loc) {
    int p = getParent(loc);
    win = winner(B[p], loc);
    B[p] = loser(B[p], loc);
    while(p > 0){
        int tmp = winner(win, B[(p - 1) / 2]);
        B[(p - 1) / 2] = loser(win, B[(p - 1) / 2]);
        win = tmp;
        p = (p - 1) / 2;
    }
    //print();
}


template <class T>
class minHeap{
private:
    T* arr;
    std::ifstream* stream;
    int ssize;
    int curSize;
    int maxSize;
    void swap(int i, int j);
    void buildHeap();
    int count;
    T pre;
public:
    minHeap(T* tree, int size, int maxsize, std::ifstream* s){
        arr = tree;
        curSize = size;
        maxSize = maxsize;
        count = 0;
        buildHeap();
        this->stream = s;
    }
    ~minHeap() = default;
    int getLeft(int i){return 2*i + 1;}
    int getRight(int i){return 2*i + 2;}
    T removeMin();
    bool insert(T);
    bool insert2(T);
    void siftUp(int pos);
    void siftDown(int pos);
    void replaceSort();
};

template <class T>
void minHeap<T>::swap(int i, int j) {
    T tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

template <class T>
void minHeap<T>::siftDown(int pos) {
    int tmp = pos;
    while(2 * tmp + 1 < curSize){
        int child = 2 * tmp + 1;
        if(child + 1 < curSize && arr[child + 1] < arr[child]){
            child = child + 1;
        }
        if(arr[child] <arr[tmp]){
            swap(child, tmp);
            tmp = child;
        }else{
            break;
        }
    }
}

template <class T>
void minHeap<T>::siftUp(int pos) {
    int tmp = pos;
    while(tmp > 0){
        int parent = (tmp - 1) / 2;
        if(arr[parent] > arr[tmp]){
            swap(parent, tmp);
            tmp = parent;
        } else{
            break;
        }
    }
}

template <class T>
bool minHeap<T>::insert(const T item) {
    if(curSize >= maxSize){
        return false;
    }

    arr[curSize++] = item;
    siftUp(curSize - 1);
    return true;
}

template <class T>
bool minHeap<T>::insert2(const T item) {
    if(curSize >= maxSize){
        std::cout<< "> maxSize" << "\n";
        return false;
    }

    if(item < pre){
        if(count >= maxSize){
            return false;
        }
        arr[maxSize - 1 - count] = item;
        count++;
        return true;
    }

    arr[curSize++] = item;
    siftUp(curSize - 1);
    return true;
}

template <class T>
T minHeap<T>::removeMin() {
    if(curSize == 0){
        exit(1);
    }

    T ret = arr[0];
    arr[0] = arr[curSize - 1];
    curSize--;
    siftDown(0);
    std::cout<< ret << std::endl;
    return ret;
}

template <class T>
void minHeap<T>::buildHeap() {
    for(int i = curSize / 2 - 1;i >= 0;i--){
        siftDown(i);
    }
}

template <class T>
void minHeap<T>::replaceSort() {
    pre = removeMin();
    int i = 0;
    while(!stream->eof() && i < 20){
        i++;
        int tmp;
        (*stream) >> tmp;

        if(!insert2(tmp) || curSize <= 0){
            break;
        }
        pre = removeMin();
    }
    while(curSize > 0){
        removeMin();
    }

    std::cout<< "\nIts Over: now heap is\n ";
    for(int i = 0;i < count;i++){
        std::cout<< arr[maxSize - i - 1] << std::endl;
    }
    std::cout<< "\n\n\n";

    stream->close();
}



#endif //DATASTRUCTURE_MYSORT_H


