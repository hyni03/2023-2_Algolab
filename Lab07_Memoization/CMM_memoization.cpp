#include <bits/stdc++.h>
using namespace std;
int p[101], memo[101][101];

int minMultiplications(int p[101], int i, int j) {
    if (i == j)
        return 0;

    if (memo[i][j] != -1)
        return memo[i][j];

    int minCost = INT_MAX;

    for (int k = i; k < j; k++) 
        minCost = min(minMultiplications(p, i, k) + minMultiplications(p, k + 1, j) + p[i] * p[k+1] * p[j+1], minCost);

    memo[i][j] = minCost;

    return minCost;
}

int main() {

    int tc, n, i;
    scanf("%d", &tc);
    for(int t=0;t<tc;t++){
        scanf("%d", &n);
        for(i=0;i<=n;i++){
            scanf("%d",&p[i]);
        }

        memset(memo, -1, sizeof(memo));
        printf("%d\n", minMultiplications(p, 0, n-1));
    }

    return 0;
}
