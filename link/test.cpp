#include "test.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

int g = 0;
class Node{
public:
    int item;
    Node* next1;
    ~Node(){ g++;}
};

int main() {
    int a[] = {1, 2, 3};
    int b = 0;
    std::cout << a[++b];
//    Node *n = new Node[10];
//    size_t* nn = reinterpret_cast<size_t *>(n);
//    for(int i = -1; i > -4; i--){
//        std::cout << nn[i] << std::endl;
//    }
//    delete[] n;
//    std::cout << "G:" << g << std::endl;
}
//int main() {
//    unsigned char *p = (unsigned char*)malloc(4*sizeof(unsigned char));
//    memset(p,0,4);
//    strcpy((char*)p,"abcdabcd"); // **deliberately storing 8bytes**
//    std::cout << p;
//    free(p); // Obvious Crash, but I need how it works and why crash.
//    std::cout << p;
//    return 0;
//}


//int main() {
////    void* n = malloc(4);
//    Node *n = new Node[10];
//    size_t* nn = reinterpret_cast<size_t *>(n);
////    int *nn = reinterpret_cast<int *>(n);
////    std::cout << sizeof(Node) << std::endl;
//    std::cout << nn[-1] << std::endl;
////    std::cout << *nn-- << std::endl;
////    Node* nnn = static_cast<Node*>(n);
////    std::cout << nnn->item << std::endl;
//    delete[] n;
//}