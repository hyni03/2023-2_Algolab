#include<iostream>
using namespace std;
int a[101];

int binary_search(int k, int left, int right){
    if(left > right)
        return -1;

    int mid = (left + right) / 2;
    if(a[mid] == k)
        return mid;
    if(a[mid] > k)
        return binary_search(k, left, mid-1);
    else
        return binary_search(k, mid+1, right);
}

int main(){
    int testcase, n, k;
    scanf("%d", &testcase);
    for(int t=0;t<testcase;t++){
        scanf("%d %d",&n, &k);
        for(int i=0;i<n;i++){
            scanf("%d", &a[i]);
        }
        printf("%d\n",binary_search(k, 0, n-1));
    }
    return 0;
}