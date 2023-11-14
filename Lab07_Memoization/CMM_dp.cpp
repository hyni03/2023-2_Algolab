#include <bits/stdc++.h>
using namespace std;
int p[101], dp[101][101], m[101][101];

int minMultiplications(int p[101], int n) {
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    for (int len = 1; len < n; len++) {
        for (int i = 1; i <= n - len; i++) {
            int j = i + len;
            
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    m[i][j] = k;
                }
            }
        }
    }
    return dp[1][n];
}

void order(int i, int j) {
    if (i == j)
        cout << "M" << i;
    else {
        cout << "(";
        order(i, m[i][j]);
        order(m[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    int tc, n;

    cin >> tc;

    for (int t = 0; t < tc; t++) {
        cin >> n;
        for (int i = 0; i <= n; i++) {
            cin >> p[i];
        }

        int cost = minMultiplications(p, n);
        order(1, n);
        printf("\n%d\n", cost);
    }

    return 0;
}
