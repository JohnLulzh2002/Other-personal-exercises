#include <bits/stdc++.h>
using namespace std;
int main(){
	int l;
	cin >> l;
	int a[l];
	bool b[l-1];
	for(int i = 1;i<=l;i++){
		cin >> a[i];
		b[i]=false;
	}
	for(int i = 1;i<l;i++) b[abs(a[i] - a[i+1])] = true;
	bool ans=true;
	for(int i = 1;i<l;i++) if(b[i] == false) ans = false;
	if(ans) cout << "Jolly";
	else 	cout << "Not jolly";
	return 0;
}
