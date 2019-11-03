#include<stdio.h>
#include<stdlib.h>
struct node
{
	char ch;
	int ascii;
	struct node *next;
};
void insert(struct node **a,char i)
{
	struct node *temp1;
	temp1=(struct node*)malloc(sizeof(struct node));
	temp1->next=NULL;
	temp1->ch=i;
	temp1->ascii=i;
	if(*a==NULL)
    *a=temp1;
    else
    {
		struct node *temp2;
    	temp2=*a;
    	while(temp2->next!=NULL)
    	temp2=temp2->next;
    	temp2->next=temp1;
	}
}
void priority(struct node *a,int l)
{
	char t1;
	int t2,i;
	for(i=0;i<l;i++)
	{
		if(a->ascii > a->next->ascii)
		{
		    t1=a->ch;
			a->ch=a->next->ch;
			a->next->ch=t1;
			t2=a->ascii;
			a->ascii=a->next->ascii;
			a->next->ascii=t2;
		}
		a=a->next;
	}
}
void display(struct node *a)
{
	printf("The Tuple : { ");
	while(a->next!=NULL)
	{
		printf("%c:%d ",a->ch,a->ascii);
		a=a->next;
	}
	printf("}\n");
}
void main()
{
	struct node *s=NULL;
	char ch;
	int len=0;
	printf("Enter the string : ");
	ch=getchar();
	while(ch!='\n')
	{
		insert(&s,ch);
		ch=getchar();
		len++;
	}
	insert(&s,'\0');
	int i;
	for(i=0;i<len;i++)
	priority(s,len-i-1);
	display(s);
	return;
}