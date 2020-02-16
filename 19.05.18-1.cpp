#include <bits/stdc++.h>
using namespace std;
int main(){
	unsigned short n,i,j,k;
	cin>>n;
	for(i=1;i<=3;i++){
		for(j=i+1;j<=4;j++){
			for(k=j+1;k<=5;k++)printf("%d %d %d\n",i,j,k);
		}
	}	
	return 0;
}
