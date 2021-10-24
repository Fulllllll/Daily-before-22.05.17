#include<stdio.h>
//
//bool GetBottom(SqStack st, ElemType &x)
//{
//	Stack temp;
//	int x;
//	InitStack(temp);
//	while(!StackEmpty(st))
//	{
//		Pop(st,x);
//		Push(temp,x);
//	}
//	Pop(temp,x);
//	whlie(!StackEmpty(temp))
//	{
//		Push(temp,x);
//		Pop(st,x);
//	}
//	return true;
//} 
//
//struct STACK {
//    ElemType data[MaxSize];
//    int top;
//}; //定义一个顺序栈
//
//void ReverseDisp(LinkList head)
//{
//	LNode* p=head->next;
//	while(p)
//	{
//		STACK.data[top++]=p->data;
//	}
//	printf("%d "STACK.data[--top]);
//}
////设该循环队列的结构定义为
//#define	maxSize	100
//typedef	int	ElemType;
//typedef	struct { 				//循环队列的结构定义
//    ElemType	elem[maxSize];	//队列存储数组
//    int	rear, length;			//队列的队尾指针和队列长度。rear是实际的队尾位置。
//} CircQueue;
//Status DeQueue(CircQueue queue,Elemtype x)
//{
//	if(queue.length==0) return 0;
//	x=queue.elem[(rear+1)/maxSize];
//	queue.length--;
//	return 1;	
//} 
//
//Status ElemType EnQueue(CircQueue queue,Elemtype x)
//{
//	if(queue.length>=maxSize) return 0;
//	queue.elem[(++rear)/maxSize]=x;
//	queue.length++;
//	return 1;
//} 
//void recurrence(int n)
//{
//    printf("%d  ",n);
//    if(n>1) recurrence(n-1);
//}
//void Output(int w)
//{
//    int i;
//    if (w != 0) {
//        Output(w - 1);
//        for (i = 1; i <= w; i++)
//            printf("%3d ", w);
//        printf("\n");
//    }
//}
//
//StrLength(char *str)
//{
//	if(*str!='\0')
//	return 1+StrLength(++str);
//	if(*str=='\0')
//	return 0;
//}
//
//
//int main()
//{
//	char ch[10]="asd";
//	printf("%d",StrLength(ch));
//}

int main()
{
    int x;
    double y;
    for(int i=0;i<5;i++)
    {
        scanf("%d",&x);
        y+=x;
    }
    printf("%.1lf",y/5.0);
}

