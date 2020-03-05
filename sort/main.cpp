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

TEST(sort, indexSort) {
    int arr[] = {29, 25, 34, 64, 34, 12, 32, 45};

    indexSort(arr, 8);

    for (int i = 0; i < 8; i++) {
        std::cout << arr[i] << std::endl;
    }
}

int main(){
    std::cout<< RUN_ALL_TESTS();
}