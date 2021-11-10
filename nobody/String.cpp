#include<stdio.h>
#include<string.h>
void get_next(char string[])
{
	int j=0,k=-1;
	int len=strlen(string);
	int next[len]={0};
	next[0]=-1;
	while(j<len-1)
	{
		if(k==-1||string[j]==string[k])
		{
			j++;
			k++;
			next[j]=k;
		}
		else k=next[k];
	}
	for(int i=0;i<len;i++)
	{
		printf("%d  ",next[i]);
	}
} 

int main()
{
	char string[]="abaabc";
	get_next(string);
}

