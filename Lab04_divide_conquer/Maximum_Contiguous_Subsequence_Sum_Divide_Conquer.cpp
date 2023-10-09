#include<iostream>
using namespace std;
int a[101];

int mcs(int left, int right){
    
    if(left == right)
        return a[left];

    int mid = (left + right) / 2;
    int start = -2147483648, end = -2147483648, sum = 0;

    for(int i=mid; i>=left; i--){
        sum += a[i];
        start = max(start, sum);
    }

    sum = 0;
    for(int i=mid+1; i<=right; i++){
        sum += a[i];
        end = max(end, sum);
    }

    int single = max(mcs(left, mid), mcs(mid+1, right));

    return max(start + end, single);
}


int main(){
    int testcase, n;
    scanf("%d", &testcase);
    for(int t=0;t<testcase;t++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d", &a[i]);
        }
        printf("%d\n", mcs(0, n-1));
    }
    return 0;
}