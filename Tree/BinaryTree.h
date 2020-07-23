//
// Created by Administrator on 2020/2/24.
//

#ifndef DATASTRUCTURE_BINARYTREE_H
#define DATASTRUCTURE_BINARYTREE_H

#include <iostream>
#include <stack>
#include <queue>

template <class T>
class completeBinaryTree{
private:
    T* arr;
    int size;
public:
    completeBinaryTree(T* tree, int size){
        this->arr = tree;
        this->size = size;
    }
    ~completeBinaryTree(){delete[] arr;}
    int getLeft(int i){return 2*i + 1;}
    int getRight(int i){return 2*i + 2;}
    void preOrder(int);
};

template <class T>
void completeBinaryTree<T>::preOrder(int i) {
    if(i < this->size){
        std::cout<< arr[i] << std::endl;
        preOrder(getLeft(i));
        preOrder(getRight(i));
    }
}


template <class T>
class BinaryTree;

template <class T>
class binarySearchTree;

template <class T>
class HaffmanTree;

template<class T>
class BinaryTreeNode{
friend class BinaryTree<T>;
friend class binarySearchTree<T>;
friend class HaffmanTree<T>;

private:
    T info;
    BinaryTreeNode<T>* left, *right;
public:
    BinaryTreeNode(){
        left = NULL;
        right = NULL;
    }
    explicit BinaryTreeNode(T);
    BinaryTreeNode(T t, BinaryTreeNode<T>* left, BinaryTreeNode<T>* right){
        this->info = t;
        this->left = left;
        this->right = right;
    }
    void setLeftChild(BinaryTreeNode<T>*);
    void setRightChild(BinaryTreeNode<T>*);
    bool isLeaf() const;
    BinaryTreeNode<T>& operator= (const BinaryTreeNode<T>& other);
    bool operator <(BinaryTreeNode<T> other){
        return this->info < other.info;
    }

    bool operator > (BinaryTreeNode<T> other){
        return this->info > other.info;
    }


};

template <class T>
class BinaryTree{
public:
    BinaryTreeNode<T>* root;
public:
    BinaryTree(){root = nullptr;}
    ~BinaryTree();
    explicit BinaryTree(BinaryTreeNode<T>* node){root = node;}
    static void CreateTree(const T& info, BinaryTreeNode<T>* left, BinaryTreeNode<T>* right);
    void FreeTree(BinaryTreeNode<T>*);

    void preOrder(BinaryTreeNode<T>*);
    void inOrder(BinaryTreeNode<T>*);
    void postOrder(BinaryTreeNode<T>*);
    void levelOrder();

    BinaryTreeNode<T>* Parent(BinaryTreeNode<T>*);
    void preOrderNoRecur();
    void inOrderNoRecur();
    void postOrderNoRecur();
};

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(T info){
    this->info = info;
    this->left = NULL;
    this->right = NULL;
}

template <class T>
void BinaryTreeNode<T>::setLeftChild(BinaryTreeNode<T>* l) {
    this->left = l;
}

template <class T>
void BinaryTreeNode<T>::setRightChild(BinaryTreeNode<T>* r) {
    this->right = r;
}

template <class T>
bool BinaryTreeNode<T>::isLeaf() const {
    return !this->right && !this->left;
}

template <class T>
BinaryTreeNode<T>& BinaryTreeNode<T>::operator=(const BinaryTreeNode<T> &other) {
    if(this == &other){
        return *this;
    }
    this->left = other.left;
    this->right = other.right;
    this->info = other.info;
    return *this;
}

template <class T>
void BinaryTree<T>::CreateTree(const T &info, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) {
    auto root = new BinaryTreeNode<T>(info);
    root->left = left;
    root->right = right;
}

template <class T>
void BinaryTree<T>::FreeTree(BinaryTreeNode<T>* node) {
    if(node){
        FreeTree(node->left);
        FreeTree(node->right);
        delete node;
    }
}

template <class T>
BinaryTree<T>::~BinaryTree() {
    FreeTree(root);
}

template <class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T>* node) {
    if(node){
        std::cout << node->info << std::endl;
        preOrder(node->left);
        preOrder(node->right);
    }
}

template <class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T>* node) {
    if(node){
        inOrder(node->left);
        std::cout << node->info << std::endl;
        inOrder(node->right);
    }
}

template <class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T>* node) {
    if(node){
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->info << std::endl;
    }
}

template <class T>
void BinaryTree<T>::preOrderNoRecur() {
    std::stack<BinaryTreeNode<T>* > s;
    auto node = root;
    while(node || !s.empty()){
        if(node){
            std::cout<< node->info << std::endl;
            s.push(node);
            node = node->left;
        }else{
            node = s.top();
            s.pop();
            node = node->right;
        }
    }
}

template <class T>
void BinaryTree<T>::inOrderNoRecur() {
    std::stack<BinaryTreeNode<T>* > s;
    auto node = root;
    while(node || !s.empty()){
        if(node){
            s.push(node);
            node = node->left;
        }else{
            node = s.top();
            s.pop();
            std::cout<< node->info << std::endl;
            node = node->right;
        }
    }
}

template <class T>
void BinaryTree<T>::postOrderNoRecur() {
    std::stack<BinaryTreeNode<T>* > s;
    auto node = root;
    BinaryTreeNode<T>* pre = NULL;
    while(node || !s.empty()){
        if(node){
            s.push(node);
            node = node->left;
        }else{
            node = s.top();
            if(node->right == pre){
                std::cout<< node->info << std::endl;
                s.pop();
                pre = node;
                node = NULL;
            }else {
                node = node->right;
                pre = NULL;
            }
        }
    }
}

template <class T>
void BinaryTree<T>::levelOrder() {
    std::queue<BinaryTreeNode<T>* > q;
    if(root){
        q.push(root);
    }
    while(!q.empty()){
        auto node = q.front();
        std::cout<< node->info << std::endl;
        q.pop();
        if(node->left){
            q.push(node->left);
        }
        if(node->right){
            q.push(node->right);
        }
    }
}

template <class T>
BinaryTreeNode<T> * BinaryTree<T>::Parent(BinaryTreeNode<T>* target) {
    std::stack<BinaryTreeNode<T>* > s;
    auto node = root;
    while(node || !s.empty()){
        if(node){
            if(node->left == target || node->right == target){
                std::cout<< node->info;
                return node;
            }
            //std::cout<< node->info << std::endl;
            s.push(node);
            node = node->left;
        }else{
            node = s.top();
            s.pop();
            node = node->right;
        }
    }
}

template <class T>
class binarySearchTree{
private:
    BinaryTreeNode<T>* root;
public:
    explicit binarySearchTree(BinaryTreeNode<T>* node){root = node;}
    bool insertNode(BinaryTreeNode<T>*);
    bool deleteNode(BinaryTreeNode<T>*);
    BinaryTreeNode<T>* getMostRight(BinaryTreeNode<T>*);
    void levelOrder();
};
template <class T>
void binarySearchTree<T>::levelOrder() {
    std::queue<BinaryTreeNode<T>* > q;
    if(root){
        q.push(root);
    }
    while(!q.empty()){
        auto node = q.front();
        std::cout<< node->info << std::endl;
        q.pop();
        if(node->left){
            q.push(node->left);
        }
        if(node->right){
            q.push(node->right);
        }
    }
}

template <class T>
bool binarySearchTree<T>::insertNode(BinaryTreeNode<T>* node) {
    if(!node){
        return false;
    }

    if(!root){
        root = node;
        return true;
    }

    BinaryTreeNode<T>* pre, *tmp;
    tmp = root;
    bool left;
    while(tmp){
        left = false;
        if(node->info < tmp->info){
            pre = tmp;
            left = true;
            tmp = tmp->left;
        } else if (node->info > tmp->info){
            pre = tmp;
            tmp = tmp->right;
        } else{
            return false;
        }
    }
    if(left){
        pre->left = node;
    } else{
        pre->right = node;
    }
    return true;
}

template <class T>
BinaryTreeNode<T> * binarySearchTree<T>::getMostRight(BinaryTreeNode<T>* node) {
    auto ret = node;
    while(ret->right){
        ret = ret->right;
    }
    return ret;
}

template <class T>
bool binarySearchTree<T>::deleteNode(BinaryTreeNode<T>* node) {
    if(!node || !root){
        return false;
    }

    BinaryTreeNode<T>* pre, *tmp;
    pre = NULL;
    tmp = root;
    bool left = false;
    while(tmp){
        if(node->info < tmp->info){
            pre = tmp;
            left = true;
            tmp = tmp->left;
        } else if (node->info > tmp->info){
            pre = tmp;
            left = false;
            tmp = tmp->right;
        } else{
            break;
        }
    }
    if(!tmp){
        return false;
    }

    std::cout<< "LEFT" << std::boolalpha << left << " PRE:  " << pre << std::endl;
    if(!tmp->left){
        if(left){
            if(pre){
                pre->left = tmp->right;
            }else{
                root = tmp->right;
            }
        }else{
            if(pre){
                pre->right = tmp->right;
            } else{
                root = tmp->right;
            }
        }
    }else{
        BinaryTreeNode<T>* rightPre, *rightNode;
        rightNode = tmp->left;
        rightPre = tmp;
        while(rightNode->right){
            rightPre = rightNode;
            rightNode = rightNode->right;
        }

        if(rightPre == tmp){
            tmp->left = rightNode->left;
        }else{
            rightPre->right = rightNode->left;
        }

        rightNode->left = tmp->left;
        rightNode->right = tmp->right;

        if(!pre){
            tmp = root;
            root = rightNode;
        }else{
            if(left){
                pre->left = rightNode;
            }else{
                pre->right = rightNode;
            }
        }

        delete tmp;
    }
}

template <class T>
class minHeap{
private:
    T* arr;
    int curSize;
    int maxSize;
    void swap(int i, int j);
    void buildHeap();
public:
    minHeap(T* tree, int size, int maxsize){
        arr = tree;
        curSize = size;
        maxSize = maxsize;
        buildHeap();
    }
    ~minHeap() = default;
    int getLeft(int i){return 2*i + 1;}
    int getRight(int i){return 2*i + 2;}
    T removeMin();
    bool insert(T);
    void siftUp(int pos);
    void siftDown(int pos);
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
        if(child + 1 < curSize && *(arr[child + 1]) < *(arr[child])){
            child = child + 1;
        }
        if(*(arr[child]) < *(arr[tmp])){
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
        if(*(arr[parent]) > *(arr[tmp])){
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
T minHeap<T>::removeMin() {
    if(curSize == 0){
        exit(1);
    }

    T ret = arr[0];
    arr[0] = arr[curSize - 1];
    curSize--;
    siftDown(0);
    return ret;
}

template <class T>
void minHeap<T>::buildHeap() {
    for(int i = curSize / 2 - 1;i >= 0;i--){
        siftDown(i);
    }
}

template <class T>
class HaffmanTree{
private:
    BinaryTreeNode<T>* root;
    BinaryTreeNode<T>* Merge(BinaryTreeNode<T>* left, BinaryTreeNode<T>* right);
    void DeleteTree(BinaryTreeNode<T>*);

public:
    HaffmanTree(const int* arr, int size);
    ~HaffmanTree(){DeleteTree(root);}
    void preOrder();
};

template <class T>
void HaffmanTree<T>::preOrder() {
    std::stack<BinaryTreeNode<T>* > s;
    auto node = root;
    while(node || !s.empty()){
        if(node){
            std::cout<< node->info << std::endl;
            s.push(node);
            node = node->left;
        }else{
            node = s.top();
            s.pop();
            node = node->right;
        }
    }
}

template <class T>
void HaffmanTree<T>::DeleteTree(BinaryTreeNode<T>* node) {
    if(node){
        DeleteTree(node->left);
        DeleteTree(node->right);
        delete node;
    }
}

template <class T>
BinaryTreeNode<T>* HaffmanTree<T>::Merge(BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) {
    auto parent = new BinaryTreeNode<T>(left->info + right->info, left, right);
    return parent;
}

template <class T>
HaffmanTree<T>::HaffmanTree(const int *arr, int size) {
    BinaryTreeNode<T>* first, *second;
    auto nodes = new BinaryTreeNode<T>*[size];
    for(int i = 0;i < size;i++){
        nodes[i] = new BinaryTreeNode<T>;
        nodes[i]->info = arr[i];
    }

    minHeap<BinaryTreeNode<T>* > minHeap(nodes, size, size) ;
    for(int i = 0;i < size - 1;i++){
        first = minHeap.removeMin();
        //std::cout<< first->info << std::endl;
        second = minHeap.removeMin();
        auto parent = Merge(first, second);
        minHeap.insert(parent);
        root = parent;
    }
}


#endif //DATASTRUCTURE_BINARYTREE_H
