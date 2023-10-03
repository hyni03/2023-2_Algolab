#include<iostream>
#include<algorithm>
using namespace std;
string str;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int tc;
    cin>>tc;
    for(int t=0;t<tc;t++){
        cin>>str;
        int cnt = 0;
        do {
            int sum = 0;
            for(int i=0;i<str.size();i++){
                (i%2==0)? sum +=str[i]-97 : sum -= str[i]-97;
            }
            if(sum > 0) cnt++;
        } while(next_permutation(str.begin(),str.end()));
        printf("%d\n", cnt);
    }
    return 0;
}