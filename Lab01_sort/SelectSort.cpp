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

        for(int i=0;i<n-1;i++){
            
            int index = i;
            
            for(int j=i+1;j<n;j++){
                countCmpOps++;
                if(a[index] > a[j]){
                    index = j;
                }
            }
            
            if(index != i){
                int im = a[index];
                a[index] = a[i];
                a[i] = im;
                countSwaps++;
            }
        }

        printf("%d %d\n", countCmpOps, countSwaps);

    }
    return 0;
}