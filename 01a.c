#include<stdio.h>
void main()
{
	int a1[10],a2[10],i,j=0;
	printf("Enter 10 numbers :\n");
	for(i=0;i<10;i++)
	scanf("%d",&a1[i]);
	for(i=0;i<10;i++)
	{
	    if(a1[i]%2==0)
	    {
		    a2[j]=a1[i];
		    j++;
		}
	}
	for(i=0;i<10;i++)
	{
	    if(a1[i]%2!=0)
	    {
		    a2[j]=a1[i];
		    j++;
	    }
	}
	printf("Rearranged Array :\n");
	for(i=0;i<10;i++)
	printf("%d ",a2[i]);
	printf("\n");
	return;
}