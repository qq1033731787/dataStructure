//
// Created by lzk on 2019-12-17.
//

#include <stack>
#include <iostream>
#include <queue>

void reverse1(std::stack<int>& stack){
    int tmp;
    std::stack<int> a, b;
    while(!stack.empty()){
        tmp = stack.top();
        stack.pop();
        a.push(tmp);
    }
    while(!a.empty()){
        tmp = a.top();
        a.pop();
        b.push(tmp);
    }
    while(!b.empty()){
        tmp = b.top();
        std::cout << tmp << std::endl;
        b.pop();
        stack.push(tmp);
    }
}

void reverse2(std::stack<int>& stack){
    int tmp;
    std::queue<int> a;
    while(!stack.empty()){
        tmp = stack.top();
        stack.pop();
        a.push(tmp);
    }
    while(!a.empty()){
        tmp = a.front();
        a.pop();
        stack.push(tmp);
    }
}

void reverse3(std::stack<int>& stack){
    int tmp;
    std::stack<int> a;
    int curSize = 0;
    int size = stack.size();
    int needPop;
    bool first;
    while(curSize < size){
        tmp = stack.top();
        needPop = size - curSize;
        first = true;
        while(needPop){
            if (!first) {
                a.push(stack.top());
            }
            first = false;
            stack.pop();
            needPop--;
        }
        stack.push(tmp);
        while(!a.empty()){
            stack.push(a.top());
            a.pop();
        }
        curSize++;
    }
}

int main(){
    std::stack<int> _s;
    _s.push(3);
    _s.push(2);
    _s.push(100);
    reverse3(_s);
    int tmp;
    while(!_s.empty()){
        tmp = _s.top();
        _s.pop();
        std::cout << tmp << std::endl;
    }
}