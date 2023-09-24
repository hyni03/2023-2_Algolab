#include<stdio.h>

int fibo(int n){

    if(n<=1)
        return n;

    else return fibo(n-1) + fibo(n-2);
}

int main(){

    int t, tc;
    
    scanf("%d", &tc);
    
    for(int t=0;t<tc;t++){

        int n;

        scanf("%d", &n);

        printf("%d\n", fibo(n));

    }
    return 0;
}