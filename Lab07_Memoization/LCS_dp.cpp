#include<bits/stdc++.h>
using namespace std;

char a[101], b[101];
int dp[101][101], S[101][101];

int LCS(char a[], char b[], int n, int m){
    int i, j;

    for(int i=0;i<=n;i++) dp[i][0] = 0;
    for(int i=0;i<=m;i++) dp[0][i] = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                S[i][j] = 0;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(dp[i][j] == dp[i][j-1])
                    S[i][j] = 1;
                else S[i][j] = 2;
            }
        }
    }

    return dp[n][m];
}

void PRINT(char a[], char b[], int n, int m){
    if(n==0 || m==0)
        return;

    if(S[n][m] == 0){
        PRINT(a, b, n-1, m-1);
        printf("%c", a[n-1]);
    }
    else if(S[n][m] == 1)
        PRINT(a, b, n, m-1);
    else if(S[n][m] == 2)
        PRINT(a, b, n-1, m);
}


int main(){
    int tc;

    scanf("%d", &tc);
    int i=0;
    for(int t=0;t<tc;t++){
        scanf("%s", a);
        scanf("%s", b);

        printf("%d ", LCS(a, b, strlen(a), strlen(b)));
        PRINT(a, b, strlen(a), strlen(b));
    }

    return 0;
}