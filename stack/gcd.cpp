#include<iostream>

int gcd(int m, int n){
    if(m >= n && m % n == 0){
        return n;
    }
    if(m < n){
        return gcd(n, m);
    }
    return gcd(n, m % n);
}

int main(){
    std::cout << gcd(25, 10) << std::endl;
}
