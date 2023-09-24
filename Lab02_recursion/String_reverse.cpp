#include<iostream>
#include<string.h>
using namespace std;

char str[105];

int main(){

    int t, tc;

    scanf("%d",&tc);
    
    for(t=0;t<tc;t++){

        scanf("%s", str);

        for(int i=strlen(str)-1;i>=0;i--){
            printf("%c", str[i]);
        }
        printf("\n");
    }
    return 0;
}