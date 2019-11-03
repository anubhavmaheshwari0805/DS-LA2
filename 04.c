#include<stdio.h>
#include<stdlib.h>
struct node
{
	char data;
	struct node *next;
};
void insert(struct node **a,char i)
{
	struct node *temp1,*temp2;
	temp1=(struct node*)malloc(sizeof(struct node));
	temp1->next=NULL;
	temp1->data=i;
	if(*a==NULL)
    *a=temp1;
    else
    {
    	temp2=*a;
    	while(temp2->next!=NULL)
    	temp2=temp2->next;
    	temp2->next=temp1;
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
		printf("%c ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void rearrange(struct node *a1,struct node **a2)
{
	struct node *temp1,*temp2;
	temp1=a1;
    temp2=a1;
	int i;
    for(i=0;i<5;i++)
    temp2=temp2->next;
	while(temp2!=NULL)
	{
		insert(a2,temp1->data);
		temp1=temp1->next;
        insert(a2,temp2->data);
        temp2=temp2->next;
	}
}
void main()
{
    int i,j;
    char student,ch;
    struct node *list1 = NULL;
    struct node *list2 = NULL;
    printf("Enter the names of primary school students :\n");
    for(i=0;i<5;i++)
    {
        scanf("%c",&student);
        scanf("%c",&ch);
        insert(&list1,student);
    }
    printf("Enter the names of high school students :\n");
    for(i=0;i<5;i++)
    {
        scanf("%c",&student);
        scanf("%c",&ch);
        insert(&list1,student);
    }
    printf("First Pattern : ");
    display(list1);
    rearrange(list1,&list2);
    printf("Second Pattern : ");
    display(list2);
    return;
}