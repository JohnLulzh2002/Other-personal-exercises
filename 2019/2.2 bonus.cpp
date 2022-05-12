#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
float x;
float f(unsigned short n){
	if(n==1)return sqrt(1+x);
	else return sqrt(n+f(n-1));
}
int main(){
	unsigned short n;
	cin>>x>>n;
	cout<<fixed<<setprecision(3)<<f(n);
	return 0;
}
