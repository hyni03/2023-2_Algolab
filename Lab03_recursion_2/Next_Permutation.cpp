/// 2 ms    1064 MB     665 Byte

#include<iostream>
#include<algorithm>
using namespace std;

void FindNextPermutation(int n, char str[]){
    int i = n-2;

    while(i >= 0 && str[i] >= str[i+1]){
        i = i-1;
    }

    if (i==-1){
        reverse(str, str+n);
        printf("%s\n", str);
        return ;
    }
    
    int j = n-1;

    while( str[i] > str[j]){
        j = j-1;
    }

    swap(str[i], str[j]);
    reverse(str+i+1, str+n);

    printf("%s\n",str);
    return ;
}

int main(){
    int tc, n;
    char str[27];

    scanf("%d ",&tc);

    for(int t=0;t<tc;t++){
        scanf("%d", &n);
        scanf("%s", str);

        FindNextPermutation(n, str);
    }

    return 0;
}