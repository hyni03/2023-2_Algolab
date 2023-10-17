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

void mergeSort(int a[], int low, int high){
    int mid;

    if(low == high)
        return ;
    
    mid = (low+high)/2;

    mergeSort(a, low, mid);
    mergeSort(a, mid+1, high);
    merge(a, low, mid, high);
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
        mergeSort(a, 0, n-1);
        printf("%d\n",cnt);
    }

    return 0;
}