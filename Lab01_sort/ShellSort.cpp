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

        int gap = n/2; 

        while(gap > 0){
            for(int i=gap;i<n;i++){
                for(int j=i;j>=gap;j-=gap){
                    countCmpOps++;
                    if(a[j-gap] > a[j]){ 
                        int im = a[j];
                        a[j] = a[j-gap];
                        a[j-gap] = im;
                        countSwaps++;
                    }
                    else break;
                }
            }
            gap /= 2;

        }

        printf("%d %d\n", countCmpOps, countSwaps);

    }
    return 0;
}