#include<stdio.h>
void bubble_sort(int arr[],int sz)
{
	
	int i,j;
	for(i=0;i<sz-1;i++)
	{
		for(j=0;j<sz-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int x=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=x;		
			}
		}
	} 
}
int main()
{
	int arr[10]={9,8,7,6,5,3,4,2,1,0};
	int sz=sizeof(arr)/sizeof(arr[0]);
	
	bubble_sort(arr,sz);
	printf("\n"); 
	int i=0;
	for(i=0;i<sz;i++)
	{
		printf("%d  ",arr[i]);	
	}
}
