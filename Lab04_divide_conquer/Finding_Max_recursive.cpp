#include<iostream>
using namespace std;
int a[101];

int find_max(int left, int right){

    if(left == right)
        return a[left];

    int half = (left + right) / 2;
    return max(find_max(left, half), find_max(half+1, right));
}

int main(){
    int testcase, n;
    scanf("%d", &testcase);
    for(int t=0;t<testcase;t++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d", &a[i]);
        }
        printf("%d\n",find_max(0, n-1));
    }
    return 0;
}