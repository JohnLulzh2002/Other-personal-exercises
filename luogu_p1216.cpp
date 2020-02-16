#include<bits/stdc++.h>
using namespace std;
short a[100][100],n;
unsigned short go(short i,short j){
	unsigned short l,r;
	if(i==n-1)	return a[i][j];
	else{
		l=go(i+1,j);
		r=go(i+1,j+1);
		return (l<r)?(l+a[i][j]):(r+a[i][j]);
	}
}
int main(){
	short i,j;
	cin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<=i;j++)
			cin>>a[i][j];
	cout<<go(0,0);
	return 0;
}
