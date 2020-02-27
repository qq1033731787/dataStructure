//
// Created by Administrator on 2020/2/22.
//

#include "string1.h"
#include <string1.h>
#include <iostream>
#include <gtest/gtest.h>
#include <string>

TEST(String,Cstring){
    char p[30] = {'h','e','l','l','o',' ','w','o','r','l','d','\0'};
    char p1[12] = {'h','e','l','l','o',' ','w','o','r','l','D','\0'};
    char p2[30] = {'h','e','l','l','o',' ','w','o','r','l','d','h','e','l','l','o',' ','w','o','r','l','D','\0'};
    ASSERT_EQ(11, Strlen(p));
    ASSERT_EQ(0, Strcmp(Strcpy(p1, p), p));
    p1[10] = 'D';
    ASSERT_EQ(0, Strcmp(Strcat(p, p1), p2));
    ASSERT_EQ('D', *strchr(p1, 'D'));
}

const int& test1(int& a){
    a  = 10;
    return a;
}

int main(){
//    RUN_ALL_TESTS();
//    const char* p = "abcdaabcab";
//    const char* p = "bcd?*";
//    const char* t = "aabcddabcababcdaabcababcdaabcabaa";
//    std::string P(p);
//    std::string T(t);
////    int* next = findNext(p);
////    for(int i = 0;i < 10;i++){
////        std::cout<< next[i];
////    }
////    std::cout << std::endl << KMPMatching(T, P, next);
////    delete[] next;
//    std::cout << Matching(T, P);
        int a ;
       std::cout << test1(a) << std::endl;
}