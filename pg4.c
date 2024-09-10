#include<stdio.h>
int main()
{
	int aSize,bSize,mSize,i,j;
	int a[10], b[10], Merged[20];
	printf("Please enter the first array size : ");
	scanf("%d",&aSize);
	printf("Enter the first array elements : ");
	for(i=0;i<aSize;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Please enter the second array size : ");
	scanf("%d",&bSize);
	printf("Enter the second array elements : ");
	for(i=0;i<bSize;i++)
	{
		scanf("%d",&b[i]);
	}
	for(i=0;i<aSize;i++)
	{
		Merged[i]=a[i];
	}
	mSize = aSize + bSize;
	for(i=0,j=aSize;j<mSize && i<bSize;i++,j++)
	{
		Merged[j]=b[i];
	}
	printf("\n a[%d] Array elements after merging \n",mSize);
	for(i=0;i<mSize;i++)
	{
		printf("%d \t",Merged[i]);
	}
	return 0;
}
