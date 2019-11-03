#include<stdio.h>
#include<stdlib.h>
struct node
{
	int ele;
	struct node *next;
	struct node *prev;
};
void insert(struct node **a,int i)
{
	struct node *temp1;
	temp1=(struct node*)malloc(sizeof(struct node));
	temp1->next=NULL;
	temp1->prev=NULL;
	temp1->ele=i;
	if(*a==NULL)
    *a=temp1;
    else
    {
		struct node *temp2;
    	temp2=*a;
    	while(temp2->next!=NULL)
    	temp2=temp2->next;
    	temp2->next=temp1;
    	temp1->prev=temp2;
	}
}
void rearrange(struct node *a1,struct node **a2)
{
	struct node *temp;
	temp=a1;
	int i=0;
	while(temp!=NULL)
	{
		if(i%2==0)
		insert(a2,temp->ele);
		temp=temp->next;
		i++;
	}
	i=0;
	temp=a1;
	while(temp!=NULL)
	{
		if(i%2!=0)
		insert(a2,temp->ele);
		temp=temp->next;
		i++;
	}
}
void display(struct node *a)
{
	struct node *temp;
	temp=a;
	if(temp==NULL)
	printf("Empty List.\n");
	while(temp!=NULL)
	{
		printf("%d ",temp->ele);
		temp=temp->next;
	}
	printf("\n");
}
void main()
{
	struct node *a1=NULL,*a2=NULL;
	int i,item;
	printf("Enter 10 elements :\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&item);
		insert(&a1,item);
	}
	rearrange(a1,&a2);
	printf("Rearranged List :\n");
	display(a2);
	return;
}