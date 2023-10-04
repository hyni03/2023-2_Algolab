#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char str[10];
int cnt;

void permute(char *str, int begin, int end){

    int range = end - begin;

    if(range == 1){
        int sum = 0;

        for(int i=0;i<strlen(str);i++){
            if(i%2==0)
                sum += str[i] - 97;
            else sum -= str[i] - 97;
        }
        
        if(sum > 0)
            cnt++;
    }

    else {
        for(int i=0; i<range; i++){
            swap(str[begin], str[begin+i]);
            permute(str, begin+1, end);
            swap(str[begin], str[begin+i]);
        }
    }

}

int main(){
    int tc;
    
    scanf("%d", &tc);

    for(int t=0;t<tc;t++){
        scanf("%s", str);
        
        cnt = 0;
        permute(str, 0, strlen(str));
        printf("%d\n",cnt);

    }
    return 0;
}