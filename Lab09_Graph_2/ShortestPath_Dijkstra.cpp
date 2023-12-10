#include<bits/stdc++.h>
using namespace std;
int d[1001], ans[1001];
bool ck[1001];
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
            }
        }

        for(int i=1;i<=n;i++){
            d[i] = INT_MAX;
            ck[i] = false;
            ans[i] = 0;
        }

        d[1] = 0;
        for(int i=0;i<vec[1].size();i++){
            d[vec[1][i].first] = vec[1][i].second;
            ans[vec[1][i].first] = vec[1][i].second;
        }

        ck[1] = true;
        for(int i=0;i<n;i++){

            int im = -1;
            for(int j=1;j<=n;j++){
                if(!ck[j] && (im==-1 || d[j] < d[im]))
                    im = j;
            }

            if(im == -1) break;
            ck[im] = true;

            for(int k=0;k<vec[im].size();k++){
                if(d[vec[im][k].first] > d[im] + vec[im][k].second){
                    d[vec[im][k].first] = d[im] + vec[im][k].second;
                    ans[vec[im][k].first] = vec[im][k].second;
                }
            }
        }

        int sum = 0;
        for(int i=1;i<=n;i++){
            sum += ans[i];
        }
        printf("%d\n", sum);
    }
    return 0;
}
