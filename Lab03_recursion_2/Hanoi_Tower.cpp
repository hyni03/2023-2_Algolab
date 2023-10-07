#include<iostream>
using namespace std;

unsigned long long int count(int k, unsigned long long int n){

	unsigned long long int p;

	if(n==0)
		return 1;
	
	if(n%2==0){
		p = count(k, n/2);
		return p * p;
	}

	p = count(k, (n-1)/2);
	return k*p*p;
}

void Hanoi_Tower(int n, unsigned long long int k, int a, int b, int c){

	if(n==1){
		printf("%d %d\n", a, c);
		return ;
	}

	unsigned long long int im = count(2, n-1);

	if(k==im){
		printf("%d %d\n", a, c);
		return ;
	}
	
	if(k>im)
		Hanoi_Tower(n-1, k-im, b, a, c);

	else if(k<im)
		Hanoi_Tower(n-1, k, a, c, b);
}

int main(){
	
	int tc;
	unsigned long long int n, k;
	scanf("%d ",&tc);
	for(int t=0;t<tc;t++){
		scanf("%llu %llu", &n, &k);
		Hanoi_Tower(n, k, 1, 2, 3);
	}
	return 0;
}