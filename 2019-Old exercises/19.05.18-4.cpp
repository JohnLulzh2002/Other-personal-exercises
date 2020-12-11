#include <bits/stdc++.h>
using namespace std;
int main(){
	string s,t;
	cin>>s;
	while(cin>>t){
		s+=' '+t;
		cout<<t<<endl;
	}
	cout<<s;
	return 0;
}
