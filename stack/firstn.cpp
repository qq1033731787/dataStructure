#include<iostream>
#include<cmath>

float firstn(int n){
    if(n == 1){
        return 1;
    }else{
        return firstn(n - 1) + (pow(-1, n) / static_cast<float>(n)); 
    }
}

int main(){
    std::cout << firstn(3)  << std::endl;
}
