#include<iostream>
using namespace std;

int factorial(int n){
    if(n <= 1)
        return 1;
    
    else{
        int im = n * factorial(n-1);
        while(im % 10 == 0) im/=10;

        return im%10000;
    }
}

int main(){

    int t, tc;
    
    scanf("%d", &tc);
    
    for(int t=0;t<tc;t++){
        int n;

        scanf("%d", &n);

        printf("%d\n", factorial(n)%1000);

    }
    return 0;
}