//
// Created by lzk on 2019-09-22.
//

#include <iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
char* strcpy(char *a, char *b){
    char *c = a;
    a++;
    printf("%ld\n", a);
    return c;
}

int main(){
        char *a, *b;
        printf("%ld\n", a);
        printf("%ld\n%ld\n", strcpy(a,b), a);
}

