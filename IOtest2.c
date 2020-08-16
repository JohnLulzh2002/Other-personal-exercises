#include<stdio.h>
int main(){
	FILE *fi,*fo;
	fi=fopen("in.txt","rb");
	fo=fopen("out.txt","wb");
	int i,s=0;
	while(fscanf(fi,"%d",&i)==1)s+=i;
	fprintf(fo,"%d",s);
	//fclose(fi);fclose(fo);
	return 0;
}
