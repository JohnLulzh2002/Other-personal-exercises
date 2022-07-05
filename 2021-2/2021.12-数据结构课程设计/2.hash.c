#include<stdio.h>
#include<string.h>
char vis[1000003];
int hash(char* s){
	int pow=2003,sum=0,p=1;
	for(;*s;s++){
		sum+=p*((*s)-'a');
		sum%=1000003;
		p*=pow;
		p%=1000003;
	}
	return sum;
}
char find(char* p){
	int h=hash(p);
	switch(vis[h]){
	case 0:	return 0;			break;
	case 1:	vis[h]=2;return 1;	break;
	case 2:	return 2;			break;
	}
	return 0;
}
int main(){
	int n,m;
	scanf("%d",&n);
	char s[55];
	for(int i=0;i<n;i++){
		scanf("%s",s);
		vis[hash(s)]=1;
	}
	char p[55];
	scanf("%d",&m);
	while(m--){
		scanf("%s",p);
		switch(find(p)){
		case 0:	puts("WRONG");	break;
		case 1:	puts("OK");		break;
		case 2:	puts("REPEAT");	break;
		}
	}
	return 0;
}