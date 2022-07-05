#include<stdio.h>
#include<string.h>
char s[10001][55],vis[10001];
int n,m;
char find(char* p){
	for(int i=0;i<n;i++)
		if(!strcmp(s[i],p)){
			if(vis[i])
				return 2;
			vis[i]=1;
			return 1;
		}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);
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