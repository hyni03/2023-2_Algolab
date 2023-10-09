#include<iostream>
using namespace std;
int a[101];

int main(){
    int testcase, n;
    scanf("%d", &testcase);
    for(int t=0;t<testcase;t++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d", &a[i]);
        }
        int i, j, start, end;
        int maxSum=0, thisSum = 0;
        start = end = -1;
        for(i=0, j=0; j<n;j++){
            thisSum += a[j];
            if(thisSum > maxSum){
                maxSum = thisSum;
                start = i;
                end = j;
            }
            else if(thisSum <= 0){
                i = j+1;
                thisSum =0;
            }
        }
        printf("%d %d %d\n", maxSum, start, end);
    }
    return 0;
}