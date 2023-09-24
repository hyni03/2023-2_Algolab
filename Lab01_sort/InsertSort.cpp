#include<stdio.h>
using namespace std;
int a[10005];
int main(){
    int t,tc,n;
    scanf("%d",&tc);

    for(int t=0;t<tc;t++){

        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }

        int countCmpOps = 0;  // 비교 연산자 실행 횟수     
        int countSwaps = 0;   // swap 함수 실행 횟수     

        for(int i=1;i<n;i++){
            for(int j=i;j>0;j--){
                countCmpOps++;
                if(a[j-1] > a[j]){
                    int im = a[j];
                    a[j] = a[j-1];
                    a[j-1] = im;
                    countSwaps++;
                }
                else break;
            }
        }

        printf("%d %d\n", countCmpOps, countSwaps);

    }
    return 0;
}