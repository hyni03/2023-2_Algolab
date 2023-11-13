#include<iostream>
#include<cstring>
using namespace std;

char a[101], b[101];
int memo[101][101];

int LCS(char a[], char b[], int n, int m){
        if(n==0 || m==0) 
            return 0;

        if(memo[n][m] != -1) 
            return memo[n][m];

        if(a[n-1] == b[m-1]) 
            memo[n][m] = LCS(a, b, n-1, m-1) + 1;

        else memo[n][m] = max(LCS(a, b, n-1, m), LCS(a, b, n, m-1));

        return memo[n][m];
}


int main(){
    int tc;

    scanf("%d", &tc);
    int i=0;
    for(int t=0;t<tc;t++){
        scanf("%s", a);
        scanf("%s", b);
        memset(memo, -1, sizeof(memo));
        printf("%d\n",LCS(a, b, strlen(a), strlen(b)));
    }

    return 0;
}