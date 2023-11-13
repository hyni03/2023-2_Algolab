#include<iostream>
#include<cstring>
using namespace std;
char a[10], b[10];

int LCS(char a[], char b[], int n, int m){
    if (m == 0 || n == 0)
        return 0;
    
    if (a[n-1] == b[m-1])
        return LCS(a, b, n-1, m-1) + 1;

    return max(LCS(a, b, n, m-1), LCS(a, b, n-1, m));
}


int main(){
    int tc, n;

    scanf("%d", &tc);
    int i=0;
    for(int t=0;t<tc;t++){
        scanf("%s", a);
        scanf("%s", b);
        
        printf("%d\n",LCS(a, b, strlen(a), strlen(b)));
    }

    return 0;
}