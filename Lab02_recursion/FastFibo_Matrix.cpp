#include<iostream>
using namespace std;

void Matrix_Mul(int A[2][2], int B[2][2]){

    int result[2][2] = {0};

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                result[i][j] += A[i][k] * B[k][j];
            }
            result[i][j] = result[i][j]%1000;
        }
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            A[i][j] = result[i][j];
        }
    }

}

int FastFibo(int n){

    if(n<=1)
        return n;

    int Base[2][2] = {{1, 0}, {0, 1}};
    int A[2][2] = {{1, 1}, {1, 0}};

    while(n > 0){
        if (n%2)
            Matrix_Mul(Base, A);
        Matrix_Mul(A, A);
        n = n/2;
    }

    return Base[0][1];
}

int main(){

    int tc;
    
    scanf("%d", &tc);
    
    for(int t=0;t<tc;t++){

        int n;

        scanf("%d", &n);

        printf("%d\n", FastFibo(n));

    }
    return 0;
}