#include<stdio.h>

int FastPower(int x, int n){

    int y;

    if(n==0)
        return 1;

    else if(n%2==1){
        y = FastPower(x, (n-1)/2);
        return (x * y * y)%1000;
    }

    else { 
        y = FastPower(x, n/2);
        return (x*FastPower(x,n-1))%1000;
    }
}

int main(){

    int t, tc;
    
    scanf("%d", &tc);
    
    for(int t=0;t<tc;t++){

        int x, n;

        scanf("%d %d", &x, &n);

        printf("%d\n", FastPower(x, n));

    }
    return 0;
}