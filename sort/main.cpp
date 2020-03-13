//
// Created by Administrator on 2020/3/1.
//
#include <gtest/gtest.h>
#include "mysort.h"

//TEST(sort, insertSort){
//    int arr[] = {45, 34, 78, 12, 34, 32, 29, 64};
//    insertSort(arr, 8);
//
//    for(int i = 0;i < 8;i++){
//        std::cout<< arr[i] << std::endl;
//    }
//
//    ASSERT_EQ(arr[0], 12);
//    ASSERT_EQ(arr[1], 29);
//    ASSERT_EQ(arr[2], 32);
//    ASSERT_EQ(arr[3], 34);
//    ASSERT_EQ(arr[4], 34);
//    ASSERT_EQ(arr[5], 45);
//    ASSERT_EQ(arr[6], 64);
//    ASSERT_EQ(arr[7], 78);
//}
//
//TEST(sort, shellSort){
//    int arr[] = {45, 34, 78, 12, 34, 32, 29, 64};
//    shellSort(arr, 8);
//
//    for(int i = 0;i < 8;i++){
//        std::cout<< arr[i] << std::endl;
//    }
//
//    ASSERT_EQ(arr[0], 12);
//    ASSERT_EQ(arr[1], 29);
//    ASSERT_EQ(arr[2], 32);
//    ASSERT_EQ(arr[3], 34);
//    ASSERT_EQ(arr[4], 34);
//    ASSERT_EQ(arr[5], 45);
//    ASSERT_EQ(arr[6], 64);
//    ASSERT_EQ(arr[7], 78);
//}

//TEST(sort, selectSort){
//    int arr[] = {45, 34, 78, 12, 34, 32, 29, 64};
//    shellSort(arr, 8);
//
//    for(int i = 0;i < 8;i++){
//        std::cout<< arr[i] << std::endl;
//    }
//
//    ASSERT_EQ(arr[0], 12);
//    ASSERT_EQ(arr[1], 29);
//    ASSERT_EQ(arr[2], 32);
//    ASSERT_EQ(arr[3], 34);
//    ASSERT_EQ(arr[4], 34);
//    ASSERT_EQ(arr[5], 45);
//    ASSERT_EQ(arr[6], 64);
//    ASSERT_EQ(arr[7], 78);
//}

//TEST(sort, bubbleSort){
//    int arr[] = {45, 34, 78, 12, 34, 32, 29, 64};
//    bubbleSort(arr, 8);
//
//    for(int i = 0;i < 8;i++){
//        std::cout<< arr[i] << std::endl;
//    }
//
//    ASSERT_EQ(arr[0], 12);
//    ASSERT_EQ(arr[1], 29);
//    ASSERT_EQ(arr[2], 32);
//    ASSERT_EQ(arr[3], 34);
//    ASSERT_EQ(arr[4], 34);
//    ASSERT_EQ(arr[5], 45);
//    ASSERT_EQ(arr[6], 64);
//    ASSERT_EQ(arr[7], 78);
//}

//TEST(sort, bubbleSort){
//    int arr[] = {45, 34, 78, 12, 34, 32, 29, 64};
//    quickSort(arr, 0, 7);
//
//    for(int i = 0;i < 8;i++){
//        std::cout<< arr[i] << std::endl;
//    }
//
//    ASSERT_EQ(arr[0], 12);
//    ASSERT_EQ(arr[1], 29);
//    ASSERT_EQ(arr[2], 32);
//    ASSERT_EQ(arr[3], 34);
//    ASSERT_EQ(arr[4], 34);
//    ASSERT_EQ(arr[5], 45);
//    ASSERT_EQ(arr[6], 64);
//    ASSERT_EQ(arr[7], 78);
//}

//TEST(sort, mergeSort){
//    int arr[] = {45, 34, 78, 12, 34, 32, 29, 64};
//    mergeSort(arr, 0, 7);
//
//    for(int i = 0;i < 8;i++){
//        std::cout<< arr[i] << std::endl;
//    }
//
//    ASSERT_EQ(arr[0], 12);
//    ASSERT_EQ(arr[1], 29);
//    ASSERT_EQ(arr[2], 32);
//    ASSERT_EQ(arr[3], 34);
//    ASSERT_EQ(arr[4], 34);
//    ASSERT_EQ(arr[5], 45);
//    ASSERT_EQ(arr[6], 64);
//    ASSERT_EQ(arr[7], 78);
//}

//TEST(sort, bucketSort){
//    int arr[] = {5, 3, 7, 2, 4, 2, 9, 4, 2, 3, 4, 5, 1, 3, 3};
//    bucketSort(arr, 15);
//
//    for(int i = 0;i < 15;i++){
//        std::cout<< arr[i] << std::endl;
//    }
//
////    ASSERT_EQ(arr[0], 12);
////    ASSERT_EQ(arr[1], 29);
////    ASSERT_EQ(arr[2], 32);
////    ASSERT_EQ(arr[3], 34);
////    ASSERT_EQ(arr[4], 34);
////    ASSERT_EQ(arr[5], 45);
////    ASSERT_EQ(arr[6], 64);
////    ASSERT_EQ(arr[7], 78);
//}

//TEST(sort, bucketSort){
//    int arr[] = {1197, 3253, 3818, 5239, 2116, 4421, 1688, 2311, 6232};
//    radixSort(arr, 9, 4, 10);
//
//    for(int i = 0;i < 9;i++){
//        std::cout<< arr[i] << std::endl;
//    }

//    ASSERT_EQ(arr[0], 12);
//    ASSERT_EQ(arr[1], 29);
//    ASSERT_EQ(arr[2], 32);
//    ASSERT_EQ(arr[3], 34);
//    ASSERT_EQ(arr[4], 34);
//    ASSERT_EQ(arr[5], 45);
//    ASSERT_EQ(arr[6], 64);
//    ASSERT_EQ(arr[7], 78);
//}

//TEST(sort, radixSortLink) {
//    int arr[] = {927, 153, 288, 519, 236, 411, 288, 311, 722};
//    Node nodes[9];
//    for (int i = 0; i < 9; i++) {
//        nodes[i].key = arr[i];
//        nodes[i].next = i + 1;
//    }
//    nodes[8].next = -1;
//
//    radixSortLink(nodes, 9, 3, 10);
//
//    for (int i = 0; i < 9; i++) {
//        std::cout << nodes[i].key << std::endl;
//    }
//}

//TEST(sort, indexSort) {
//    int arr[] = {29, 25, 34, 64, 34, 12, 32, 45};
//
//    indexSort(arr, 8);
//
//    for (int i = 0; i < 8; i++) {
//        std::cout << arr[i] << std::endl;
//    }
//}

TEST(sort, loserTree) {
    int arr[8][8] = {{10, 19, 26, 30, 42, 58, 65, 76},
                   {12, 20, 31, 44, 53, 67, 78, 88},
                   {15, 22, 34, 46, 59, 63, 70, 81},
                   {110, 291, 316, 420, 512, 618, 715, 816},
                   {1101, 2911, 3116, 4120, 5112, 6118, 7115, 8116},
                   {1110, 2191, 3116, 4120, 5112, 6118, 7115, 8116},
                   {1110, 2191, 3116, 4112, 5118, 6115, 7116, 32155},
                   {1110, 2191, 3116, 4120, 5512, 6118, 7115, 8116},};
    matrix m(arr, 8);
    //int arr[] = {3, 2, 9, 1, 4};

    loserTree<matrix> losertree(m, 8);

    losertree.init();
    int loc = losertree.remove();
    for(int i = 1;i < 64;i++){
        losertree.replay(loc);
        loc = losertree.remove();
    }
}

//TEST(sort, replaceSort) {
////    int arr[] = {10, 9, 6, 20, 12, 8, 15, 16};
////    int stream[] = {1,1,1,1,1,20, 221, 22, 26, 28, 1, 7, 12, 62, 7, 131, 5, 78, 523};
////    minHeap<int> mh(arr, 8, 8, stream, 19);
////    mh.replaceSort();
//}

int main(){
    std::cout<< RUN_ALL_TESTS();
//    int arr[] = {10, 9, 6, 20, 12, 8, 15, 16};
//    std::ifstream s;
//    s.open("E:\\code\\dataStructure\\Tree\\test.txt");
//    if(!s.is_open()){
//        exit(1);
//    }
//
//    minHeap<int> mh(arr, 8, 8, &s);
//    mh.replaceSort();
}