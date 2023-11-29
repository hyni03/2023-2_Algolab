#include<bits/stdc++.h>
using namespace std;

int n, cnt;
bool visited[1001];

void Stack(int v, int d[][1001]) {
    stack<int> s;
    s.push(v);
    visited[v] = true;
    cnt = 1;

    while (!s.empty()) {
        int t = s.top();
        s.pop();

        for (int i = 1; i <= n; i++) {
            if (d[t][i] == 1 && !visited[i]) {
                s.push(i);
                visited[i] = true;
                cnt++;
            }
        }
    }
}

int main() {
    int tc, k, m, v;

    scanf("%d", &tc);
    for (int t = 0; t < tc; t++) {
        scanf("%d", &n);
        memset(visited, false, sizeof(visited));

        int d[1001][1001] = {0};
        vector<int> vec;

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &k, &m);
            for (int j = 0; j < m; j++) {
                scanf("%d", &v);
                d[k][v] = 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                Stack(i, d);
                vec.push_back(cnt);
            }
        }

        sort(vec.begin(), vec.end());
        printf("%d ", (int)vec.size());
        for(int i=0; i < vec.size(); i++) {
            printf("%d ", vec[i]);
        }
        printf("\n");
    }
    return 0;
}
