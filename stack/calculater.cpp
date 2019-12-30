//
// Created by lzk on 2019-08-22.
//

#include <stack>
#include <map>
#include <iostream>
#include <string>
#include "string.h"

std::string preToPost(std::string);
float calculate(std::string);

std::map<char, int> _privilige;
int main(){
    _privilige['('] = 3;
    _privilige['*'] = 2;
    _privilige['/'] = 2;
    _privilige['+'] = 1;
    _privilige['-'] = 1;
    _privilige[')'] = 0;
    std::string input = "(((1+2)*3/(1+2+3*4))*5+3)*9";
    //std::cout<< preToPost(input)<< std::endl;
    std::cout<< calculate(preToPost(input))<< std::endl;
}

std::string preToPost(std::string input){
    std::string ret;
    std::stack<char> _s;
    for(char c : input){
        if(c == '('){
            _s.push(c);
        } else if(c == ')'){
            while(!_s.empty() && _s.top() != '('){
                ret.push_back(_s.top());
                _s.pop();
            }
            if(_s.top() == '('){
                _s.pop();
            }
        } else if(c >= '0' && c <= '9'){
            ret.push_back(c);
        } else{
            while(!_s.empty() && _privilige[_s.top()] >= _privilige[c] && _s.top() != '('){
                ret.push_back(_s.top());
                _s.pop();
            }
            _s.push(c);
        }
    }
    while(!_s.empty()){
        ret.push_back(_s.top());
        _s.pop();
    }
    return ret;
}

float calculate(std::string post){
    std::cout<< post<< std::endl;
    std::stack<float> _s;
    for(char c : post){
        if(c >='0' && c <= '9'){
            _s.push(float(c)-48);
        } else{
            float n2 = _s.top();
            _s.pop();
            float n1 = _s.top();
            _s.pop();
            float ret;
            switch(c){
                case '+':
                    ret = n1 + n2;
                    break;
                case '-':
                    ret = n1 - n2;
                    break;
                case '*':
                    ret = n1 * n2;
                    std::cout<<n1 << "*"<< n2<< std::endl;
                    break;
                case '/':
                    ret = n1 / n2;
                    std::cout<<n1 << "/"<< n2<< std::endl;
                    break;
            }
            _s.push(ret);
        }
    }
    return _s.top();
}