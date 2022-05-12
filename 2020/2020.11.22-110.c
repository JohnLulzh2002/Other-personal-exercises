#include<stdio.h>
int main(){
	int n,t,i;
	int a[9],ans;
	for(n=1;n<6561;n++){
		t=n;
		for(i=0;i<8;i++){
			a[i]=t%3;
			t/=3;
		}//3进制穷举，0:pass 1:+ 2:-
		ans=0;t=1;
		for(i=0;i<8;i++)
			switch(a[i]){
				case 0:	//拼接到t上
					t*=10;
					t+=t>0?i+2:-i-2;
					break;
				case 1:	//t为当前数
					ans+=t;
					t=i+2;
					break;
				case 2:	//t为当前数相反数
					ans+=t;
					t=-i-2;
			}
		ans+=t;
		if(ans==110){
			for(i=0;i<8;i++){
				printf("%d",i+1);
				switch(a[i]){
					case 1:
						printf("+");
						break;
					case 2:
						printf("-");
						break;
				}
			}
			printf("9\n");
		}
	}
}