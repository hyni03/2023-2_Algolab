#include<iostream>
using namespace std;

int gcd(int a, int b){

    if (b==0)
        return a;
    
    else return gcd(b, a%b);

}

int main(){

    int t, tc;
    
    scanf("%d", &tc);
    
    for(int t=0;t<tc;t++){
        int a, b;

        scanf("%d %d", &a, &b);

        printf("%d\n", gcd(a, b));

    }
    return 0;
}