#include<iostream>
using namespace std;
int fib(int n){
	if (n ==1 || n==2) return 1;
	else return fib(n-1)+fib(n-2);
}
int main(){
	int m,n,i;
	cin>>m;
	for(i=0;i<m;i++){
		cin>>n;
		cout<<fib(n)<<endl;
	}
	return 0;
}
