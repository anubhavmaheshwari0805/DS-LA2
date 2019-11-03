#include<stdio.h>
#include<stdlib.h>
struct node
{
	int bun;
	struct node *next;
};
void insert(struct node **a,int i)
{
	struct node *temp1;
	temp1=(struct node*)malloc(sizeof(struct node));
	temp1->next=NULL;
	temp1->bun=i;
	if(*a==NULL)
    {
        *a=temp1;
        (*a)->next=*a;
    }
    else
    {
    	struct node *temp2;
        temp2=*a;
        do
        {
            temp2=temp2->next;
        }while(temp2->next!=*a);
    	temp2->next=temp1;
        temp1->next=*a;
	}
}
void display(struct node *a)
{
	struct node *temp;
	temp=a;
	if(temp==NULL)
	printf("Carousel is empty.\n");
	do
	{
		printf("%d ",temp->bun);
        if(temp->next==a)
        printf("\nThe lighted container of bun : %d",temp->bun);
		temp=temp->next;
	}while(temp!=a);
	printf("\n");
}
void picked(struct node **a)
{
    if((*a)->next==*a)
    {
        printf("Bun %d is picked.\n",(*a)->bun);
        *a=NULL;
    }
    else
    {
        struct node *temp1,*temp2;
        temp1=*a;
        do
        {
            temp1=temp1->next;
        }while(temp1->next!=*a);
        temp2=temp1;
        do
        {
            temp2=temp2->next;
        }while(temp2->next!=temp1);
        temp2->next=temp1->next;
        printf("Bun %d is picked.\n",temp1->bun);
        free(temp1);
    }
}
void main()
{
    struct node *c=NULL;
    int choice,n;
    do
    {
        printf("Enter Choice :\n1.-Put a Bun.  2.-Pick a bun.  3.-Display Carousel.  4.-Exit.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter Bun number : ");
                    scanf("%d",&n);
                    insert(&c,n);
                    break;
            case 2: if(c==NULL)
                    printf("Carousel is empty.\n");
                    else
                    picked(&c);
                    break;
            case 3: if(c==NULL)
                    printf("Carousel is empty.\n");
                    else
                    {
                        printf("Carousel : ");
                        display(c);
                    }
                    break;
            case 4: printf("Quiting...\n");
                    break;
            default:printf("Invalid choice!!!\n");
                    break;
        }
    }while(choice!=4);
    return;
}