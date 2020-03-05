//
// Created by Administrator on 2020/3/1.
//

#ifndef DATASTRUCTURE_MYSORT_H
#define DATASTRUCTURE_MYSORT_H

#include <cmath>

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

void bucketSort(int* arr, int size){
    int* count = new int[10];
    int* tmp = new int[size];
    int i ;

    for(i = 0;i < size;i++){
        tmp[i] = arr[i];
    }
    for(i = 0;i < 10;i++){
        count[i] = 0;
    }

    for(i = 0;i < size;i++){
        count[arr[i]]++;
    }

    for(i = 1;i < 10;i++){
        count[i] = count[i] + count[i - 1];
    }

    for(i = size - 1;i >= 0;i--){
        arr[--count[tmp[i]]] = tmp[i];
    }
    delete[] tmp;
    delete[] count;
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


#endif //DATASTRUCTURE_MYSORT_H
