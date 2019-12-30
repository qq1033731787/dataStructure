//
// Created by lzk on 2019-12-19.
//

#include <stack>
#include <iostream>
#include <map>

std::string toPost(std::string in){
    std::map<char, int> _privOut{
            {')', -1},
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2},
            {'(', 3}
    };

    std::map<char, int> _privIn{
            {'(', 0},
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2},
            {')', 3}
    };

    std::string ret;
    std::stack<char> sym;
    for(auto c : in){

        if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')){
            ret += c;
            continue;
        }else{
            while(!sym.empty() && _privOut[c] <= _privIn[sym.top()]){
                if(sym.top() != '(' && sym.top() != ')'){
                    ret += sym.top();
                }
                sym.pop();
            }
            if(c != ')'){
                sym.push(c);
            }
        }
    }
    while(!sym.empty()){
        ret += sym.top();
        sym.pop();
    }
    return ret;
}

int main(){
    std::string t = "a*(b*c-d)+e";
    std::cout << toPost(t) << std::endl;
}