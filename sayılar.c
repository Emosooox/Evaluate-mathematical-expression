#include <stdio.h>
#include <math.h>

int powah(int x,int p){
    if(p == 2){
        return x*x;
    }
    else if(p == 4){
        x = x*x;
        p = 2;
        x = powah(x,p);
        return x;
    }
    return 0;
}



int main(){
    printf("%d",powah(2,4));
    return 0;
}