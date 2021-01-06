#include<stdio.h>
int main(){
	system("title 身份证号第18位生成器By JohnLu");
	char a[19];
	int b[18],i;
	printf("身份证号第18位生成器\n");
	printf("           By JohnLu\n");
InputError:
	printf("输入前17位：");
	gets(a);
	for(i=0;i<17;i++)b[i]=(int)a[i];
	b[17]=(b[0]-48)*7+(b[1]-48)*9+(b[2]-48)*10+(b[3]-48)*5+(b[4]-48)*8
+(b[5]-48)*4+(b[6]-48)*2+(b[7]-48)*1+(b[8]-48)*6+(b[9]-48)*3+(b[10]-48)*7
+(b[11]-48)*9+(b[12]-48)*10+(b[13]-48)*5+(b[14]-48)*8+(b[15]-48)*4+(b[16]-48)*2;
	i=b[17]%11;
	if(i==0)i=1;
	else if(i==1)i=0;
	else if(i==2)i=10;
	else if(i==3)i=9;
	else if(i==4)i=8;
	else if(i==5)i=7;
	else if(i==6)i=6;
	else if(i==7)i=5;
	else if(i==8)i=4;
	else if(i==9)i=3;
	else if(i==10)i=2;
	else {printf("少了几位\n");goto InputError;}
	printf("完整的身份证号是\n");
	printf(a);
	if(i==10)printf("X");
	else printf("%d",i);
	printf("\n回车键退出\n");
	scanf("%c",&a[18]);
	return 0;
}
