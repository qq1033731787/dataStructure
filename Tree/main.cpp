//
// Created by Administrator on 2020/2/24.

//
#include "BinaryTree.h"
#include <gtest/gtest.h>

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

TEST(binaryTree, HaffmanTree){
    int a[] = {6,2,3,4};
    HaffmanTree<int>* ht = new HaffmanTree<int>(a, 4);
    ht->preOrder();
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
