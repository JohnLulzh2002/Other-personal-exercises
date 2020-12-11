#include<stdio.h>
int main(){
	FILE *fi,*fo;
	fi=fopen("in.txt","rb");
	fo=fopen("out.txt","wb");
	//fi=stdin;fo=stdout;
	int n,i=0;
	for(fscanf(fi,"%d",&n);i<n;i++)fprintf(fo,"%d	",i+1);
	fclose(fi);fclose(fo);
	return 0;
}
