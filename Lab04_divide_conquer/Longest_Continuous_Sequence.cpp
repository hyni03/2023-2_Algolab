#include<iostream>
using namespace std;
int arr[1001];

int LCS(int n){
    int length = 1;
    int i=0,j=0;
    
    while(i<n){
        for(j=i; arr[i] <= arr[j] && j<n;j++);
        length = max(length, j-i);
        i = j;
    }

    return length;
}

int main(){
    int testcase, n;
    scanf("%d", &testcase);
    for(int t=0;t<testcase;t++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        printf("%d\n", LCS(n));
    }
    return 0;
}
