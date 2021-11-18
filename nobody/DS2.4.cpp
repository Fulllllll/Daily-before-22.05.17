#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 15

void initRandomize(int *arr, int n, int min, int max)
{
    int i = 0;
    srand(time(0));
    for (i = 0; i < n; ++i) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}
int max(int a,int b)
{
	return a>=b? a:b;
}

int min(int a,int b)
{
	return a<b? a:b;
}

int fmax(int* arr,int n)
{
	if(n!=1)	return max(fmax(arr,n-1),arr[n-1]);
	else return arr[0];
}
int fmin(int* arr,int n)
{
	if(n!=1)	return min(fmin(arr,n-1),arr[n-1]);
	else return arr[0];
}

int main()
{
	int arr[MAXSIZE]={0};
	initRandomize(arr,MAXSIZE,0,100);
	for(int i=0;i<MAXSIZE;i++)
	{
		cout<<arr[i]<<" ";
	}

	cout<<endl;
	cout<<"MAX:"<<fmax(arr,MAXSIZE)<<endl;
	cout<<"MIN:"<<fmin(arr,MAXSIZE)<<endl;
	return 0;
}
