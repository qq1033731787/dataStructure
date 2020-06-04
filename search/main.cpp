//
// Created by Administrator on 2020/3/13.
//
#include <gtest/gtest.h>
#include <search.h>
//
//TEST(search, bin){
//    int a[] = {1 ,2, 3};
//    int ret = binSearch(a, 1, 1);
//    ASSERT_EQ(ret, 0);
//    ret = binSearch(a, 2, 2);
//    ASSERT_EQ(ret, 1);
//    ret = binSearch(a, 3, 3);
//    ASSERT_EQ(ret, 2);
//}


TEST(search, mySet){
    mySet<26> ms1, ms2;

    ms1.Set('a').Set('b').Set('c').Set('d').Set('e').Set('f').Set('g');
    ms2.Set('a').Set('b').Set('c').Set('d').Set('e').Set('f').Set('g').Set('z').Set('h');
    //ms1.print();
//    ms2.print();
    ASSERT_EQ(true, ms1 < ms2);
    ASSERT_EQ(true, ms1 <= ms2);
    ASSERT_EQ(true, ms2 > ms1);
    ASSERT_EQ(false, ms1 > ms2);
    ASSERT_EQ(true, (ms1 & ms2) == ms1);
    ASSERT_EQ(true, (ms1 | ms2) == ms2);
    ASSERT_EQ(true, (ms1 ^ ms2) == (ms2 - ms1));
    (ms2 - ms1).print();


}

int main(){
    RUN_ALL_TESTS();
}