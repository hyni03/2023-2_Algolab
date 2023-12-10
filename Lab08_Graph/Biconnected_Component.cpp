#include<bits/stdc++.h>
using namespace std;

vector<int> v[101];

bool t[101]; // 단절점 파악
int d[101]; // dfs 순서 
int c, bcc_cnt;

int f(int x, bool k, int parent) {
    d[x] = ++c;
    int r = d[x]; // x의 자식 노드가 x를 거치지 않고 도달할 수 있는 정점 중 dfs 함수가 방문한 정점
    int ch = 0; // 자식 수

    for (int i = 0; i < v[x].size(); i++) {
        int next = v[x][i];

        if (!d[next]) {
            ch++;
            int low = f(next, false, x);
            r = min(r, low);
            if (low >= d[x]) {
                if(!k) t[x] = true;

                bcc_cnt++;
            }
        } else if (next != parent && d[next] < d[x]) {
            r = min(r, d[next]);
        }
    }

    // 루트 노드일 때 자식 수가 2개 이상이면 단절점
    if (parent == -1 && ch >= 2)
        t[x] = true;

    return r;
}

int main() {
    int tc, n, m, a, b, cnt = 0;
    scanf("%d", &tc);
    for(int l=0;l<tc;l++){
        scanf("%d", &n);

        for(int i=1;i<=n;i++){
            v[i].clear();
            t[i] = d[i] = 0;
        }

        c = bcc_cnt = cnt = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a, &m);
            for(int j=0;j<m;j++){
                scanf("%d", &b);
                v[a].push_back(b);
                v[b].push_back(a);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!d[i])
                f(i, true, -1);
        }

        for (int i = 1; i <= n; i++) {
            if (t[i])
                cnt++;
        }

        printf("%d\n%d ", bcc_cnt, cnt);
        for (int i = 1; i <= n; i++) {
            if (t[i])
                printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}
