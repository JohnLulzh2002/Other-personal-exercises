#include<iostream>
#include<cstdio> 
using namespace std;
int stair(int n){
	switch(n){
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		default:
			return stair(n-1)+stair(n-2);
	}
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
		cout<<stair(n)<<endl;
	}
	return 0;
}
