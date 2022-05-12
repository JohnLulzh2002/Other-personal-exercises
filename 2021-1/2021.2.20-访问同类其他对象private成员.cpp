#include<iostream>
using namespace std;
class A{
	int n;
	public:
		void setn(int t)
		{n=t;}
		void avg(A&b,A&c)
		{n=(b.n+c.n)/2;}
		void out()
		{cout<<n;}
};
int main(){
	A d,e,f;
	d.setn(1);e.setn(3);
	f.avg(d,e);
	f.out();
	return 0;
}