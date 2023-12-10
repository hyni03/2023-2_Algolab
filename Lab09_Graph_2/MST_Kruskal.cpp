#include<bits/stdc++.h>
using namespace std;

bool ck[1001];

bool cmp(const pair<int, pair<int,int> > &p, const pair<int, pair<int,int> > &q){
    if(p.first == q.first)
        return p.second.first < q.second.first;
    return p.first < q.first;
}

struct UnionFind {
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int findSet(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = findSet(parent[x]);
    }

    void unionSets(int x, int y) {
        int rootX = findSet(x);
        int rootY = findSet(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY])
                swap(rootX, rootY);

            parent[rootY] = rootX;

            if (rank[rootX] == rank[rootY])
                rank[rootX]++;
        }
    }
};

int main() {
    int tc, k, n, m, v, a;

    scanf("%d", &tc);
    for (int t = 0; t < tc; t++) {
        scanf("%d", &n);

        vector< pair<int, pair<int,int> > > vec;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &k, &m);
            for (int j = 0; j < m; j++) {
                scanf("%d %d", &v, &a);
                vec.push_back({a,{v,k}});
            }
        }

        sort(vec.begin(), vec.end(), cmp);
        
        UnionFind uf(n + 1); // n 개의 정점이 있을 때, 1부터 n까지의 정점 사용

        int sum = 0;
        for (int i = 0; i < vec.size(); i++) {
            int weight = vec[i].first;
            int u = vec[i].second.first;
            int v = vec[i].second.second;

            if (uf.findSet(u) != uf.findSet(v)) {
                sum += weight;
                uf.unionSets(u, v);
            }
        }


        printf("%d\n", sum);
    }

    return 0;
}
