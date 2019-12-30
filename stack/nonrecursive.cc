#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int w[5] = {4,6,1,4,6};

struct Node{
    int rd;
    bool k;
    int s, n;
}tmp,x;


bool cur(int s,int n){
    if(s==0){
        return true;    
    }
    if(s<0 || n<1){
        return false;
    }
    if(cur(s-w[n-1], n-1)){
        cout<<w[n-1]<<endl;
        return true;
    }
    else return cur(s, n-1);
} 

bool nocur(int s, int n){
    stack<Node> _s = stack<Node>();
    tmp.rd=0;
    tmp.s = s;
    tmp.n = n;
    _s.push(tmp);
label0:
    //cout<<"LABEL 0"<<endl;
    tmp = _s.top();
    if(tmp.s==0){
        tmp.k = true;
        //cout<<"TRUE"<<endl;
        _s.pop();
        _s.push(tmp);
        goto label3;
    }
    if(tmp.s<0 || tmp.n<1){
        tmp.k = false;
        _s.pop();
        _s.push(tmp);
        goto label3;
    }

    tmp.rd = 1;
    tmp.s = tmp.s - w[tmp.n-1];
    tmp.n = tmp.n -1; 
    _s.push(tmp);
    goto label0;

label1:
    //cout<<"LABEL 1"<<endl;
    if(tmp.k==true){
        x = _s.top();
        cout<<w[x.n-1]<<endl;
        x.k = true;
        _s.pop();
        _s.push(x);
        goto label3;
    }else{
        tmp.s = tmp.s;
        tmp.n = tmp.n -1 ;
        tmp.rd = 2;
        _s.push(tmp);
        goto label0;
    }
label2:
    //cout<<"LABEL 2"<<endl;
    if(tmp.k==true){
        x = _s.top();
        x.k = true;
        _s.pop();
        _s.push(x);
        goto label0;
    }    


label3:
    //cout<<"LABEL 3"<<endl;
    tmp = _s.top();
    _s.pop();
    switch(tmp.rd){
        case 0: return tmp.k;
        case 1: goto label1;
        case 2: goto label2;
    }

}

int main(){
    cout.setf(ios_base::boolalpha);
    cout<<nocur(11, 3)<<endl;
}
