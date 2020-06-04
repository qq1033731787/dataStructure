//
// Created by Administrator on 2020/2/24.

//
#include <algorithm>
#include "BinaryTree.h"
#include "Tree.h"
#include <gtest/gtest.h>

bool cmp(TreeNode<int> a, TreeNode<int> b){
    return a.getChildsNum() > b.getChildsNum();
}

void mapDye(TreeNode<int>* mnodes, int size){
    std::vector<bool> records(size, false);
    int colors = 0;
    int curDyedNum = 0;
    std::sort(mnodes, mnodes + size);

    records[0] = true;
    colors++;
    curDyedNum++;
    int start = 0;
    while(curDyedNum < size){

    }


}

//TEST(binaryTree, minHeap){
//    int* a = new int[20]{19, 8, 35, 65, 40, 3, 7,45};
//    minHeap<int> mh(a, 8, 20);
////    mh.insert();
//    ASSERT_EQ(mh.removeMin(), 3);
//    ASSERT_EQ(mh.removeMin(), 7);
//    ASSERT_EQ(mh.removeMin(), 8);
//    ASSERT_EQ(mh.removeMin(), 19);
//    ASSERT_EQ(mh.removeMin(), 35);
//    ASSERT_EQ(mh.removeMin(), 40);
//    ASSERT_EQ(mh.removeMin(), 45);
//    ASSERT_EQ(mh.removeMin(), 65);
//
//    std::cout<< "OVER\n";
//    delete[] a;
//}

//TEST(binaryTree, HaffmanTree){
//    int a[] = {6,2,3,4};
//    HaffmanTree<int>* ht = new HaffmanTree<int>(a, 4);
//    ht->preOrder();
//}

//TEST(Tree, listOfChildTree){
//    ListOfChildTreeNode<char> a('A');
//    ListOfChildTreeNode<char> b('B');
//    ListOfChildTreeNode<char> c('C');
//    ListOfChildTreeNode<char> d('D');
//    ListOfChildTreeNode<char> e('E');
//    ListOfChildTreeNode<char> f('F');
//    ListOfChildTreeNode<char> g('G');
//    ListOfChildTreeNode<char> h('H');
//    ListOfChildTreeNode<char> i('I');
//    ListOfChildTreeNode<char> j('J');
//    ListOfChildTreeNode<char> k('K');
//    ListOfChildTreeNode<char> l('L');
//
//    a.setChild(&b);
//    a.setChild(&c);
//    a.setNext(&b);
//
//    b.setChild(&d);
//    b.setChild(&e);
//    b.setParent(&a);
//    b.setNext(&c);
//
//    c.setChild(&f);
//    c.setChild(&g);
//    c.setChild(&h);
//    c.setParent(&a);
//    c.setNext(&d);
//
//    d.setChild(&i);
//    d.setChild(&j);
//    d.setParent(&b);
//    d.setNext(&e);
//
//    e.setParent(&b);
//    e.setNext(&f);
//
//    f.setParent(&c);
//    f.setNext(&g);
//
//    g.setChild(&k);
//    g.setChild(&l);
//    g.setParent(&c);
//    g.setNext(&h);
//
//    h.setParent(&b);
//    h.setNext(&i);
//
//    i.setParent(&d);
//    i.setNext(&j);
//
//    j.setParent(&d);
//    j.setNext(&k);
//
//    k.setParent(&g);
//    k.setNext(&l);
//
//    l.setParent(&g);
//
//    ListOfChildTree<char> tree(&a);
//
//    ASSERT_EQ('B', a.getMostLeftChild()->getValue());
//    ASSERT_EQ('D', b.getMostLeftChild()->getValue());
//    ASSERT_EQ('I', d.getMostLeftChild()->getValue());
//    ASSERT_EQ('J', i.getRightSibing()->getValue());
//    ASSERT_EQ('E', d.getRightSibing()->getValue());
//    ASSERT_EQ(NULL, j.getRightSibing());
//    ASSERT_EQ(NULL, c.getRightSibing());
//    ASSERT_EQ(NULL, h.getRightSibing());
//    ASSERT_EQ(NULL, h.getMostLeftChild());
//    ASSERT_EQ(NULL, a.getRightSibing());
//
//    tree.InOrder();
//
//}

//TEST(Tree, lcrsDynamicTree){
//    lcrsDynamicTreeNode<char> a('A');
//    lcrsDynamicTreeNode<char> b('B');
//    lcrsDynamicTreeNode<char> c('C');
//    lcrsDynamicTreeNode<char> d('D');
//    lcrsDynamicTreeNode<char> e('E');
//    lcrsDynamicTreeNode<char> f('F');
//    lcrsDynamicTreeNode<char> g('G');
//    lcrsDynamicTreeNode<char> h('H');
//    lcrsDynamicTreeNode<char> i('I');
//    lcrsDynamicTreeNode<char> j('J');
//    lcrsDynamicTreeNode<char> k('K');
//    lcrsDynamicTreeNode<char> l('L');
//
//    a.setChild(&b);
//    a.setChild(&c);
//    a.setNext(&b);
//
//    b.setChild(&d);
//    b.setChild(&e);
//    b.setNext(&c);
//
//    c.setChild(&f);
//    c.setChild(&g);
//    c.setChild(&h);
//    c.setNext(&d);
//
//    d.setChild(&i);
//    d.setChild(&j);
//    d.setNext(&e);
//
//    e.setNext(&f);
//
//    f.setNext(&g);
//
//    g.setChild(&k);
//    g.setChild(&l);
//    g.setNext(&h);
//
//    h.setNext(&i);
//
//    i.setNext(&j);
//
//    j.setNext(&k);
//
//    k.setNext(&l);
//
//    ASSERT_EQ('B', a.getMostLeftChild()->getValue());
//    ASSERT_EQ('C', b.getRightSibing()->getValue());
//    ASSERT_EQ('D', b.getMostLeftChild()->getValue());
//
//
//    lcrsDynamicTree<char> tree(&a);
//    tree.InOrder();
//}

//TEST(Tree, Dnode){
//    int r[10] = {1, 1, 1, 1, 0, 0, 0, 1, 0, 0};
//    int l[10] = {1, 0, 1, 0, 0, 0, 1, 1, 0, 0};
//    DualTagTreeNode<char> Dnodes[10];
//    for(int i = 0;i < 10;i++){
//        Dnodes[i].val = 65 + i;
//        Dnodes[i].ltag = l[i];
//        Dnodes[i].rtag = r[i];
//    }
//
//    Dnodes[3].val = 'E';
//    Dnodes[4].val = 'F';
//    Dnodes[5].val = 'D';
//    Dnodes[6].val = 'G';
//    Dnodes[7].val = 'H';
//    Dnodes[8].val = 'J';
//    Dnodes[9].val = 'I';
//
//    lcrsDynamicTree<char> lt(Dnodes, 10);
//    lt.PreOrder();
//}

TEST(Tree, Dnode){
    int d[10] = {0, 0, 0, 2, 0, 3, 0, 1, 0, 2};
    DegreeTreeNode<char> Dnodes[10];
    for(int i = 0;i < 10;i++){
        Dnodes[i].val = 65 + i;
        Dnodes[i].degree = d[i];
    }

    Dnodes[0].val = 'B';
    Dnodes[1].val = 'E';
    Dnodes[2].val = 'F';
    Dnodes[3].val = 'C';
    Dnodes[4].val = 'D';
    Dnodes[5].val = 'A';
    Dnodes[6].val = 'J';
    Dnodes[7].val = 'H';
    Dnodes[8].val = 'I';
    Dnodes[9].val = 'G';

    lcrsDynamicTree<char> lt(Dnodes, 10);
    lt.PreOrder();
}


int main(){
//    BinaryTreeNode<int>* nodeG = new BinaryTreeNode<int>(20, nullptr, nullptr);
//    BinaryTreeNode<int>* node92 = new BinaryTreeNode<int>(92, nullptr, nullptr);
//    BinaryTreeNode<int>* nodeH = new BinaryTreeNode<int>(88, nullptr, node92);
////    BinaryTreeNode<int>* nodeI = new BinaryTreeNode<int>(120, nullptr, nullptr);
//    BinaryTreeNode<int>* nodeD = new BinaryTreeNode<int>(5, nullptr, nullptr);
//    BinaryTreeNode<int>* nodeE = new BinaryTreeNode<int>(35, nodeG, nullptr);
//    BinaryTreeNode<int>* nodeB = new BinaryTreeNode<int>(19, nodeD, nodeE);
//
//    BinaryTreeNode<int>* node53 = new BinaryTreeNode<int>(53, nullptr, nullptr);
//    BinaryTreeNode<int>* node52 = new BinaryTreeNode<int>(52, nullptr, node53);
//    BinaryTreeNode<int>* nodeF = new BinaryTreeNode<int>(100, nodeH, nullptr);
//    BinaryTreeNode<int>* nodeC = new BinaryTreeNode<int>(55, node52, nodeF);
//    BinaryTreeNode<int>* nodeA = new BinaryTreeNode<int>(50, nodeB, nodeC);
////    BinaryTreeNode<int>* nodeG = new BinaryTreeNode<int>('G', nullptr, nullptr);
////    BinaryTreeNode<int>* nodeH = new BinaryTreeNode<int>('H', nullptr, nullptr);
////    BinaryTreeNode<int>* nodeI = new BinaryTreeNode<int>('I', nullptr, nullptr);
////    BinaryTreeNode<int>* nodeD = new BinaryTreeNode<int>('D', nullptr, nullptr);
////    BinaryTreeNode<int>* nodeE = new BinaryTreeNode<int>('E', nodeG, nullptr);
////    BinaryTreeNode<int>* nodeB = new BinaryTreeNode<int>('B', nodeD, nodeE);
////    BinaryTreeNode<int>* nodeF = new BinaryTreeNode<int>('F', nodeH, nodeI);
////    BinaryTreeNode<int>* nodeC = new BinaryTreeNode<int>('C', nullptr, nodeF);
////    BinaryTreeNode<int>* nodeA = new BinaryTreeNode<int>('A', nodeB, nodeC);
////    auto n = BinaryTreeNode<int>(10);
//    //BinaryTree<int>* tree = new BinaryTree<int>(nodeA);
//    binarySearchTree<int>* bs = new binarySearchTree<int>(nodeA);
//
//    bs->deleteNode(nodeC);
//    bs->deleteNode(nodeG);
//    bs->deleteNode(node92);
//    bs->deleteNode(nodeD);
//    bs->deleteNode(nodeB);
//    bs->deleteNode(nodeA);
//    bs->deleteNode(nodeE);
//    //bs->deleteNode(nodeA);
//    bs->levelOrder();
//    tree->preOrder(tree->root);
//    tree->preOrderNoRecur();
//    tree->inOrder(tree->root);
//    tree->inOrderNoRecur();
//    tree->postOrder(tree->root);
//    tree->postOrderNoRecur();
//    tree->Parent(nodeH);
//    char a[] = {'A','B','C','D','E','F','G','H','I','J','K','L'};
//    completeBinaryTree<int>* ct = new completeBinaryTree<char >(a, 12);
//    ct->preOrder(0);
    testing::InitGoogleTest();
    std::cout<< RUN_ALL_TESTS();
}
