//
// Created by lzk on 2019-12-01.
//

#include <stack>
#include <iostream>
#include <stdlib.h>

int weight[5] = {1, 3, 5, 6, 8};

bool cursive(int s, int index){
    //std::cout<<index<<"!";
    if(s == 0){
        return true;
    }
    if(s < 0 || index >= (sizeof(weight) / sizeof(int))){
        return false;
    }
    if(cursive(s - weight[index], index + 1)){
        std::cout << weight[index] << "\n";
        return true;
    }else{
        return cursive(s, index + 1);
    }
}

struct node{
    int s, n, ra;
    bool ret = false;
}_old, _new;

std::stack<node> sk;

bool nocursive(int s){
    _new.s = s;
    _new.n = 0;
    _new.ra = 0;
    _new.ret = false;
    sk.push(_new);
label0:
//    std::cout<<"label0"<<std::endl;
    _old = sk.top();
    sk.pop();
    if(_old.s == 0){
        _old.ret = true;
        sk.push(_old);
        goto label3;
    }
    if(_old.s < 0 || _old.n >= (sizeof(weight) / sizeof(int))){
        _old.ret = false;
        sk.push(_old);
        goto label3;
    }
    sk.push(_old);
    _new.s = _old.s - weight[_old.n];
    _new.n = _old.n + 1;
    _new.ra = 1;
    sk.push(_new);
    goto label0;
label1:
//    std::cout<<"label1"<<std::endl;
    if(_old.ret){
        _old = sk.top();
        sk.pop();
        std::cout << weight[_old.n] << "_" << std::endl;
        _old.ret = true;
        sk.push(_old);
        goto label3;
    }else{
        _new.s = _old.s + weight[_old.n - 1];
        _new.n = _old.n;
        _new.ra = 2;
        sk.push(_new);
        goto label0;
    }
label2:
//    std::cout<<"label2"<<std::endl;
    if(_old.ret){
        _old = sk.top();
        sk.pop();
        _old.ret = true;
        sk.push(_old);
        goto label3;
    }else{
        _old = sk.top();
        sk.pop();
        _old.ret = false;
        sk.push(_old);
        goto label3;
    }
label3:
//    std::cout<<"label3"<<std::endl;
    _old = sk.top();
    sk.pop();
    switch(_old.ra){
        case 0:return _old.ret;
        case 1:goto label1;
        case 2:goto label2;
    }
}

bool nocursiveSimple(int s){
    _new.s = s;
    _new.n = 0;
    _new.ra = 0;
    int n0 = sizeof(weight) / sizeof(int);
    bool K = false;
    sk.push(_new);
    while(!sk.empty()){
        _old = sk.top();
        while(_old.s == 0 || (_old.s > 0 && _old.n < n0)){
            if(_old.s == 0){
                K = true;
                break;
            }else{
                _new.s = _old.s - weight[_old.n];
                _new.n = _old.n + 1;
                _new.ra = 1;
                sk.push(_new);
            }
            _old = sk.top();
        }

        while(!sk.empty()){
            _old = sk.top();
            sk.pop();
            if(_old.ra == 0){
                return K;
            }else if(_old.ra == 1){
                if(K){
                    std::cout << weight[_old.n - 1] << "_" << std::endl;
                }else{
                    _new.s = _old.s + weight[_old.n - 1];
                    _new.n = _old.n;
                    _new.ra = 2;
                    sk.push(_new);
                    break;
                }
            }
        }
    }
}


int main(int argc, char** argv){
    bool ret = false;
    for(int i = 0; i < 130; i++){
        std::cout << "NUM:" << i << std::endl;
        std::cout << std::boolalpha << nocursive(i) << std::endl;
        std::cout << std::boolalpha << nocursiveSimple(i) << std::endl << std::endl << std::endl << std::endl;
        if(nocursive(i) != nocursiveSimple(i)){
            std::cout << "FALSE!!!!!!!!!!" << std::endl;
            return 0;
        }
    }
    std::cout << "SUCCESS" << std::endl;
    return 0;
}