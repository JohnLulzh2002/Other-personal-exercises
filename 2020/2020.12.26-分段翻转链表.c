#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{
	int data;
	struct NODE* next;
}Node;
const int NodeSize=sizeof(Node);
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	Node*head=(Node*)malloc(NodeSize),*p;
	p=head;
	while(n--){
		scanf("%d",&p->data);
		if(n)
			p=p->next=malloc(NodeSize);
	}
	p->next=NULL;

	Node*newhead,*temp;
	int i;
	p=head;
	for(i=1;i<k;i++)
		p=p->next;
	newhead=p->next;
	p->next=NULL;
	while(newhead){
		p=newhead;
		for(i=1;i<k;i++)
			p=p->next;
		temp=p->next;
		p->next=head;
		head=newhead;
		newhead=temp;
	}
	p=head;
	printf("%d",p->data);
	while(p->next){
		p=p->next;
		printf("->%d",p->data);
	}
	return 0;
}