#include <bits/stdc++.h>
using namespace std;
unsigned short n,r,a[100];
void f(unsigned short j){
	unsigned short i;
	if(j>r){
		for(i=1;i<=r;i++)	printf("%d",a[i]);
		printf("\n");
	}
	else{
		for(i=a[j-1]+1;i<=n-r+j;i++){
			a[j]=i;
			f(j+1);
		}
	}
}
int main(){
	cin>>n>>r;
	f(1);
	return 0;
}
