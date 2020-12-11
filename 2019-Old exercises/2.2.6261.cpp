#include<iostream>
using namespace std;
void hnoi(unsigned short n,char a,char b,char c){
	if(n==1)cout<<a<<"->"<<n<<"->"<<c<<endl;
	else {
		hnoi(n-1,a,c,b);
		cout<<a<<"->"<<n<<"->"<<c<<endl;
		hnoi(n-1,b,a,c);
	}
}
int main(){
	unsigned short n;
	char a,b,c;
	cin>>n>>a>>b>>c;
	hnoi(n,a,c,b);
	return 0;
}
