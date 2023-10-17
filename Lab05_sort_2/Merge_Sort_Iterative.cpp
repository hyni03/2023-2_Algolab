#include<iostream>
using namespace std;
int cnt;

void merge(int a[], int low, int mid, int high){
    int i,j,k;
    int tmp[101];

    for(int i=low; i<=high;i++)
        tmp[i] = a[i];

    i = k = low;
    j = mid + 1;

    while(i<=mid && j<=high){
        cnt++;
        if(tmp[i] <= tmp[j])
            a[k++] = tmp[i++];
        else a[k++] = tmp[j++];
    }

    while(i<=mid)
        a[k++] = tmp[i++];
    while(j<=high)
        a[k++] = tmp[j++];    
}

void mergeSortIterative(int v[], int n) {
    int size = 1;
    while (size < n){   
        for (int i = 0; i < n; i += 2 * size){
            int low = i;
            int mid = low + size - 1;
            int high = min(i + 2 * size - 1, n - 1);

            if(mid >= n-1)
                break;

            merge(v, low, mid, high);
        }
        size *= 2;
    }
}

int main(){
    int tc, n;
    scanf("%d", &tc);
    for(int t=0;t<tc;t++){
        int a[101];

        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        cnt=0;
        mergeSortIterative(a, n);
        printf("%d\n",cnt);
    }

    return 0;
}