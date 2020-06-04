//
// Created by Administrator on 2020/2/27.
//

#ifndef DATASTRUCTURE_TREE_H
#define DATASTRUCTURE_TREE_H

#include<list>
#include <iostream>
#include <iterator>

template <class T>
class TreeNode{
public:
    virtual ~TreeNode() = default;
    virtual T getValue() = 0;
    virtual TreeNode<T>* getMostLeftChild() = 0;
    virtual TreeNode<T>* getRightSibing() = 0;
    virtual void setValue(T&) = 0;
    virtual void setChild(TreeNode<T>*) = 0;
    virtual void setParent(TreeNode<T>*) = 0;
    virtual void setSibing(TreeNode<T>*) = 0;
    virtual void setNext(TreeNode<T>*) = 0;
    virtual bool isLeaf() = 0;
    virtual std::list<TreeNode<T>*>& getChilds(){
        auto ret = new std::list<TreeNode<T>*>();
        return *ret;
    }
    virtual int getChildsNum() = 0;
};

template <class T>
class DualTagTreeNode{
public:
    T val;
    int ltag;
    int rtag;
    DualTagTreeNode() = default;
    DualTagTreeNode(int v, int l, int r){
        val = v;
        l = ltag;
        r = rtag;
    }
};

template <class T>
class DegreeTreeNode{
public:
    T val;
    int degree;
    DegreeTreeNode() = default;
    DegreeTreeNode(T v, int d){
        val = v;
        degree = d;
    }
};

template <class T>
class Tree{
public:
    virtual void preOrder(TreeNode<T>*);
    virtual void postOrder(TreeNode<T>*);
    virtual ~Tree() = default;
    virtual TreeNode<T>* getRoot() = 0;
    virtual void PreOrder();
    virtual void PostOrder();
    virtual void LevelOrder();
};

template <class T>
void Tree<T>::preOrder(TreeNode<T>* node) {
    while(node){
        std::cout<< node->getValue() << std::endl;
        preOrder(node->getMostLeftChild());
        node = node->getRightSibing();
    }
}


template <class T>
void Tree<T>::postOrder(TreeNode<T>* node) {
    while(node){
        std::cout<< node->getValue() << std::endl;
        preOrder(node->getMostLeftChild());
        node = node->getRightSibing();
    }
}


template <class T>
void Tree<T>::PreOrder() {}


template <class T>
void Tree<T>::PostOrder() {}


template <class T>
void Tree<T>::LevelOrder() {}

template <class T>
class ListOfChildTreeNode : public TreeNode<T>{
private:
    T val;
    TreeNode<T>* parent, *next;
    std::list<TreeNode<T>*> childs;
public:
    ListOfChildTreeNode();
    ~ListOfChildTreeNode() = default;
    explicit ListOfChildTreeNode(T v):val(v),parent(NULL),next(NULL){}
    T getValue();
    TreeNode<T>* getMostLeftChild();
    TreeNode<T>* getRightSibing();
    void setValue(T&);
    void setChild(TreeNode<T>*);
    void setParent(TreeNode<T>*);
    void setSibing(TreeNode<T>*);
    void setNext(TreeNode<T>*);
    bool isLeaf();
    std::list<TreeNode<T>*>& getChilds(){return childs;}
    int getChildsNum(){return childs.size();}
};

template <class T>
ListOfChildTreeNode<T>::ListOfChildTreeNode():
    parent(NULL),
    next(NULL){}


template <class T>
bool ListOfChildTreeNode<T>::isLeaf() {
    return childs.empty();
}

template <class T>
T ListOfChildTreeNode<T>::getValue() {
    return val;
}

template <class T>
void ListOfChildTreeNode<T>::setParent(TreeNode<T>* node) {
    parent = node;
}

template <class T>
void ListOfChildTreeNode<T>::setChild(TreeNode<T>* node){
    childs.push_back(node);
}

template <class T>
void ListOfChildTreeNode<T>::setValue(T& v) {
    val = v;
}

template <class T>
TreeNode<T> * ListOfChildTreeNode<T>::getMostLeftChild() {
    if(childs.empty()){
        return NULL;
    }
    return childs.front();
}

template <class T>
TreeNode<T> * ListOfChildTreeNode<T>::getRightSibing() {
    auto node = this->parent;
    if(!node){
        return  NULL;
    }

    for(auto i = node->getChilds().begin();i != node->getChilds().end();i++){
        if(*i == this){
            auto tmp = i;
            if(++tmp == node->getChilds().end()){
                return NULL;
            }
            return *(++i);
        }
    }
    return NULL;
}

template <class T>
void ListOfChildTreeNode<T>::setSibing(TreeNode<T>* node) {
    auto tmp = this->parent;
    for(auto i = tmp->getChilds().begin();i != tmp->getChilds().end();i++){
        tmp->getChilds().insert(++i, node);
    }
}

template <class T>
void ListOfChildTreeNode<T>::setNext(TreeNode<T>* node) {
    next = node;
}

template <class T>
class ListOfChildTree : public Tree<T>{
private:
    ListOfChildTreeNode<T>* root;
//    void preOrder(TreeNode<T>*);
//    void postOrder(TreeNode<T>*);
public:
    void preOrder(TreeNode<T>*);
    void postOrder(TreeNode<T>*);
    explicit ListOfChildTree(ListOfChildTreeNode<T>* node):root(node){}
    TreeNode<T>* getRoot();
    void PreOrder();
    void PostOrder();
    void LevelOrder();
};

template <class T>
TreeNode<T> * ListOfChildTree<T>::getRoot() {
    return root;
}

template <class T>
void ListOfChildTree<T>::preOrder(TreeNode<T>* node) {
    while(node){
        std::cout<< node->getValue() << std::endl;
        preOrder(node->getMostLeftChild());
        node = node->getRightSibing();
    }
}

template <class T>
void ListOfChildTree<T>::postOrder(TreeNode<T>* node){
    while(node){
        std::cout<< node->getValue() << std::endl;
        preOrder(node->getMostLeftChild());
        node = node->getRightSibing();
    }
}

template <class T>
void ListOfChildTree<T>::PreOrder() {
    preOrder(root);
}

template <class T>
void ListOfChildTree<T>::PostOrder() {
    postOrder(root);
}

template <class T>
void ListOfChildTree<T>::LevelOrder() {

}

template <class T>
class lcrsDynamicTreeNode : public TreeNode<T>{
private:
    TreeNode<T>* left, *right, *next, *parent;
    T val;
public:
    lcrsDynamicTreeNode();
    explicit lcrsDynamicTreeNode(T);
    T getValue();
    TreeNode<T>* getMostLeftChild();
    TreeNode<T>* getRightSibing();
    void setValue(T&);
    void setChild(TreeNode<T>*);
    void setParent(TreeNode<T>*);
    void setSibing(TreeNode<T>*);
    void setNext(TreeNode<T>*);
    bool isLeaf();
};

template <class T>
lcrsDynamicTreeNode<T>::lcrsDynamicTreeNode(){
    left = right = parent = next = NULL;
    val = 0;
}

template <class T>
lcrsDynamicTreeNode<T>::lcrsDynamicTreeNode(T t) {
    val = t;
    left = right = parent = next = NULL;
}

template <class T>
T lcrsDynamicTreeNode<T>::getValue() {
    return val;
}

template <class T>
TreeNode<T> * lcrsDynamicTreeNode<T>::getMostLeftChild() {
    return left;
}

template <class T>
TreeNode<T> * lcrsDynamicTreeNode<T>::getRightSibing() {
    return right;
}

template <class T>
bool lcrsDynamicTreeNode<T>::isLeaf() {
    return left == nullptr;
}

template <class T>
void lcrsDynamicTreeNode<T>::setValue(T& t) {
    val = t;
}

template <class T>
void lcrsDynamicTreeNode<T>::setNext(TreeNode<T>* node) {
    next = node;
}

template <class T>
void lcrsDynamicTreeNode<T>::setChild(TreeNode<T>* node) {
    if(!left){
        left = node;
        return;
    }

    TreeNode<T>* pre = left;
    TreeNode<T>* tmp = left->getRightSibing();
    while(tmp){
        pre = tmp;
        tmp = tmp->getRightSibing();
    }
    pre->setSibing(node);
}

template <class T>
void lcrsDynamicTreeNode<T>::setSibing(TreeNode<T>* node) {
    right = node;
}

template <class T>
void lcrsDynamicTreeNode<T>::setParent(TreeNode<T>*) {}


template <class T>
class lcrsDynamicTree : public Tree<T>{
private:
    TreeNode<T>* root;
public:
    explicit lcrsDynamicTree(TreeNode<T>* node){
        root = node;
    }

    explicit lcrsDynamicTree(DualTagTreeNode<T>* node, int size);

    explicit lcrsDynamicTree(DegreeTreeNode<T>* node, int size);

    TreeNode<T>* getRoot(){
        return root;
    }
    virtual void PreOrder();
    virtual void PostOrder();
    virtual void LevelOrder();
};

template <class T>
void lcrsDynamicTree<T>::PreOrder() {
    Tree<T>::preOrder(root);
}

template <class T>
void lcrsDynamicTree<T>::PostOrder() {
    Tree<T>::postOrder(root);
}

template <class T>
void lcrsDynamicTree<T>::LevelOrder() {}


template <class T>
lcrsDynamicTree<T>::lcrsDynamicTree(DualTagTreeNode<T>* Dnodes, int size) {
    //add ~lcrsDynamicTree()
    if(size == 0){
        return;
    }
    auto nodes = new lcrsDynamicTreeNode<T>*[size];
    for(int i = 0;i < size;i++){
        nodes[i] = new lcrsDynamicTreeNode<T>();
        nodes[i]->setValue(Dnodes[i].val);
    }

    std::stack<lcrsDynamicTreeNode<T>*> s;
    for(int i = 0;i < size;i++){
        if(Dnodes[i].rtag){
            s.push(nodes[i]);
        }

        if(Dnodes[i].ltag){
            nodes[i]->setChild(nodes[i + 1]);
        }else{
            if(!s.empty()){
                lcrsDynamicTreeNode<T>* node = s.top();
                s.pop();
                node->setSibing(nodes[i + 1]);
            }
        }
    }

    root = nodes[0];
    delete[] nodes;
}

template <class T>
lcrsDynamicTree<T>::lcrsDynamicTree(DegreeTreeNode<T> *Dnodes, int size) {
    if(size == 0){
        return;
    }
    auto nodes = new lcrsDynamicTreeNode<T>*[size];
    for(int i = 0;i < size;i++){
        nodes[i] = new lcrsDynamicTreeNode<T>();
        nodes[i]->setValue(Dnodes[i].val);
    }

    TreeNode<T>* pre = NULL;
    std::stack<lcrsDynamicTreeNode<T>*> s;

    for(int i = 0;i < size;i++){
        std::stack<lcrsDynamicTreeNode<T>*> tmp;
        int dg = Dnodes[i].degree;
        for(int j = 0;j < dg;j++){
            if(!s.empty()){
                tmp.push(s.top());
                s.pop();
            }
        }

        for(int j = 0;j < dg;j++){
            nodes[i]->setChild(tmp.top());
            tmp.pop();
        }

        s.push(nodes[i]);
    }

    std::stack<lcrsDynamicTreeNode<T>*> tmp;
    int len = s.size();
    for(int i = 0;i < len;i++){
        tmp.push(s.top());
        s.pop();
    }

    root = tmp.top();
    pre = root;
    tmp.pop();
    while(!tmp.empty()){
        pre->setSibing(tmp.top());
        tmp.pop();
    }

    delete[] nodes;
}


template <class T>
class dynamicListTreeNode : public TreeNode<T>{
private:
    T val;
    int size;
    std::list<dynamicListTreeNode<T>*> childs;
public:
    dynamicListTreeNode():val(0),size(0){}
    ~dynamicListTreeNode() = default;
    explicit dynamicListTreeNode(T v):val(v),size(0){}
    T getValue();
    TreeNode<T>* getMostLeftChild();
    TreeNode<T>* getRightSibing();
    void setValue(T&);
    void setChild(TreeNode<T>*);
    void setParent(TreeNode<T>*);
    void setSibing(TreeNode<T>*);
    void setNext(TreeNode<T>*);
    bool isLeaf();
    std::list<TreeNode<T>*>& getChilds() {return childs;}
};

class ParTreeNode{
public:
    ParTreeNode* parent;
    int val;
    int count;
    ParTreeNode(){
        parent = NULL;
        val = 0;
        count = 0;
    }
    void setParent(ParTreeNode* parent){this->parent = parent;}
    ParTreeNode* getParent(){return parent;}
    void setCounts(int count){this->count = count;}
    int getCounts(){return count;}
};

class ParTree{
public:
    ParTreeNode* arr;
    int size;
    explicit ParTree(int size){
        this->size = size;
        arr = new ParTreeNode[size];
    }

    virtual ~ParTree(){
        delete[] arr;
    }

    ParTreeNode* Find(ParTreeNode* node);
    bool Different(int node1, int node2);
    void Union(int node1, int node2);
};

ParTreeNode* ParTree::Find(ParTreeNode* node){
    while(node->getParent() != NULL){
        node = node->getParent();
    }
    return node;
}

bool ParTree::Different(int node1_index, int node2_index) {
    auto node1 = &arr[node1_index];
    auto node2 = &arr[node2_index];
    return !(Find(node1) == Find(node2) && !(node1 == NULL && node2 == NULL));
}

void ParTree::Union(int node1_index, int node2_index) {
    auto node1 = &arr[node1_index];
    auto node2 = &arr[node2_index];
    node1 = Find(node1);
    node2 = Find(node2);
    if(node1 != node2){
        if(node1->getCounts() < node2->getCounts()){
            auto tmp = node2;
            node2 = node1;
            node1 = tmp;
        }

        node2->setParent(node1);
        node1->setCounts(node2->getCounts() + node1->getCounts());
    }
}





#endif //DATASTRUCTURE_TREE_H
