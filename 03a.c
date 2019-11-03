#include<stdio.h>
#include<string.h>
void main()
{
	char str[20];
	printf("Enter the string : ");
	scanf("%s",str);
	int i,j,len=strlen(str);
	for(i=0;i<len;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if(str[j]>str[j+1])
			{
				char temp=str[j];
				str[j]=str[j+1];
				str[j+1]=temp;
			}
		}
	}
	printf("The Tuple : { ");
	for(i=0;i<len;i++)
	printf("%c:%d ",str[i],str[i]);
	printf("}\n");
	return;
}