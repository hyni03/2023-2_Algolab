#include<bits/stdc++.h>
using namespace std;
bool ck[1001];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    int tc, k, n, m, v, a;

    scanf("%d", &tc);
    for (int t = 0; t < tc; t++) {
        scanf("%d", &n);

        vector< pair<int,int> > vec[1001];
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &k, &m);
            for (int j = 0; j < m; j++) {
                scanf("%d %d", &v, &a);
                vec[k].push_back({v,a});
                vec[v].push_back({k,a});
            }
        }

        for(int i=1;i<=n;i++)
            ck[i] = false;

        for(int i=0;i<vec[1].size();i++){
            pq.push({vec[1][i].second, vec[1][i].first});
        }

        ck[1] = true;
        int sum = 0;
        while (!pq.empty()) {
            int w = pq.top().first;
            int v = pq.top().second;
            pq.pop();

            if (ck[v]) continue;

            sum += w;
            ck[v] = true;

            for (int i = 0; i < vec[v].size(); i++) {
                if (!ck[vec[v][i].first]) {
                    pq.push({vec[v][i].second, vec[v][i].first});
                }
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
