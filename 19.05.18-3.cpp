#include <bits/stdc++.h>
using namespace std;
unsigned short a[100];
void f(unsigned short n,unsigned short r,unsigned short m){
	//n:numbers remain
	//r:unchoosed numbers remain
	//m:choosed numbers
	if(r==0){
		for(unsigned short i=0;i<m;i++)
			printf("%d",a[i]);
		printf("\n");
	}
	else{
		if(n==0) return;
		else{
			a[m]=n;
			f(n-1,r-1,m+1);	//choose
			f(n-1,r,m);	//not choose
		}
	}
}
int main(){
	unsigned short n,r;
	cin>>n>>r;
	f(n,r,0);
	return 0;
}
