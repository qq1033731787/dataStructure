//
// Created by Administrator on 2020/2/12.
//
#include <gtest/gtest.h>
#include "Link.h"
#include "stack.h"

TEST(LinkTest, TestarrList) {
    auto alist = new arrList<int>(2);
    ASSERT_TRUE(alist->append(1));
    ASSERT_TRUE(alist->insert(0,100));
    ASSERT_FALSE(alist->append(2));
    ASSERT_FALSE(alist->insert(0, 1000));
    int p;
    ASSERT_TRUE(alist->getPos(p, 100));
    ASSERT_EQ(0, p);
}

TEST(StackTest, TestarrStack){
    auto as = new arrStack<int>();
    ASSERT_TRUE(as->isEmpty());
    ASSERT_TRUE(as->push(3));
    int a;
    ASSERT_TRUE(as->Top(a));
    ASSERT_EQ(3, a);
    a = 0;
    ASSERT_TRUE(as->pop(a));
    ASSERT_EQ(3, a);
    ASSERT_TRUE(as->isEmpty());
    ASSERT_TRUE(as->push(3));
    ASSERT_TRUE(as->push(2));
    ASSERT_TRUE(as->isFull());
    ASSERT_TRUE(as->push(1));
    ASSERT_TRUE(as->pop(a));
    ASSERT_EQ(1, a);
    ASSERT_TRUE(as->pop(a));
    ASSERT_EQ(2, a);
    ASSERT_TRUE(as->pop(a));
    ASSERT_EQ(3, a);
    ASSERT_TRUE(as->isEmpty());
}

TEST(StackTest, TestlnkStack){
    auto ls = new lnkStack<int>();
    ASSERT_TRUE(ls->isEmpty());
    ASSERT_TRUE(ls->push(3));
    int a;
    ASSERT_TRUE(ls->Top(a));
    ASSERT_EQ(3, a);
    a = 0;
    ASSERT_TRUE(ls->pop(a));
    ASSERT_EQ(3, a);
    ASSERT_TRUE(ls->isEmpty());
    ASSERT_TRUE(ls->push(3));
    ASSERT_TRUE(ls->push(2));
    ASSERT_FALSE(ls->isFull());
    ASSERT_TRUE(ls->push(1));
    ASSERT_TRUE(ls->pop(a));
    ASSERT_EQ(1, a);
    ASSERT_TRUE(ls->pop(a));
    ASSERT_EQ(2, a);
    ASSERT_TRUE(ls->pop(a));
    ASSERT_EQ(3, a);
    ASSERT_TRUE(ls->isEmpty());
}
