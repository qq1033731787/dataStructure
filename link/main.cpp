#include <stdio.h>
#include "link/Link.h"

int main(){
    int a[5] = {1,2,3,4,5};
    deleteEle(a, 0, 5);
    for(int i=0; i<4; i++){
        printf("%d\n", a[i]);
    }
}



